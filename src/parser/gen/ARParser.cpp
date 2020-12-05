
// Generated from src/parser/ARParser.g4 by ANTLR 4.8


#include "ARParserListener.h"
#include "ARParserVisitor.h"

#include "ARParser.h"


using namespace antlrcpp;
using namespace antlr4;

ARParser::ARParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ARParser::~ARParser() {
  delete _interpreter;
}

std::string ARParser::getGrammarFileName() const {
  return "ARParser.g4";
}

const std::vector<std::string>& ARParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ARParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AryopContext ------------------------------------------------------------------

ARParser::AryopContext::AryopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ARParser::AryopContext::ADD_SYMBOL() {
  return getToken(ARParser::ADD_SYMBOL, 0);
}

tree::TerminalNode* ARParser::AryopContext::SUB_SYMBOL() {
  return getToken(ARParser::SUB_SYMBOL, 0);
}

tree::TerminalNode* ARParser::AryopContext::MUL_SYMBOL() {
  return getToken(ARParser::MUL_SYMBOL, 0);
}

tree::TerminalNode* ARParser::AryopContext::DIV_SYMBOL() {
  return getToken(ARParser::DIV_SYMBOL, 0);
}


size_t ARParser::AryopContext::getRuleIndex() const {
  return ARParser::RuleAryop;
}

void ARParser::AryopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAryop(this);
}

void ARParser::AryopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAryop(this);
}


antlrcpp::Any ARParser::AryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitAryop(this);
  else
    return visitor->visitChildren(this);
}

ARParser::AryopContext* ARParser::aryop() {
  AryopContext *_localctx = _tracker.createInstance<AryopContext>(_ctx, getState());
  enterRule(_localctx, 0, ARParser::RuleAryop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ARParser::ADD_SYMBOL)
      | (1ULL << ARParser::SUB_SYMBOL)
      | (1ULL << ARParser::MUL_SYMBOL)
      | (1ULL << ARParser::DIV_SYMBOL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ARParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ARParser::ExpressionContext::IDENTIFIER() {
  return getToken(ARParser::IDENTIFIER, 0);
}

std::vector<ARParser::ExpressionContext *> ARParser::ExpressionContext::expression() {
  return getRuleContexts<ARParser::ExpressionContext>();
}

ARParser::ExpressionContext* ARParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<ARParser::ExpressionContext>(i);
}

tree::TerminalNode* ARParser::ExpressionContext::MUL_SYMBOL() {
  return getToken(ARParser::MUL_SYMBOL, 0);
}

tree::TerminalNode* ARParser::ExpressionContext::DIV_SYMBOL() {
  return getToken(ARParser::DIV_SYMBOL, 0);
}

tree::TerminalNode* ARParser::ExpressionContext::ADD_SYMBOL() {
  return getToken(ARParser::ADD_SYMBOL, 0);
}

tree::TerminalNode* ARParser::ExpressionContext::SUB_SYMBOL() {
  return getToken(ARParser::SUB_SYMBOL, 0);
}


size_t ARParser::ExpressionContext::getRuleIndex() const {
  return ARParser::RuleExpression;
}

void ARParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void ARParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any ARParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


ARParser::ExpressionContext* ARParser::expression() {
   return expression(0);
}

ARParser::ExpressionContext* ARParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ARParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  ARParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ARParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(21);
    match(ARParser::IDENTIFIER);
    _ctx->stop = _input->LT(-1);
    setState(31);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(29);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(23);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(24);
          dynamic_cast<ExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ARParser::MUL_SYMBOL

          || _la == ARParser::DIV_SYMBOL)) {
            dynamic_cast<ExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(25);
          expression(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(26);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(27);
          dynamic_cast<ExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ARParser::ADD_SYMBOL

          || _la == ARParser::SUB_SYMBOL)) {
            dynamic_cast<ExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(28);
          expression(3);
          break;
        }

        } 
      }
      setState(33);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockExprContext ------------------------------------------------------------------

