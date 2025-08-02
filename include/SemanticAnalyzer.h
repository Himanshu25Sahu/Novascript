#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "SymbolTable.h"
#include "Type.h"
#include <stdexcept>
#include <string>
#include "Token.h"

namespace MyCustomLang {
class Program;
class Stmt;
class Expr;
}

#include "AST.h"

namespace MyCustomLang {

class SemanticError : public std::runtime_error {
public:
    Token token;
    SemanticError(const Token& token, const std::string& message)
        : std::runtime_error(message), token(token) {}
};

class SemanticAnalyzer {
public:
    SemanticAnalyzer(SymbolTable& symTable) : symbolTable(symTable) {}
    void analyze(Program& program);
    const SymbolTable& getSymbolTable() const { return symbolTable; } // Added for external access

private:
    SymbolTable& symbolTable;

    void analyzeStmt(Stmt* stmt);
    void analyzeExpr(Expr* expr);
    Type inferExprType(Expr* expr);
    void checkTypeCompatibility(Type expected, Type actual, const Token& token);
    void updateFunctionReturnType(const std::string& funcName, Type returnType);
};

} // namespace MyCustomLang

#endif // SEMANTIC_ANALYZER_H