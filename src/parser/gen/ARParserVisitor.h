
// Generated from src/parser/ARParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ARParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ARParser.
 */
class  ARParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ARParser.
   */
    virtual antlrcpp::Any visitAryop(ARParser::AryopContext *context) = 0;

    virtual antlrcpp::Any visitExpression(ARParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBlockExpr(ARParser::BlockExprContext *context) = 0;

    virtual antlrcpp::Any visitParaList(ARParser::ParaListContext *context) = 0;

    virtual antlrcpp::Any visitFunType(ARParser::FunTypeContext *context) = 0;

    virtual antlrcpp::Any visitFunStmt(ARParser::FunStmtContext *context) = 0;

    virtual antlrcpp::Any visitStatement(ARParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitStatements(ARParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitModule(ARParser::ModuleContext *context) = 0;


};

