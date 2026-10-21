/*
 * eagle.h
 * Definition of the enumeration type used to identify tokens in Eagle
 * Author: Dennis Sherpa - sherpad@bc.edu
 */

#pragma once

enum Token { 
    STRING = 1, 
    RATIONAL, 
    INTEGER, 
    OP_NE,          // ~=
    OP_LE,          // <=
    OP_GE,          // >=
    OP_ARROW,       // ->
    OP_PERIOD,      // .
    OP_COMMA,       // ,
    OP_SEMICOLON,   // ;
    OP_COLON,       // :
    OP_EQUALS,      // =
    OP_LT,          // <
    OP_GT,          // >
    OP_PLUS,        // +
    OP_MINUS,       // -
    OP_TIMES,       // *
    OP_DIVIDE,      // /
    OP_MODULO,      // %
    OP_LPAREN,      // (
    OP_RPAREN,      // )
    OP_LBRAC,       // [
    OP_RBRAC,       // ]
    FUNCTION,
    PROCEDURE,
    IF,
    OTHERWISE,
    AND,
    OR,
    NOT,
    LET,
    IN,
    TYPE,
    RECORD,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    IDENTIFIER,
    ERROR
};
