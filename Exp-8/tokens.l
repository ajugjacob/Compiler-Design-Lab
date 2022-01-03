
%{
#include<stdio.h>
%}

%%
auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short     {ECHO; printf("\tKEYWORD\n");} 						

[{};,()]   {ECHO; printf("\tSEPERATOR\n");}						

[+-/=*%]   {ECHO; printf("\tOPERATOR\n");}		

([a-zA-Z][0-9])+|[a-zA-Z]* {ECHO; printf("\tIDENTIFIER\n");}  

[0-9]* {ECHO; printf("\tNUMBER\n");}

.|\n ; 															
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
