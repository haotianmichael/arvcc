lexer grammar ARLexer;



INT_SYMBOL : 'int';
VOID_SYMBOL : 'void';
CHAR_SYMBOL : 'char';
ADD_SYMBOL : '+';
SUB_SYMBOL : '-';
MUL_SYMBOL : '*';
DIV_SYMBOL : '/';
SEMICOLON_SYMBOL : ';';
COMMA_SYMBOL : ',';



fragment WITHOUT_DIGIT: [a-zA-Z];
fragment WITH_DIGIT: [0-9a-zA-Z];


LEFT_PAR: '(';
RIGHT_PAR: ')';
LEFT_BRA: '{';
RIGHT_BRA: '}';


IDENTIFIER : WITHOUT_DIGIT WITH_DIGIT;


SINGLE_COMMENT:
    '//' ~[\r\n]* '\r'?  '\n' -> skip
;




