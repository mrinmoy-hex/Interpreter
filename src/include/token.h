#pragma once

typedef struct TOKEN_STRUCT {
    enum {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_SEMI,
        TOKEN_LPAREN,
        TOKEN_RPAREN
    } types;

    char* value;
} token_T;

token_T* init_token(int type, char* value);
