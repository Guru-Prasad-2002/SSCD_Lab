#include<stdio.h>
#include<stdlib.h>

int max[10][10],need[10][10],alloc[10][10],safeseq[10],avail[10],completed[10];
int count=0,process=-1,i,j,p,r;

int main(){
	printf("Enter the number of processes\n");
	scanf("%d",&p);

	for(i=0;i<p;i++){
		completed[i]=0;
	}
	
	printf("Enter the number of resources\n");
	scanf("%d",&r);

	printf("Enter the max matrix \n");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}

	printf("Enter the alloc matrix \n");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			scanf("%d",&alloc[i][j]);
		}
	}

	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}

	printf("Enter the available resources \n");
	for(i=0;i<r;i++){
		scanf("%d",&avail[i]);
	}


	do{
		printf("Max Matrix \t Alloc Matrix\n");
		
		for(i=0;i<p;i++){
			for(j=0;j<r;j++){
				printf("%d",max[i][j]);
			}
			printf("\t\t");
			for(j=0;j<r;j++){
				printf("%d",alloc[i][j]);
			}
			printf("\n");
		}
		process=-1;
		for(i=0;i<p;i++){
			if(completed[i]==0){
				process=i;
				for(j=0;j<r;j++){
					if(avail[j]<need[process][j]){
						process=-1;
						break;
					}
				}
				if(process!=-1){
					break;
				} 
			}
		}
		if(process!=-1){
			completed[process]=1;
			safeseq[count]=process+1;
			count=count+1;
			
			for(j=0;j<r;j++){
				avail[j]=alloc[process][j];
				max[process][j]=0;
				alloc[process][j]=0;
				need[process][j]=0;
			}	
		}
	}while(process!=-1 && count!=p);

	if(count==p){
		printf("SAFE STATE\n");
		printf("SAFE SEQUENCE IS AS FOLLOWS");
		for(i=0;i<p;i++){
			printf("%d ",safeseq[i]);
		}
		printf("\n");
	}else{
		printf("NOT IS SAFE STATE\n");
	}
	return 0;
}




