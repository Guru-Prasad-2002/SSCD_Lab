%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
input:s'\n'{printf("Valid Expression\n");exit(0);}
		s : A s1 B | B 
		s1 : ; |A s1 
%%
int yyerror(){
	printf("Something went wrong\n");
	exit(0);
}
int main(){
	printf("Enter the String\n");
	yyparse();
	return 0;
}



