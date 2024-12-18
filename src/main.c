#include <stdio.h>
#include "../include/lexer.h"
#include "../include/parser.h"

int main(int argc, char* argv[]) 
{
    lexer_t* lexer = init_lexer(
        "var name = \"mrinmoy\";\n"
        "print(name);\n"
    );

    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser);

    printf("%d\n", root->type);
    printf("%d\n", root->compound_size);

    return 0;
}