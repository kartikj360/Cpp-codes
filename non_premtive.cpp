// Done by KARTIK JOSHI 3932
//SHORTEST JOB FIRST, NON PRE-EMPTIVE(WITH SAME ARRIVAL TIME)
#include<iostream>
using namespace std;

float findtat(int n, int p_bt[], int p_wt[], int p_tat[]){
    float total_tat=0;                              //stores the total turn around time 
    for(int i=0;i<n;i++){
        p_tat[i]=p_wt[i]+p_bt[i];
        total_tat+=p_tat[i];
    }

    return total_tat/n;
}

float findwt(int n, int p_bt[], int p_wt[]){
    p_wt[0]=0;
    float total_wt=0;                                 //stores the total waiting time
    for(int i=1;i<n;i++){
        p_wt[i]=p_wt[i-1]+p_bt[i-1];
        total_wt+=p_wt[i];
    }

    return total_wt/n;
}
int main(){
    int n;    //stores the number of processes
    cout<<"Enter the number of processes - ";
    cin>>n;
    int p_bt[n];                                       //stores the burst time or run time for each process
    int p_wt[n];                                       //stores the waiting time for each process
    int p_tat[n];                                     //stores the turn around time for each process
    for(int i=0;i<n;i++){
        cout<<"\nEnter the burst time for process "<<i+1<<" - ";
        cin>>p_bt[i];
    }
    int count=0,temp=0;
    while(count<n-1){                                  //sorting the data in asceding order
        count=0;
        for(int i=0;i<n-1;i++){
            if(p_bt[i+1]<p_bt[i]){
                temp=p_bt[i];
                p_bt[i]=p_bt[i+1];
                p_bt[i+1]=temp;
            }
            else{
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<p_bt[i];
    }

    float avg_wt=findwt(n,p_bt,p_wt);                    //stores the average waiting time
    cout<<"\nAverage waiting time is - "<<avg_wt;
    float avg_tat=findtat(n,p_bt,p_wt,p_tat);            //stores the average turn around time
    cout<<"\nAverage turn around time is - "<<avg_tat;
    return 0;
}