%{
#include<stdio.h>
#include<stdlib.h>
	int op=0,id=0,v=0;
%}
%%
[0-9]+ {id++;}
"("  {v++;}
")"  {v--;}
[+\-\/\*] {op++;}
.|\n {;}
%%
int main(){
	printf("Enter the arithematic expression to be evaluated\n");
	yylex();
	if(v==0 && id==op+1){
		printf("Valid Expression\n");
	}
	else{
		printf("Invalid Expression\n");
	}
	return 0;
}

