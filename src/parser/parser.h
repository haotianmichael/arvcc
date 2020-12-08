#include "antlr4-runtime.h"
#include "parser/gen/ARParserVisitor.h"


namespace AR{

    class Parser : public ARParserVisitor{
        public : 
        private:
            virtual antlrcpp::Any visitAryop(ARParser::AryopContext *context);

            virtual antlrcpp::Any visitExpression(ARParser::ExpressionContext *context);

            virtual antlrcpp::Any visitBlockExpr(ARParser::BlockExprContext *context);

            virtual antlrcpp::Any visitParaList(ARParser::ParaListContext *context);

            virtual antlrcpp::Any visitFunType(ARParser::FunTypeContext *context);

            virtual antlrcpp::Any visitFunStmt(ARParser::FunStmtContext *context);

            virtual antlrcpp::Any visitStatement(ARParser::StatementContext *context);

            virtual antlrcpp::Any visitStatements(ARParser::StatementsContext *context);

            virtual antlrcpp::Any visitModule(ARParser::ModuleContext *context);



    };

};
