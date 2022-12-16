// OS assignment by 3932(Kartik Joshi)
#include<iostream>
using namespace std;

void waitingTime(int processes[], int n,float burst_time[], float wt[], float timeQ){
	
	int remBt[n]; //to store the remaining running time
	for (int i = 0 ; i < n ; i++)
		remBt[i] = burst_time[i]; //as at first phase it'll be same as running time

	int cTime = 0; //current time

	while (true)//loop will run untill all the processes are done
	{
		bool done = true;	//flag to check whether process is done

		for (int i = 0 ; i < n; i++)//traversing through all the processes
		{
			if (remBt[i] > 0) //remaining time more than 0 means process is incomplete
			{
				done = false; //setting flag to false
				if (remBt[i] > timeQ)//remaining time greater than time quantum process will run for time quantum
				{
					cTime+= timeQ; //increasing current time
					remBt[i] -= timeQ; //now remaining time will be reduced by time quantum
				}else{	//if remaining time is less than or equals 0
					cTime = cTime + remBt[i]; //increasing current time as process will run for remaining time

					wt[i] = cTime - burst_time[i]; //Waiting time=current time-runtime

					remBt[i] = 0; 
				}
			}
		}

		if (done == true)//when the processes are completed flag will be true
		break;
	}
}

void turnAroundTime(int processes[], int n,float burst_time[], float wt[], float tat[]){

	for (int i = 0; i < n ; i++)
		tat[i] = burst_time[i] + wt[i]; //TAT=runtime+waiting time
}

void avgTime(int n,int processes[],float burst_time[],int timeQ){
	float wt[n], tat[n]; //arrays to store waiting time and turn around time respectively
	float total_wt = 0, total_tat = 0;


	waitingTime(processes, n, burst_time, wt, timeQ); //calculating waiting time and storing to wt

	
	turnAroundTime(processes, n, burst_time, wt, tat); //calculating turn around time and storing to tat

	//printing the result table
	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n";
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << burst_time[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "<< (float)total_wt / (float)n; //avg wt= total waiting time/number of processes
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;//avg tat=total tat/number of processes
}


int main()
{	
	//taking inputs 
    cout<<"Enter the number of Processes: ";
    int n;
    cin>>n;

	int processes[n];	//array to store the process ids
    cout<<"Enter the process ids: "<<endl;
	for(int i=0;i<n;i++){
        cin>>processes[i];
    }

	float burst_time[n];	//array to store the runtimes
    cout<<"Enter the runtimes of the processes: "<<endl;
    for(int i=0;i<n;i++){
        cin>>burst_time[i];
    }

    int timeQ;
    cout<<"Enter the time quantum for each process: "<<endl;
    cin>>timeQ;

	//calculating average time to complete the processes
	avgTime(n, processes, burst_time,timeQ);
	return 0;
}
