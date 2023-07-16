%{
#include<stdio.h>
#include<stdlib.h>
int c=0;
%}
%%
[/*].*["\n"].*[*/] {c++;}
[//].*[^"\n"] {c++;}
[a-zA-Z0-9] {fprintf(yyout,"%s",yytext);}
%%
int main(int argc,char *argv[]){
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
	printf("Comments=%d\n",c);
	return 0;
}	
