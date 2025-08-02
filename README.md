# Nova Script Documentation

\---
# Nova Script Documentation

## 📘 Table of Contents

1. [Introduction](#1-introduction)
2. [Language Features](#2-language-features)
    - [Print Statements (`say`)](#21-print-statements-say)
    - [Variable Declarations (`let`)](#22-variable-declarations-let)
    - [Constants (`const`)](#23-constants-const)
    - [Functions (`define`)](#24-functions-define)
    - [Conditionals (`if`, `else if`, `else`)](#25-conditionals-if-else-if-else)
    - [Loops (`repeat`, `while`)](#26-loops-repeat-while)
    - [Lists and Iteration](#27-lists-and-iteration)
    - [Comments](#28-comments)
    - [Modules (Importing)](#29-modules-importing)
    - [Error Handling (`try`, `catch`)](#210-error-handling-try-catch)
3. [Type System](#3-type-system)
4. [Operators](#4-operators)
5. [Built-in Functions](#5-built-in-functions)
6. [Examples](#6-examples)
7. [File Execution](#8-file-execution)


---

## 1. Introduction

Nova Script is a simple, readable, English-like programming language designed for beginners and rapid prototyping. It emphasizes clarity and natural language syntax.
Checkout this LinkedIN post for more info : https://www.linkedin.com/feed/update/urn:li:activity:7339534452844281857/
---

## 2. Language Features

### 2.1 Print Statements (`say`)

```ns
say "Hello, world!"
say x
```

* **Syntax**: `say <expression>`
* Prints the value of the expression to the console.

### 2.2 Variable Declarations (`let`)

```ns
let count be 42 as integer
let name be "Alice" as string
let value as integer
```

* **Syntax**: `let <identifier> [be= <expression>] [as integer | long | string]`
* Declares a variable, optionally with a value and type.

### 2.3 Constants (`const`)

```ns
const pi be 3.14 as float
```

* **Syntax**: `const <identifier> be <expression> [as <type>]`
* Declares an immutable value.

### 2.4 Functions (`define`)

```ns
define greet with name as string:
  say "Hello, " + name

greet with "Alice"
```

* **Syntax**: `define <function-name> [with <param> as <type>, ...]:`
* Defines a function.

### 2.5 Conditionals (`if`, `else if`, `else`)

```ns
if x > 10:
  say "Greater than 10"
else if x == 10:
  say "Equal to 10"
else:
  say "Less than 10"
```

* **Syntax**:

  * `if <condition>:`
  * `else if <condition>:`
  * `else:`

### 2.6 Loops (`repeat`, `while`)

```ns
repeat 5 times:
  say "Hello"

let i be 0
while i < 5:
  say i
  let i be i + 1
```

* **Syntax**:

  * `repeat <number> times:`
  * `while <condition>:`

### 2.7 Lists and Iteration

```ns
let items be [1, 2, 3, 4]
for each item in items:
  say item
```

* **Syntax**: `for each <item> in <list>:`
* Iterates through a list.

### 2.8 Comments

```ns
# This is a single-line comment
```

* Lines starting with `#` are ignored.

### 2.9 Modules (Importing)

```ns
import math
say math.pi
```

* **Syntax**: `import <module>`
* Imports functions/constants from a module.

### 2.10 Error Handling (`try`, `catch`)

```ns
try:
  let x be 10 / 0
catch error:
  say "Error: " + error
```

* **Syntax**:

  * `try:`
  * `catch <error-var>:`

---

## 3. Type System

* **Types supported**:

  * `integer`, `long`, `float`, `string`, `boolean`, `list`

---

## 4. Operators

* `+`, `-`, `*`, `/`, `%`, `==`, `!=`, `>`, `<`, `>=`, `<=`, `and`, `or`, `not`

---

## 5. Built-in Functions

* `length`, `type`, `input`, `random`, `print`, `str`, `int`, `float`, `bool`

---

## 6. Examples

### Factorial

```ns
define function factorial(n)
  let result be 1
  let i be 1

  repeat while i<=n
    set result to result*i
    set i to i+1
  end

  return result
end

let answer be call factorial(5)
say answer
```

### Fibonacci

```ns
define function fibonacci(n)
  let a be 0
  let b be 1
  let c be 0

  repeat while c<n
    say a
    let temp be b
    set b to a+b
    set a to temp
    set c to c+1
  end
end

call fibonacci(10)
```
### Exception Handling

```ns
try
  let number be 0
  let result be 100/number
  say result
catch error
  say "an error occured:"
  say error
end


```

---

## 7. File Execution

Save code in a `.ns` file and run:

```terminal
g++ -I../include -o main main.cpp lexer.cpp Parser.cpp SymbolTable.cpp SemanticAnalyzer.cpp -std=c++17 -mconsole
```
After successful compilation - run:
```
./main
```
Bam! You just experienced Novascript!
---

