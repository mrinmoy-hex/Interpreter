#pragma once
#include "lexer.h"
#include "AST.h"

typedef struct PARSER_STRUCT
{
    lexer_t* lexer;
    token_T* current_token;
} parser_T;

parser_T* init_parser(lexer_t* lexer);

void parser_eat(parser_T* parser, int token_type);

AST_T* parser_parse(parser_T* parser);

AST_T* parser_parse_statement(parser_T* parser);    // this will parse single statements

AST_T* parser_parse_statements(parser_T* parser);   // this will parse a lists of statements

AST_T* parser_parse_expr(parser_T* parser); 

AST_T* parser_parse_factor(parser_T* parser); 

AST_T* parser_parse_term(parser_T* parser); 

AST_T* parser_parse_function_call(parser_T* parser);

AST_T* parser_parse_variable(parser_T* parser);

AST_T* parser_parse_string(parser_T* parser);
