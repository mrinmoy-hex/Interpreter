#pragma once
#include "token.h"

typedef struct LEXER_STRUCT {
    char current_char;
    unsigned int current_pos;
    char* contents;
} lexer_t;

lexer_t* init_lexer(char* contents);

void lexer_advance(lexer_t* lexer);

void lexer_skip_whitespace(lexer_t* lexer);

token_T* lexer_get_next_token(lexer_t* lexer);

token_T* lexer_collect_string(lexer_t* lexer);

token_T* lexer_collect_id(lexer_t* lexer);

token_T* lexer_advance_with_token(lexer_t* lexer, token_T* token);

char* lexer_get_current_char_as_str(lexer_t* lexer);