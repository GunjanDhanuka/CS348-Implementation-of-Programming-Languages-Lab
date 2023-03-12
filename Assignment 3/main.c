#include <stdio.h>
#include "header.h"

extern int yylex();
extern char* yytext;
extern int yylineno;
extern int yylen;
extern FILE* yyin;
extern FILE* yyout;

int main(){
    int next_token;

    yyin = fopen("test.c", "r");

    next_token = yylex();

    while(next_token){
        switch (next_token)
        {
        case KEYWORD:
            printf("<KEYWORD, %s>\n", yytext);
            break;

        case IDENTIFIER:
            printf("<IDENTIFIER, %s>\n", yytext);
            break;
        
        case INT_CONSTANT:
            printf("<INT_CONSTANT, %s>\n", yytext);
            break;

        case CHAR_CONSTANT:
            printf("<CHAR_CONSTANT, %s>\n", yytext);
            break;

        case STRING_LITERAL:
            printf("<STRING_LITERAL, %s>\n", yytext);
            break;

        case PUNCTUATOR:
            printf("<PUNCTUATOR, %s>\n", yytext);
            break;

        case SINGLE_LINE_COMMENT:
            printf("<SINGLE_LINE_COMMENT at line number %d>\n", yylineno);
            break;
        
        case MULTI_LINE_COMMENT:
            printf("MULTI_LINE_COMMENT at line number %d>\n", yylineno);
            break;

        default:
            printf("<UNEXPECTED TOKEN at line number %d: %s>\n", yylineno, yytext);
            break;
        }

        next_token = yylex();
    }

    return 0;
}