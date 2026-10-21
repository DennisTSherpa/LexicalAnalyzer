/* 
 * main.cpp
 * A lexical analyzer for the Eagle programming language
 * Author: Dennis Sherpa - sherpad@bc.edu
 */

#include <FlexLexer.h>
#include <fstream>
#include <iostream>
#include <string>

#include "eagle.h"

int main(int argc, char * argv[]) {
    std::ifstream input_file;
    yyFlexLexer * lexer = nullptr;
    if (argc > 1) {
        input_file.open(argv[1]);
        if (!input_file.is_open()) {
            std::cerr << "Error: Could not open file " << argv[1] << std::endl;
            return EXIT_FAILURE;
        }
        lexer = new yyFlexLexer(&input_file);
    } else {
        lexer = new yyFlexLexer();
    }
    Token token;
    while (true) {
        token = static_cast<Token>(lexer->yylex());
        if (token == 0) {
            break;
        }
        switch (token) {
            case STRING: {
                std::string s = lexer->YYText();
                std::cout << "String: " << s.substr(1, s.length()-2) << std::endl;
                break;
            } case RATIONAL:
                std::cout << "Rational: " << std::stod(lexer->YYText()) << std::endl;
                break;
            case INTEGER:
                std::cout << "Integer: " << std::stol(lexer->YYText()) << std::endl;
                break;
            case IDENTIFIER:
                std::cout << "Identifier: " << lexer->YYText() << std::endl;
                break;
            case OP_NE:
                std::cout << "Operator: OP_NE" << std::endl;
                break;
            case OP_LE:
                std::cout << "Operator: OP_LE" << std::endl;
                break;
            case OP_GE:
                std::cout << "Operator: OP_GE" << std::endl;
                break;
            case OP_ARROW:
                std::cout << "Operator: OP_ARROW" << std::endl;
                break;
            case OP_PERIOD:
                std::cout << "Operator: OP_PERIOD" << std::endl;
                break;
            case OP_COMMA:
                std::cout << "Operator: OP_COMMA" << std::endl;
                break;
            case OP_SEMICOLON:
                std::cout << "Operator: OP_SEMICOLON" << std::endl;
                break;
            case OP_COLON:
                std::cout << "Operator: OP_COLON" << std::endl;
                break;
            case OP_EQUALS:
                std::cout << "Operator: OP_EQUALS" << std::endl;
                break;
            case OP_LT:
                std::cout << "Operator: OP_LT" << std::endl;
                break;
            case OP_GT:
                std::cout << "Operator: OP_GT" << std::endl;
                break;
            case OP_PLUS:
                std::cout << "Operator: OP_PLUS" << std::endl;
                break;
            case OP_MINUS:
                std::cout << "Operator: OP_MINUS" << std::endl;
                break;
            case OP_TIMES:
                std::cout << "Operator: OP_TIMES" << std::endl;
                break;
            case OP_DIVIDE:
                std::cout << "Operator: OP_DIVIDE" << std::endl;
                break;
            case OP_MODULO:
                std::cout << "Operator: OP_MODULO" << std::endl;
                break;
            case OP_LPAREN:
                std::cout << "Operator: OP_LPAREN" << std::endl;
                break;
            case OP_RPAREN:
                std::cout << "Operator: OP_RPAREN" << std::endl;
                break;
            case OP_LBRAC:
                std::cout << "Operator: OP_LBRAC" << std::endl;
                break;
            case OP_RBRAC:
                std::cout << "Operator: OP_RBRAC" << std::endl;
                break;
            case TYPE_INT:
                std::cout << "Type declarator: TYPE_INT" << std::endl;
                break;
            case TYPE_FLOAT:
                std::cout << "Type declarator: TYPE_FLOAT" << std::endl;
                break;
            case TYPE_STRING:
                std::cout << "Type declarator: TYPE_STRING" << std::endl;
                break;
            case FUNCTION:
                std::cout << "Keyword: FUNCTION" << std::endl;
                break;
            case PROCEDURE:
                std::cout << "Keyword: PROCEDURE" << std::endl;
                break;
            case IF:
                std::cout << "Keyword: IF" << std::endl;
                break;
            case OTHERWISE:
                std::cout << "Keyword: OTHERWISE" << std::endl;
                break;
            case AND:
                std::cout << "Keyword: AND" << std::endl;
                break;
            case OR:
                std::cout << "Keyword: OR" << std::endl;
                break;
            case NOT:
                std::cout << "Keyword: NOT" << std::endl;
                break;
            case LET:
                std::cout << "Keyword: LET" << std::endl;
                break;
            case IN:
                std::cout << "Keyword: IN" << std::endl;
                break;
            case TYPE:
                std::cout << "Keyword: TYPE" << std::endl;
                break;
            case RECORD:
                std::cout << "Keyword: RECORD" << std::endl;
                break;
            default:
                std::cout << "Error: " << lexer->YYText() << std::endl;
                break;
        }
    }
    delete lexer;
    return EXIT_SUCCESS;
}
