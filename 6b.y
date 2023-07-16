%{
#include<stdio.h>
#include<stdlib.h>
int id=0,dig=0,op=0,key=0; 
%}
%token ID KEY DIG OP
%%
input:OP input{op++;}
|ID input{id++;}
|KEY input{key++;}
|DIG input{dig++;}
|OP {op++;}
|ID {id++;}
|KEY {key++;}
|DIG {dig++;};
%%
#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yyparse();
extern FILE* yyin;

int main(){
	FILE* myfile;
	myfile=fopen("Add.c","r");
	if(!myfile){
		printf("Cant open\n");
		exit(0);
	}
	yyin=myfile;
	do{
		yyparse();
	}while(!feof(yyin));
	return 0;
}
int yyerror(){
	printf("Error\n");
	exit(0);
}
