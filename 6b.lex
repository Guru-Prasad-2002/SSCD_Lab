%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
extern yylval;
%}
%%
[\t] ;
[+\-\*\/\<\>] {printf("OPERATORS %s \n",yytext);return OP;}
[0-9]+ {yylval=atoi(yytext);printf("DIGIT %d \n",yylval);return DIG;}
int|bool|char|void|return|if|else|for|do|while {printf("KEYWORDS %s \n",yytext);return KEY;}
[a-zA-Z0-9]+ {printf("IDENTIFIERS %s \n",yytext);return ID;}
. ;
%%
