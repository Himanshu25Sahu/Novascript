
# MyCustomLang Interpreter Implementation Roadmap

## Phase 1: Lexical Analysis (Tokenizer)

### 1.1 Token Specification

```python
# Special Keywords
WHEN = 'when'
THEN = 'then'
OTHERWISE = 'otherwise'
END = 'end'

# Operators
COMPARISON_OPS = ['is', 'is not', 'greater than', 'less than', 'equals']

# Token Types
[
    ('WHEN', r'when'),
    ('THEN', r'then'),
    ('OTHERWISE', r'otherwise'),
    ('COMPARISON_OP', r'is not|is|greater than|less than|equals'),
    ('END', r'end')
]
```

### 1.2 Tokenization Rules

Handle nested conditionals:

```python
when x > 0 then
    when y < 0 then  # Nested when
        say "Special case"
    end
end
```

Multi-word operator handling:

```python
"x is greater than 10" → [IDENT(x), COMPARISON_OP(is greater than), NUMBER(10)]
```

### 1.3 Edge Cases

Distinguish between:

```python
when x is 10 then...   # Comparison
when is_active then... # Boolean check
```

## Phase 2: Parsing (AST Generation)

### 2.1 AST Node Structure

```typescript
interface Conditional {
  type: 'Conditional';
  test: {
    left: Expression;
    op: string;
    right: Expression;
  };
  consequent: Statement[];
  alternate?: Statement[];
}
```

### 2.2 Grammar Rules

```
conditional_stmt → WHEN expression THEN block (OTHERWISE block)? END
expression → ID COMPARISON_OP literal
           | ID COMPARISON_OP ID
           | boolean_expr
```

### 2.3 Parser Implementation

```python
def parse_when_statement():
    consume('WHEN')
    test = parse_comparison()
    consume('THEN')
    consequent = parse_block()

    alternate = []
    if current_token == 'OTHERWISE':
        consume('OTHERWISE')
        alternate = parse_block()

    consume('END')
    return Conditional(test, consequent, alternate)
```

## Phase 3: Semantic Analysis

### 3.1 Type Checking

```python
when "hello" is greater than 10 then... # Error: String vs Number
```

### 3.2 Control Flow Validation

```python
when true then
    say "Always runs"
otherwise
    say "Dead code"  # Should warn
end
```

### 3.3 Symbol Table Management

```python
{
  'scope': 'conditional',
  'variables': {
    'x': {'type': 'Number', 'defined_at': line 12}
  }
}
```

## Phase 4: Intermediate Representation (IR)

### 4.1 Lowering to IR

```python
# Original
when x is greater than 10 then
    say "Large"
end

# IR (Pseudocode)
LABEL cond_start
COMPARE x > 10
JUMP_IF_FALSE cond_end
PRINT "Large"
LABEL cond_end
```

### 4.2 Optimization Passes

**Constant Folding**:

```python
when 5 is greater than 10 then... → Eliminate dead code
```

**Branch Merging**:

```python
when a then X otherwise when b then X → when (a or b) then X
```

## Phase 5: Code Generation

### 5.1 JavaScript Target

```javascript
if (x > 10) {
    console.log("Large");
}
```

### 5.2 Bytecode (Stack-Based VM)

```
0: LOAD x
1: CONST 10
2: GT
3: JUMP_IF_FALSE 7
4: CONST "Large"
5: PRINT
6: JUMP 7
7: NOP
```

### 5.3 Native Code (LLVM)

```llvm
%cmp = icmp sgt i32 %x, 10
br i1 %cmp, label %then, label %end
then:
    call void @print(i8* "Large")
    br label %end
end:
    ...
```

## Phase 6: Runtime Implementation

### 6.1 Comparison Operators

```c
int compare_values(Value a, Value b, string op) {
    if (op == "is") return a == b;
    if (op == "greater than") return a > b;
    // ... other operators
}
```

### 6.2 Error Handling

```python
when x is greater than then... # Error: Missing right operand
```

### 6.3 Debugging Support

```python
Bytecode  | Source Line
------------------------
0x01      | when x > 10
0x02      | then say "Hi"
```

## Phase 7: Testing & Validation

### 7.1 Test Cases

```python
# Equality
when name is "Alice" then ... end

# Numeric
when temp is greater than 30 then ... end

# Nested
when x then
    when y then ... end
end

# Type Errors
when "text" is less than 10 then ... end # Should fail
```

### 7.2 Performance Benchmarks

```bash
# Measure branch prediction
$ time mylang script.mcl > /dev/null
```

## Phase 8: Optimization

### 8.1 Branch Prediction

```python
# Cold path
when rare_condition then ... end

# Hot path
when common_case then ... end
```

### 8.2 Lazy Evaluation

```python
when config.debug and expensive_check() then... # Short-circuit
```
