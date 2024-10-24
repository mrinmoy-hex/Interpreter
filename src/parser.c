#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>

parser_T* init_parser(lexer_t* lexer) 
{
    parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->current_token = lexer_get_next_token(lexer);

    return parser;
}

void parser_eat(parser_T* parser, int token_type) 
{
    if (parser->current_token->types == token_type)
    {
        parser->current_token = lexer_get_next_token(parser->lexer);
    }
    else
    {
        fprintf(stderr, 
        "Unexpected token '%s', with type %d", 
        parser->current_token->value,
        parser->current_token->types
        );
        exit(1);
    }
}

AST_T* parser_parse(parser_T* parser) 
{
    // return parser_parse_statements();
}

AST_T* parser_parse_statement(parser_T* parser) 
{

}    

AST_T* parser_parse_statements(parser_T* parser) 
{

}  

AST_T* parser_parse_expr(parser_T* parser) 
{

} 

AST_T* parser_parse_factor(parser_T* parser)
{

}

AST_T* parser_parse_term(parser_T* parser) 
{

} 

AST_T* parser_parse_function_call(parser_T* parser) 
{

}

AST_T* parser_parse_variable(parser_T* parser) 
{

}

AST_T* parser_parse_string(parser_T* parser) 
{

}