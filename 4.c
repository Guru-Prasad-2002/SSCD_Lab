#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k=0,i=0,j=0,c,z;
char a[20],ac[20],act[20],stk[20];

void check();

void main(){
printf("Enter the string\n");
scanf("%s",a);

printf("\tINPUT\tSTACK\tACTION\n");

c=strlen(a);
strcpy(act,"SHIFT->");

for(k=0,i=0;j<c;k++,i++,j++){
	if(a[j]=='i' && a[j+1]=='d'){
		stk[i]=a[j];
		stk[i+1]=a[j+1];
		stk[i+2]='\0';
		a[j]=' ';
		a[j+1]=' ';
		printf("\t$%s\t%s$\t%sid\n",stk,a,act);
		check();
	}else{
		stk[i]=a[j];
		stk[i+1]='\0';
		a[j]=' ';
		printf("\t$%s\t%s$\t%s\n",stk,a,act);
		check();
	}
}
}

void check(){
	strcpy(ac,"REDUCE TO E");
	for(z=0;z<c;z++){
		if(stk[z]=='i' && stk[z+1]=='d'){
			stk[z]='E';
			stk[z+1]='\0';
			printf("\t$%s\t%s$\t%s\n",stk,a,ac);
			j++;
		}
	}
	for(z=0;z<c;z++){
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E'){
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\t$%s\t%s$\t%s\n",stk,a,ac);
			i=i-2;
		}
	}
	for(z=0;z<c;z++){
		if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E'){
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\t$%s\t%s$\t%s\n",stk,a,ac);
			i=i-2;
		}
	}
	for(z=0;z<c;z++){
		if(stk[z]=='(' && stk[z+1]=='+' && stk[z+2]==')'){
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\t$%s\t%s$\t%s\n",stk,a,ac);
			i=i-2;
		}
	}
}






