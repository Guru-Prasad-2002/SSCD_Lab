#include <stdio.h>
#include <stdlib.h>

void lru(char[],char[],int,int);
void fifo(char[],char[],int,int);

int main(){
    int ch;
    char F[10],s[25];
    int l,f,i;
    while(1){
        printf("Enter the number of frames\n");
        scanf("%d",&f);
        printf("Enter the length of the string\n");
        scanf("%d",&l);
        printf("Enter the string\n");
        scanf("%s",s);
        printf("1.FIFO\n2.LRU\n3.EXIT\n");
        printf("Enter ur choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:for(i=0;i<f;i++){
                F[i]=-1;
                }
                fifo(F,s,f,l);
                break;
            case 2:for(i=0;i<f;i++){
                F[i]=-1;
                }
                lru(F,s,f,l);
                break;
            case 3:exit(0);
            default:printf("Enter a valid option\n");
            break;
        }
    }
    return 0;
}
void fifo(char F[],char s[],int f,int l){
    int cnt=0,flag=0;
    int i,j=0,k;
    printf("\tPage\tFrames\t\t\tPage Faults\n");
    for(i=0;i<l;i++){
        for(k=0;k<f;k++){
            if(F[k]==s[i]){
                flag=1;
            }
        }
        printf("\t%c\t",s[i]);
        if(flag==0){
            F[j]=s[i];
            j++;
            for(k=0;k<f;k++){
                printf("   %c",F[k]);
            }
            printf("\t\tPage Fault %d \n",cnt);
            cnt++;
        }else{
            flag=0;
            for(k=0;k<f;k++){
                printf("   %c",F[k]);
            }
            printf("\t\tPage Hit\n");
        }if(j==f){
            j=0;
        }
    }
}

void lru(char F[],char s[],int f,int l){
    int flag=0,cnt=0;
    int top=0,j=0;
    int m,i,k;
    printf("\tPage\tFrames\t\t\tPage Faults\n");
    for(i=0;i<l;i++){
        for(k=0;k<f;k++){
            if(F[k]==s[i]){
                flag=1;
                break;
            }
        }
        printf("\t%c\t",s[i]);
        if(j!=f && flag!=1){
            F[top]=s[i];
            j++;
            if(j!=f){
                top++;
            }
        }else{
            if(flag!=1){
            for(k=0;k<top;k++){
                F[k]=F[k+1];
            }
            F[top]=s[i];
            }if(flag==1){
            for(m=k;m<top;m++){
                F[m]=F[m+1];
            }
            F[top]=s[i];
            }
        }

        for(k=0;k<f;k++){
            printf("   %c",F[k]);
        }if(flag==0){
            printf("\t\tPage Fault %d \n",cnt);
            cnt++;
        }else{
            printf("\t\tPage Hit\n");
            flag=0;
        }
    }
    printf("LRU DONE");
}
