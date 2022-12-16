
// C++ program to implement Shortest Job Scheduled First(Non Premptive version)
/*
pid =process Id
at=arrival time
wt= Wait time
tat= Turn around time
bt= Brust time
n= Number of processes
terminated_Process= no of process completed
min_t= least remained brust time
burst_t=duplicate brust time

*/
#include <bits/stdc++.h>
using namespace std;
 //Class to Create process
class Process 
{
	public:
		
    int pid; // Process ID
    int bt; // Burst Time
    int at; // Arrival Time
    
    //functions
    void findWaitingTime(Process processes[], int n, int wt[]);
    void findTurnAroundTime(Process processes[], int n, int wt[], int tat[]);
    void findavgTime(Process processes[], int n);
    
};
 
// Function to find the waiting time
void Process::findWaitingTime(Process processes[], int n, int wt[])
{
	int brust_t[n];
 
    // at begninning remain brust time =brust time
    for (int i = 0; i < n; i++)
    
        brust_t[i] = processes[i].bt;
    
 
    int terminated_Process = 0, cur_time = 0, min_t = INT_MAX;
    int least = 0;
    bool check = false;
 
    // Process until all processes gets
    // completed
    while (terminated_Process != n) 
	
	{
 
        // Find process with minimum remaing brust time 
        for (int j = 0; j < n; j++) 
		{
            if ((processes[j].at <= cur_time) && (brust_t[j] < min_t) && brust_t[j] > 0) 
			{
                min_t = brust_t[j];
                least = j;
                check = true;
            }
        }
 		// if any process is not available to execute
        if (check == false) 
		{
            cur_time++;
            continue;
        }
        cur_time+=brust_t[least];
        brust_t[least]=0;
        min_t = brust_t[least];
        	//If process terminated
        	if (min_t == 0)
            	min_t = INT_MAX;
        // Calculating waiting time
        wt[least] = cur_time - processes[least].bt - processes[least].at;
        terminated_Process++;
        
 
        
 
    }
}
 
// Function to calculate turn around time
void Process::findTurnAroundTime(Process processes[], int n, int wt[], int tat[])
{
    // Calculating turnaround time by adding
    // turn around time= brust time + waiting time
    for (int i = 0; i < n; i++)
    
        tat[i] = processes[i].bt + wt[i];
}
 
// Function to calculate average waiting and turn around time
void Process::findavgTime(Process processes[], int n)
{
    int wt[n], tat[n], total_wt = 0,total_tat = 0;
 
    // Invoking functions to find waiting and turn around time
    findWaitingTime(processes, n, wt);
 
    findTurnAroundTime(processes, n, wt, tat);
 
    cout<<"Processes ";
    cout<<" Burst time ";
    cout<<" \tArivial time";
    cout<<" \tWaiting time ";
    cout<<" Turn around time\n";
 
    // Calculating total waiting time and turnaround time
    for (int i = 0; i < n; i++) 
	{
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        
        cout<<" "<<processes[i].pid <<"\t\t";
        cout<<processes[i].bt<<"\t\t "<<processes[i].at;
        cout<<"\t\t "<<wt[i]<<"\t\t "<<tat[i]<<endl;
    }
 
    cout<<"\nAverage waiting time = "<<(double)total_wt/(double)n;
    cout<<"\nAverage turn around time = "<<(double)total_tat/(double)n;
}
 
// Driver code
int main()
{
	//Taking number of processes from user
    cout<<"Enter the number of Processes: ";
    int n;
    cin>>n;

	Process processes[n];
	Process P;
	//Taking process ID, brust time and arrival time from user
	for(int i=0;i<n;i++)
	{
		cout<<"\nData For Process "<<(i+1)<<"\n";
		cout<<"\nEnter the process ids: "<<endl;
        cin>>processes[i].pid;
        cout<<"Enter the runtime of the process: "<<endl;
        cin>>processes[i].bt;
        cout<<"Enter the value of arrival time\n";
        cin>>processes[i].at;
    }
	
        
    P.findavgTime(processes, n);
    return 0;
}