ARParser::BlockExprContext::BlockExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ARParser::BlockExprContext::LEFT_BRA() {
  return getToken(ARParser::LEFT_BRA, 0);
}

tree::TerminalNode* ARParser::BlockExprContext::RIGHT_BRA() {
  return getToken(ARParser::RIGHT_BRA, 0);
}

ARParser::StatementContext* ARParser::BlockExprContext::statement() {
  return getRuleContext<ARParser::StatementContext>(0);
}


size_t ARParser::BlockExprContext::getRuleIndex() const {
  return ARParser::RuleBlockExpr;
}

void ARParser::BlockExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockExpr(this);
}

void ARParser::BlockExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockExpr(this);
}


antlrcpp::Any ARParser::BlockExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitBlockExpr(this);
  else
    return visitor->visitChildren(this);
}

ARParser::BlockExprContext* ARParser::blockExpr() {
  BlockExprContext *_localctx = _tracker.createInstance<BlockExprContext>(_ctx, getState());
  enterRule(_localctx, 4, ARParser::RuleBlockExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(34);
      match(ARParser::LEFT_BRA);
      setState(35);
      match(ARParser::RIGHT_BRA);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(36);
      match(ARParser::LEFT_BRA);
      setState(37);
      statement();
      setState(38);
      match(ARParser::RIGHT_BRA);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParaListContext ------------------------------------------------------------------

ARParser::ParaListContext::ParaListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ARParser::ExpressionContext *> ARParser::ParaListContext::expression() {
  return getRuleContexts<ARParser::ExpressionContext>();
}

ARParser::ExpressionContext* ARParser::ParaListContext::expression(size_t i) {
  return getRuleContext<ARParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> ARParser::ParaListContext::COMMA_SYMBOL() {
  return getTokens(ARParser::COMMA_SYMBOL);
}

tree::TerminalNode* ARParser::ParaListContext::COMMA_SYMBOL(size_t i) {
  return getToken(ARParser::COMMA_SYMBOL, i);
}


size_t ARParser::ParaListContext::getRuleIndex() const {
  return ARParser::RuleParaList;
}

void ARParser::ParaListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParaList(this);
}

void ARParser::ParaListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParaList(this);
}


antlrcpp::Any ARParser::ParaListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitParaList(this);
  else
    return visitor->visitChildren(this);
}

ARParser::ParaListContext* ARParser::paraList() {
  ParaListContext *_localctx = _tracker.createInstance<ParaListContext>(_ctx, getState());
  enterRule(_localctx, 6, ARParser::RuleParaList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ARParser::IDENTIFIER) {
      setState(42);
      expression(0);
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ARParser::COMMA_SYMBOL) {
        setState(43);
        match(ARParser::COMMA_SYMBOL);
        setState(44);
        expression(0);
        setState(49);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunTypeContext ------------------------------------------------------------------

ARParser::FunTypeContext::FunTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ARParser::FunTypeContext::INT_SYMBOL() {
  return getToken(ARParser::INT_SYMBOL, 0);
}

tree::TerminalNode* ARParser::FunTypeContext::VOID_SYMBOL() {
  return getToken(ARParser::VOID_SYMBOL, 0);
}

tree::TerminalNode* ARParser::FunTypeContext::CHAR_SYMBOL() {
  return getToken(ARParser::CHAR_SYMBOL, 0);
}


size_t ARParser::FunTypeContext::getRuleIndex() const {
  return ARParser::RuleFunType;
}

void ARParser::FunTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunType(this);
}

void ARParser::FunTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunType(this);
}


antlrcpp::Any ARParser::FunTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitFunType(this);
  else
    return visitor->visitChildren(this);
}

