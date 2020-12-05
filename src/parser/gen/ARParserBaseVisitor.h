
// Generated from src/parser/ARParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ARParserVisitor.h"


/**
 * This class provides an empty implementation of ARParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ARParserBaseVisitor : public ARParserVisitor {
public:

  virtual antlrcpp::Any visitAryop(ARParser::AryopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(ARParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockExpr(ARParser::BlockExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParaList(ARParser::ParaListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunType(ARParser::FunTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunStmt(ARParser::FunStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(ARParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(ARParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule(ARParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }


};

