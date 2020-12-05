
// Generated from src/parser/ARLexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  ARLexer : public antlr4::Lexer {
public:
  enum {
    INT_SYMBOL = 1, VOID_SYMBOL = 2, CHAR_SYMBOL = 3, ADD_SYMBOL = 4, SUB_SYMBOL = 5, 
    MUL_SYMBOL = 6, DIV_SYMBOL = 7, SEMICOLON_SYMBOL = 8, COMMA_SYMBOL = 9, 
    LEFT_PAR = 10, RIGHT_PAR = 11, LEFT_BRA = 12, RIGHT_BRA = 13, IDENTIFIER = 14, 
    SINGLE_COMMENT = 15
  };

  ARLexer(antlr4::CharStream *input);
  ~ARLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