ARParser::FunTypeContext* ARParser::funType() {
  FunTypeContext *_localctx = _tracker.createInstance<FunTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, ARParser::RuleFunType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ARParser::INT_SYMBOL)
      | (1ULL << ARParser::VOID_SYMBOL)
      | (1ULL << ARParser::CHAR_SYMBOL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunStmtContext ------------------------------------------------------------------

ARParser::FunStmtContext::FunStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ARParser::FunTypeContext* ARParser::FunStmtContext::funType() {
  return getRuleContext<ARParser::FunTypeContext>(0);
}

tree::TerminalNode* ARParser::FunStmtContext::IDENTIFIER() {
  return getToken(ARParser::IDENTIFIER, 0);
}

tree::TerminalNode* ARParser::FunStmtContext::LEFT_PAR() {
  return getToken(ARParser::LEFT_PAR, 0);
}

ARParser::ParaListContext* ARParser::FunStmtContext::paraList() {
  return getRuleContext<ARParser::ParaListContext>(0);
}

tree::TerminalNode* ARParser::FunStmtContext::RIGHT_PAR() {
  return getToken(ARParser::RIGHT_PAR, 0);
}

ARParser::BlockExprContext* ARParser::FunStmtContext::blockExpr() {
  return getRuleContext<ARParser::BlockExprContext>(0);
}


size_t ARParser::FunStmtContext::getRuleIndex() const {
  return ARParser::RuleFunStmt;
}

void ARParser::FunStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunStmt(this);
}

void ARParser::FunStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunStmt(this);
}


antlrcpp::Any ARParser::FunStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitFunStmt(this);
  else
    return visitor->visitChildren(this);
}

ARParser::FunStmtContext* ARParser::funStmt() {
  FunStmtContext *_localctx = _tracker.createInstance<FunStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ARParser::RuleFunStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    funType();
    setState(55);
    match(ARParser::IDENTIFIER);
    setState(56);
    match(ARParser::LEFT_PAR);
    setState(57);
    paraList();
    setState(58);
    match(ARParser::RIGHT_PAR);
    setState(59);
    blockExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ARParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ARParser::FunStmtContext* ARParser::StatementContext::funStmt() {
  return getRuleContext<ARParser::FunStmtContext>(0);
}


size_t ARParser::StatementContext::getRuleIndex() const {
  return ARParser::RuleStatement;
}

void ARParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void ARParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any ARParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ARParser::StatementContext* ARParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, ARParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    funStmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

ARParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ARParser::StatementContext *> ARParser::StatementsContext::statement() {
  return getRuleContexts<ARParser::StatementContext>();
}

ARParser::StatementContext* ARParser::StatementsContext::statement(size_t i) {
  return getRuleContext<ARParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> ARParser::StatementsContext::SEMICOLON_SYMBOL() {
  return getTokens(ARParser::SEMICOLON_SYMBOL);
}

tree::TerminalNode* ARParser::StatementsContext::SEMICOLON_SYMBOL(size_t i) {
  return getToken(ARParser::SEMICOLON_SYMBOL, i);
}


size_t ARParser::StatementsContext::getRuleIndex() const {
  return ARParser::RuleStatements;
}

void ARParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void ARParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


antlrcpp::Any ARParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

ARParser::StatementsContext* ARParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 14, ARParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ARParser::INT_SYMBOL)
      | (1ULL << ARParser::VOID_SYMBOL)
      | (1ULL << ARParser::CHAR_SYMBOL))) != 0)) {
      setState(63);
      statement();
      setState(64);
      match(ARParser::SEMICOLON_SYMBOL);
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleContext ------------------------------------------------------------------

ARParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ARParser::StatementsContext* ARParser::ModuleContext::statements() {
  return getRuleContext<ARParser::StatementsContext>(0);
}

tree::TerminalNode* ARParser::ModuleContext::EOF() {
  return getToken(ARParser::EOF, 0);
}


size_t ARParser::ModuleContext::getRuleIndex() const {
  return ARParser::RuleModule;
}

void ARParser::ModuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule(this);
}

void ARParser::ModuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ARParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule(this);
}


antlrcpp::Any ARParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ARParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

