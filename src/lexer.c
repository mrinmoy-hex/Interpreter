#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

lexer_t* init_lexer(char* contents) {
    lexer_t* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->current_pos = 0;
    lexer->current_char = contents[lexer->current_pos];

    return lexer;
}

void lexer_advance(lexer_t* lexer) {
    if (lexer->current_char != '\0' && lexer->current_pos < strlen(lexer->contents))
    {
        lexer->current_pos += 1;
        lexer->current_char = lexer->contents[lexer->current_pos];
    }
}

void lexer_skip_whitespace(lexer_t* lexer) {
    while (lexer->current_char == ' ' || lexer->current_char == 10)     // 10 -> new line
    {
        lexer_advance(lexer);
    }
}

token_T* lexer_get_next_token(lexer_t* lexer) {
    while (lexer->current_char != '\0' && lexer->current_pos < strlen(lexer->contents))
    {
        if (lexer->current_char == ' ' || lexer->current_char == 10)
        {
            lexer_skip_whitespace(lexer);
        }

        if (isalnum(lexer->current_char))
        {
            return lexer_collect_id(lexer);
        }

        if (lexer->current_char == '"'){
            return lexer_collect_string(lexer);
        }

        switch (lexer->current_char) {
            case '=':
                return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_str(lexer)));
                break;
            case ';':
                return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_str(lexer)));
                break;
            case '(':
                return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_str(lexer)));
                break;
            case ')':
                return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_str(lexer)));
                break;
        }
    }
    return (void*)0;
}

token_T* lexer_collect_string(lexer_t* lexer) {
    lexer_advance(lexer);

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (lexer->current_char != '"') 
    {
        char* _strings = lexer_get_current_char_as_str(lexer);
        value = realloc(value, (strlen(value) + strlen(_strings) + 1) * sizeof(char));
        strcat(value, _strings);
        lexer_advance(lexer);
    }
    lexer_advance(lexer);

    return init_token(TOKEN_STRING, value);
}

token_T* lexer_collect_id(lexer_t* lexer) {
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (isalnum(lexer->current_char))
    {
        char* _strings = lexer_get_current_char_as_str(lexer);
        value = realloc(value, (strlen(value) + strlen(_strings) + 1) * sizeof(char));
        strcat(value, _strings);
        lexer_advance(lexer);
    }
    // lexer_advance(lexer);

    return init_token(TOKEN_ID, value);
}

token_T* lexer_advance_with_token(lexer_t* lexer, token_T* token){
    lexer_advance(lexer);

    return token;
}

char* lexer_get_current_char_as_str(lexer_t* lexer) {
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->current_char;
    str[1] = '\0';

    return str;
}