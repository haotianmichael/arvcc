
// Generated from src/parser/ARParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ARParserListener.h"


/**
 * This class provides an empty implementation of ARParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ARParserBaseListener : public ARParserListener {
public:

  virtual void enterAryop(ARParser::AryopContext * /*ctx*/) override { }
  virtual void exitAryop(ARParser::AryopContext * /*ctx*/) override { }

  virtual void enterExpression(ARParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ARParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterBlockExpr(ARParser::BlockExprContext * /*ctx*/) override { }
  virtual void exitBlockExpr(ARParser::BlockExprContext * /*ctx*/) override { }

  virtual void enterParaList(ARParser::ParaListContext * /*ctx*/) override { }
  virtual void exitParaList(ARParser::ParaListContext * /*ctx*/) override { }

  virtual void enterFunType(ARParser::FunTypeContext * /*ctx*/) override { }
  virtual void exitFunType(ARParser::FunTypeContext * /*ctx*/) override { }

  virtual void enterFunStmt(ARParser::FunStmtContext * /*ctx*/) override { }
  virtual void exitFunStmt(ARParser::FunStmtContext * /*ctx*/) override { }

  virtual void enterStatement(ARParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ARParser::StatementContext * /*ctx*/) override { }

  virtual void enterStatements(ARParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(ARParser::StatementsContext * /*ctx*/) override { }

  virtual void enterModule(ARParser::ModuleContext * /*ctx*/) override { }
  virtual void exitModule(ARParser::ModuleContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

