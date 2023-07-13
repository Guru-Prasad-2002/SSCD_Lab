#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char prod[3][10]={"A->aBa","B->bB","B->@"};
char stack[25],input[25];
int top=-1;
int i,j,k,l;

void push(char item){
	top=top+1;
	stack[top]=item;
}
void pop(){
	top=top-1;
}
void stackpush(char p){
	if(p=='A'){
		pop();
		for(j=strlen(prod[0])-1;j>=3;j--){
			push(prod[0][j]);	
		}
	}else{
		pop();
		for(j=strlen(prod[1])-1;j>=3;j--){
			push(prod[1][j]);	
		}
	}
}
int main(){
	printf("Enter the input string ending with dollar\n");
	scanf("%s",input);
	for(i=0;input[i]!='\0';i++){
		if(input[i]!='a' && input[i]!='b' && input[i]!='$'){
			printf("Invalid String\n");
			exit(0);
		}
	}
	if(input[i-1]!='$'){
		printf("String not ending with dollar\n");
		exit(0);
	}
	push('$');
	push('A');
	i=0;
	printf("\tSTACK\tINPUT\tACTION");
	printf("\n\n");
	while(stack[top]!='$' && i!=strlen(input)){
		printf("\n\t");
		for(l=top;l>=0;l--){
			printf("%c",stack[l]);
		}
		printf("\t");
		for(k=i;k<strlen(input);k++){
			printf("%c",input[k]);
		}
		printf("\t");
		if(stack[top]=='A'){
			printf("A->aBa\t");
			stackpush('A');
		}else if(stack[top]=='B'){
			if(input[i]!='b'){
				printf("Matched @");
				pop();
			}else{
				printf("B->bB\t");
				stackpush('B');
			}
		}else{
			if(stack[top]==input[i]){
				printf("Matched %c",input[i]);
				pop();
				i++;			
			}else{
				break;			
			}		
		}
	}
	if(stack[top]=='$' && input[i]=='$'){
		printf("\nValid String Accepted\n");
	}else{
		printf("\nInvalid String Rejected\n");
	}
	return 0;
}





