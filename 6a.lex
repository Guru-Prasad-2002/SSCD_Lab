%{
#include <stdio.h>
#include <stdlib.h>
int c=0;
%}
%%
[/*].*["\n"].*[*/] {c++;}
[//].*[^"\n"] {c++;}
[a-zA-Z0-9] {fprintf(yyout,"%s",yytext);}
%%
int main(int argc,char *argv[]){
	printf("1\n");
	FILE *yyin,*yyout;
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	printf("2\n");
	yylex();
	printf("3\n");
	printf("Number of commented lines=%d",c);
	return 0;
}

