#!/bin/sh

# configuring antrl4
ANTLR_HOME="$PWD/third-party/ANTLR"
ANTLR=`ls $ANTLR_HOME`
ANTLR_JAR="$ANTLR_HOME/$ANTLR"
alias antlr4="java -jar $ANTLR_JAR"

# antlr4 gen
antlr4 -Werror -Dlanguage=Cpp -listener -visitor -lib src/parser/ src/parser/ARLexer.g4 src/parser/ARParser.g4 -Xexact-output-dir  -o src/parser/gen

if [ $? != 0 ]
then
    echo "======ANTLR4 Error! Firstly Please Make Sure It's In ./third-party/ANTLR/========="
fi
