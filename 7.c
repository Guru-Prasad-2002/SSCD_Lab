#include <stdio.h>
#include <stdlib.h>

int rt[10],at[10],bt[10];
int count=0,flag=0;
int smallest,endTime;
int srtf_tt,srtf_wt;
int rr_tt,rr_wt;
int ch,n,time,time_quantum,remain,i;

int main(){
	printf("1.ROUND ROBIN \n 2.SRTF \n");
	printf("Enter your choice");
	
	scanf("%d",&ch);
	
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	
	printf("Enter arrival and burst time for each process\n");
	for(int i=0;i<n;i++){
		printf("Enter arrival time for process P[%d]\t",i+1);
		scanf("%d",&at[i]);
		
		printf("Enter burst time for process P[%d]\t",i+1);
		scanf("%d",&bt[i]);
		
		rt[i]=bt[i];
	}
	switch(ch){
		case 1:
				remain=n;
				time=0;
				rr_tt=0;
				rr_wt=0;
				printf("Enter the time quantum \n");
				scanf("%d",&time_quantum);
				printf("Process\tTurnAround Time\tWaiting Time\n");
				for(count=0,time=0;remain!=0;){
					if(rt[count]<=time_quantum && rt[count]>0){
						time=time+rt[count];
						rt[count]=0;
						flag=1;
					}else if(rt[count]>0){
						time=time+time_quantum;
						rt[count]=rt[count]-time_quantum;
					}
					if(flag==1 && rt[count]==0){
						remain--;
						flag=0;
						printf("P[%d]\t%d\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
						rr_tt=rr_tt+time-at[count];
						rr_wt=rr_wt+time-at[count]-bt[count];
					}
					if(count==n-1){
						count=0;
					}else if(at[count+1]<=time){
						count=count+1;
					}else{
						count=0;
					}
				}
				printf("ROUND ROBIN TT %2f\n",rr_tt*1.0/n);
				printf("ROUND ROBIN WT %2f\n",rr_wt*1.0/n);
				break;
		case 2:	remain=0;
				rt[9]=9999;
				srtf_tt=0;
				srtf_wt=0;
				for(time=0;remain!=n;time++){
					smallest=9;
					for(i=0;i<n;i++){
						if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0){
							smallest=i;
						}
						rt[smallest]--;
						//time=time+1;
						if(rt[smallest]==0){
							remain+=1;
							endTime=time+1;
							printf("P[%d]\t%d\t%d\n",smallest+1,endTime-at[smallest],endTime-at[smallest]-bt[smallest]);
						srtf_tt=srtf_tt+endTime-at[smallest];
						srtf_wt=srtf_wt+endTime-bt[smallest]-at[smallest];
						}
					}
				}
				printf("SRTF TT %f\n",srtf_tt*1.0/n);
				printf("SRTF WT %f\n",srtf_wt*1.0/n);
				break;
		default:
				printf("Please enter the correct option \n");
				break;
	}
	return 0;
}





