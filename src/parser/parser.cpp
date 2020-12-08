#include "parser.h"
#include <cmath>
#include "antlr4-runtime.h"
#include "parser/gen/ARLexer.h"
#include "parser/gen/ARParser.h"
#include "parser/gen/ARParserVisitor.h"
#include <typeinfo>

namespace  AR{


            virtual antlrcpp::Any visitAryop(ARParser::AryopContext *context){
                
               return nullptr; 
            }

            virtual antlrcpp::Any visitExpression(ARParser::ExpressionContext *context){
                
               return nullptr; 
            }

            virtual antlrcpp::Any visitBlockExpr(ARParser::BlockExprContext *context){
            
               return nullptr; 
            }

            virtual antlrcpp::Any visitParaList(ARParser::ParaListContext *context){
            
               return nullptr; 
            }

            virtual antlrcpp::Any visitFunType(ARParser::FunTypeContext *context){
                
               return nullptr; 
            }

            virtual antlrcpp::Any visitFunStmt(ARParser::FunStmtContext *context){
                
               return nullptr; 
            }

            virtual antlrcpp::Any visitStatement(ARParser::StatementContext *context){
                
               return nullptr; 
            }

            virtual antlrcpp::Any visitStatements(ARParser::StatementsContext *context){
                
               return nullptr; 
            }

            virtual antlrcpp::Any visitModule(ARParser::ModuleContext *context){
                
               return nullptr; 
            }


};
