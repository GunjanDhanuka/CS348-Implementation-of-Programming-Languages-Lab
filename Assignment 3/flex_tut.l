%{
    /* definitions */
%}


single_comment "//".*"\n"
multi_comment [\t]*"/*".*[\n]*.*"*/"[\t]*
main_function "int main()"
function [\t]*[a-zA-Z]+"(".*")"[\t]*\n
keyword [\t]*"char"|"else"|"for"|"if"|"int"|"return"|"void"

/* datatype [\t]*"int"|[\t]*"char"|[\t]*"void" */
arithmetic "+"|"-"|"*"|"/"|"%"
relational [\t]*"<"|"<="|">"|">="|"=="|"!="
logical [\t]*"&&"|"||""!"
conditional [\t]*"?:"
pointer_op [\t]*"&"|"*"|"->"
assignment [\t]*"="
terminator ";"
bracket_op [\t]*"{"[\t]*
bracket_cl [\t]*"}"[\t]*
digit [0-9]
identifier-nondigit [a-zA-Z]
identifier [a-zA-Z_][a-zA-Z0-9_]*



/* rules section */
%%

if {printf("Keyword\n");}
[a-z0-9.]{3,10}@[a-z0-9.-]+ {printf("Email address\n");}
[6-9][0-9]{9} {printf("Mobile number\n");}
[a-zA-Z_][a-zA-Z0-9_]* {printf("Identifier \n");}
.+ {printf("Invalid\n");}
\n {return 0;}

%%

yywrap() {}

int main() {
    printf("Enter string: ");
    yylex();

    return 0;
}