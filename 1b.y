%{
#include <stdio.h>
#include <stdlib.h>
%}
%token num;
%left '+''-'
%left '*''/'
%%
input:exp{printf("The result after evaluation=%d",$$);exit(0);}

exp:exp'+'exp{$$=$1+$3;}
|exp'-'exp{$$=$1-$3;}
|exp'*'exp{$$=$1*$3;}
|exp'/'exp{if($3==0){printf("Divide by 0 error\n");exit(0);}else{$$=$1/$3;}}
|'('exp')'{$$=$2;}
|num {$$=$1;}
%%
int yyerror(){
	printf("Something went wrong\n");
	exit(0);
}
int main(){
	printf("Enter the expression to be evaluated\n");
	yyparse();
	return 0;
}
