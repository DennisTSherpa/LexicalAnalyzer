/*
 * eagle.lex
 * The Flex specification file for the Eagle programming language
 * Author: Dennis Sherpa - sherpad@bc.edu
 */

%{
#include "eagle.h"
%}

%option noinput nounput
%option noyywrap
%option c++

WS          [ \t\r\n]
COMMENTS    #[^\n]*
FALSE_ID    [0-9]+[a-zA-Z_][a-zA-Z0-9_]*
DIGIT       [0-9]
STRING      \"[^\n"]*\"
INTEGER     {DIGIT}+
RATIONAL    {DIGIT}+\.{DIGIT}+
ID          [a-zA-Z_][a-zA-Z0-9_]*


%%

{WS}                { /* Skip whitespace */ }
{COMMENTS}          { /* Skip comments */ }
{FALSE_ID}          { return ERROR; }
{STRING}            { return STRING; }
{RATIONAL}          { return RATIONAL; }
{INTEGER}           { return INTEGER; }
"~="                { return OP_NE; }
"<="                { return OP_LE; }
">="                { return OP_GE; }
"->"                { return OP_ARROW; }
"."                 { return OP_PERIOD; }
","                 { return OP_COMMA; }
";"                 { return OP_SEMICOLON; }
":"                 { return OP_COLON; }
"="                 { return OP_EQUALS; }
"<"                 { return OP_LT; }
">"                 { return OP_GT; }
"+"                 { return OP_PLUS; }
"-"                 { return OP_MINUS; }
"*"                 { return OP_TIMES; }
"/"                 { return OP_DIVIDE; }
"%"                 { return OP_MODULO; }
"("                 { return OP_LPAREN; }
")"                 { return OP_RPAREN; }
"["                 { return OP_LBRAC; }
"]"                 { return OP_RBRAC; }
"function"          { return FUNCTION; }
"procedure"         { return PROCEDURE; }
"if"                { return IF; }
"otherwise"         { return OTHERWISE; }
"and"               { return AND; }
"or"                { return OR; }
"not"               { return NOT; }
"let"               { return LET; }
"in"                { return IN; }
"type"              { return TYPE; }
"record"            { return RECORD; }
"int"               { return TYPE_INT; }
"float"             { return TYPE_FLOAT; }
"string"            { return TYPE_STRING; }
{ID}                { return IDENTIFIER; }
.                   { return ERROR; }

%%
