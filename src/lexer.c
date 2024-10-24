#include "../include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to initialize the lexer with the contents to be tokenized
lexer_t* init_lexer(char* contents) {
    lexer_t* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;        
    lexer->current_pos = 0;            
    lexer->current_char = contents[lexer->current_pos];

    return lexer;
}

// Function to advance the lexer position by one character
void lexer_advance(lexer_t* lexer) {
    if (lexer->current_char != '\0' && lexer->current_pos < strlen(lexer->contents)) {
        lexer->current_pos += 1;
        lexer->current_char = lexer->contents[lexer->current_pos];
    }
}

void lexer_skip_whitespace(lexer_t* lexer) {
    // Continue advancing while the current character is a space or newline
    while (lexer->current_char == ' ' || lexer->current_char == 10) {  // 10 is ASCII for newline
        lexer_advance(lexer);
    }
}

// Function to get the next token from the input
token_T* lexer_get_next_token(lexer_t* lexer) {
    // Process the input until the end of the string is reached
    while (lexer->current_char != '\0' && lexer->current_pos < strlen(lexer->contents)) {
        
        // Skip over any whitespace before processing the next token
        if (lexer->current_char == ' ' || lexer->current_char == 10) {
            lexer_skip_whitespace(lexer);
        }

        // If the current character is alphanumeric, it's likely an identifier
        if (isalnum(lexer->current_char)) {
            return lexer_collect_id(lexer);
        }

        // If the current character is a double quote, it's the start of a string
        if (lexer->current_char == '"') {
            return lexer_collect_string(lexer); 
        }

        // Switch statement to handle single-character tokens (operators, punctuation)
        switch (lexer->current_char) {
            case '=':
                return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_str(lexer)));
            case ';':
                return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_str(lexer)));
            case '(':
                return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_str(lexer)));
            case ')':
                return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_str(lexer)));
        }
    }
    // If the input is exhausted, return NULL to signify no more tokens
    return (void*)0;
}

// Function to collect a string token, assuming the lexer is positioned at the opening quote
token_T* lexer_collect_string(lexer_t* lexer) {
    lexer_advance(lexer);  // Skip the opening double-quote

    // Allocate an initial empty string
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';  // Initialize it as an empty string

    // Collect characters until the closing quote is encountered
    while (lexer->current_char != '"') {
        char* _strings = lexer_get_current_char_as_str(lexer);
        // Reallocate memory to accommodate the new character and append it
        value = realloc(value, (strlen(value) + strlen(_strings) + 1) * sizeof(char));
        strcat(value, _strings);
        lexer_advance(lexer);
    }
    lexer_advance(lexer);  // Skip the closing quote

    
    return init_token(TOKEN_STRING, value);
}

// Function to collect an identifier token (alphanumeric string)
token_T* lexer_collect_id(lexer_t* lexer) {
    // Allocate an initial empty string
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';  // Initialize it as an empty string

    // Collect alphanumeric characters
    while (isalnum(lexer->current_char)) {
        char* _strings = lexer_get_current_char_as_str(lexer); 
        // Reallocate memory to accommodate the new character and append it
        value = realloc(value, (strlen(value) + strlen(_strings) + 1) * sizeof(char));
        strcat(value, _strings);
        lexer_advance(lexer); 
    }

   
    return init_token(TOKEN_ID, value);
}

// Function to advance the lexer and return a token
token_T* lexer_advance_with_token(lexer_t* lexer, token_T* token) {
    lexer_advance(lexer); 
    return token;
}

// Helper function to get the current character as a string
char* lexer_get_current_char_as_str(lexer_t* lexer) {
    // Allocate memory for a 2-character string (1 char + null terminator)
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->current_char;  // Set the first element to the current character
    str[1] = '\0';  // Null-terminate the string
    return str;
}
