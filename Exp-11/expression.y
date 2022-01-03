%{
/* Definition section */
#include<stdio.h>
#include<stdlib.h>
%}

%token A B NL

/* Rule Section */
%%
stmt: S NL { printf("valid string\n");
			exit(0); }
;
S: A S B |
;
%%

int yyerror(char *msg)
{
printf("invalid string\n");
exit(0);
}


void main()
{
printf("enter the string\n");
yyparse();
}
