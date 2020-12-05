parser grammar ARParser;


options {
    tokenVocab = ARLexer;
}

aryop : 
    ADD_SYMBOL
    | SUB_SYMBOL
    | MUL_SYMBOL
    | DIV_SYMBOL
;

expression: 
    expression op=(MUL_SYMBOL | DIV_SYMBOL) expression 
    | expression op=(ADD_SYMBOL | SUB_SYMBOL) expression 
    | IDENTIFIER
;


blockExpr : 
    LEFT_BRA RIGHT_BRA
    | LEFT_BRA statement RIGHT_BRA
;

paraList : 
    (expression (COMMA_SYMBOL expression)*)?
;

funType : 
    INT_SYMBOL
    | VOID_SYMBOL
    | CHAR_SYMBOL 
;

funStmt : 
    funType IDENTIFIER LEFT_PAR paraList RIGHT_PAR blockExpr
;


statement : 
    funStmt    
;


statements :
    (statement SEMICOLON_SYMBOL)*
;


module :
    statements EOF
;