ARParser::ModuleContext* ARParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 16, ARParser::RuleModule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    statements();
    setState(72);
    match(ARParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ARParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ARParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ARParser::_decisionToDFA;
atn::PredictionContextCache ARParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ARParser::_atn;
std::vector<uint16_t> ARParser::_serializedATN;

std::vector<std::string> ARParser::_ruleNames = {
  "aryop", "expression", "blockExpr", "paraList", "funType", "funStmt", 
  "statement", "statements", "module"
};

std::vector<std::string> ARParser::_literalNames = {
  "", "'int'", "'void'", "'char'", "'+'", "'-'", "'*'", "'/'", "';'", "','", 
  "'('", "')'", "'{'", "'}'"
};

std::vector<std::string> ARParser::_symbolicNames = {
  "", "INT_SYMBOL", "VOID_SYMBOL", "CHAR_SYMBOL", "ADD_SYMBOL", "SUB_SYMBOL", 
  "MUL_SYMBOL", "DIV_SYMBOL", "SEMICOLON_SYMBOL", "COMMA_SYMBOL", "LEFT_PAR", 
  "RIGHT_PAR", "LEFT_BRA", "RIGHT_BRA", "IDENTIFIER", "SINGLE_COMMENT"
};

dfa::Vocabulary ARParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ARParser::_tokenNames;

ARParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x11, 0x4d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x20, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x23, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x2b, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x30, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x33, 0xb, 0x5, 0x5, 0x5, 0x35, 
    0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x7, 0x9, 0x45, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x48, 0xb, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x2, 0x3, 0x4, 0xb, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 0x6, 0x3, 0x2, 0x6, 0x9, 0x3, 
    0x2, 0x8, 0x9, 0x3, 0x2, 0x6, 0x7, 0x3, 0x2, 0x3, 0x5, 0x2, 0x49, 0x2, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x16, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x34, 0x3, 0x2, 0x2, 0x2, 0xa, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x38, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x46, 0x3, 0x2, 0x2, 0x2, 0x12, 0x49, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x15, 0x9, 0x2, 0x2, 0x2, 0x15, 0x3, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 
    0x8, 0x3, 0x1, 0x2, 0x17, 0x18, 0x7, 0x10, 0x2, 0x2, 0x18, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x1a, 0xc, 0x5, 0x2, 0x2, 0x1a, 0x1b, 0x9, 0x3, 
    0x2, 0x2, 0x1b, 0x20, 0x5, 0x4, 0x3, 0x6, 0x1c, 0x1d, 0xc, 0x4, 0x2, 
    0x2, 0x1d, 0x1e, 0x9, 0x4, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x4, 0x3, 0x5, 
    0x1f, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x5, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x25, 0x7, 0xe, 0x2, 0x2, 0x25, 0x2b, 0x7, 0xf, 
    0x2, 0x2, 0x26, 0x27, 0x7, 0xe, 0x2, 0x2, 0x27, 0x28, 0x5, 0xe, 0x8, 
    0x2, 0x28, 0x29, 0x7, 0xf, 0x2, 0x2, 0x29, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x24, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x31, 0x5, 0x4, 0x3, 0x2, 0x2d, 0x2e, 
    0x7, 0xb, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 0x3, 0x2, 0x2f, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x9, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x37, 0x9, 0x5, 0x2, 0x2, 0x37, 0xb, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x5, 0xa, 0x6, 0x2, 0x39, 0x3a, 0x7, 0x10, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
    0xc, 0x2, 0x2, 0x3b, 0x3c, 0x5, 0x8, 0x5, 0x2, 0x3c, 0x3d, 0x7, 0xd, 
    0x2, 0x2, 0x3d, 0x3e, 0x5, 0x6, 0x4, 0x2, 0x3e, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x5, 0xc, 0x7, 0x2, 0x40, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x42, 0x5, 0xe, 0x8, 0x2, 0x42, 0x43, 0x7, 0xa, 0x2, 0x2, 0x43, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x44, 0x41, 0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x11, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4a, 0x5, 0x10, 0x9, 0x2, 0x4a, 0x4b, 0x7, 0x2, 0x2, 
    0x3, 0x4b, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1f, 0x21, 0x2a, 0x31, 0x34, 
    0x46, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ARParser::Initializer ARParser::_init;
