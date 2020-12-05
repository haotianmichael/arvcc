
// Generated from src/parser/ARParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ARParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ARParser.
 */
class  ARParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAryop(ARParser::AryopContext *ctx) = 0;
  virtual void exitAryop(ARParser::AryopContext *ctx) = 0;

  virtual void enterExpression(ARParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(ARParser::ExpressionContext *ctx) = 0;

  virtual void enterBlockExpr(ARParser::BlockExprContext *ctx) = 0;
  virtual void exitBlockExpr(ARParser::BlockExprContext *ctx) = 0;

  virtual void enterParaList(ARParser::ParaListContext *ctx) = 0;
  virtual void exitParaList(ARParser::ParaListContext *ctx) = 0;

  virtual void enterFunType(ARParser::FunTypeContext *ctx) = 0;
  virtual void exitFunType(ARParser::FunTypeContext *ctx) = 0;

  virtual void enterFunStmt(ARParser::FunStmtContext *ctx) = 0;
  virtual void exitFunStmt(ARParser::FunStmtContext *ctx) = 0;

  virtual void enterStatement(ARParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ARParser::StatementContext *ctx) = 0;

  virtual void enterStatements(ARParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(ARParser::StatementsContext *ctx) = 0;

  virtual void enterModule(ARParser::ModuleContext *ctx) = 0;
  virtual void exitModule(ARParser::ModuleContext *ctx) = 0;


};

