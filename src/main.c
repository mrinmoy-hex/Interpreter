#include <stdio.h>
#include "../include/lexer.h"

int main(int argc, char* argv[]) 
{
    lexer_t* lexer = init_lexer(
        "var name = \"mrinmoy\";\n"
        "print(name);\n"
    );

    token_T* token = (void*)0;

    while ((token = lexer_get_next_token(lexer)) != (void*)0)
    {
        printf("Token(%d, %s)\n", token->types, token->value);
    }

    return 0;
}