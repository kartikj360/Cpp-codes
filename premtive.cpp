// Done by KARTIK JOSHI 3932
//SHORTEST JOB FIRST, PRE - EMPTIVE(WITH DIFFERENT ARRIVAL TIME)
#include <iostream>
#include <climits>
using namespace std;

class process     //CLASS DEFINED
{
public:
	int bt;		   //stores the burst time or runtime of the process
	int at;		   //stores the arrival time of the process
	int tat;	   //stores the turn around time of the process
	int wt;		   //stores the waiting time of the process
	int rbt;	   //stores the remaining burst time of the process,
				   // the process having shortest remaining burst time is executed first
	int completed; //if the process is executed, completed=0 else completed=1

	void input(int i)
	{
		cout << "\nEnter the arrival time of process " << i + 1 << "- ";
		cin >> at;
		cout << "\nEnter the burst time of process " << i + 1 << "- ";
		cin >> bt;
		rbt = bt;	   //in the beigninning before the execution starts rbt is equal to the burst time
		completed = 1; //since the process is not executed yet completed = 1
		tat = 0;
		wt = 0;
	}
};

int main()
{
	int n;
	cout << "\nEnter the number of processes - ";
	cin >> n;
	int total_time; //stores the total time for each cycle
	process p[n];
	for (int i = 0; i < n; i++)
	{
		p[i].input(i);
		total_time += p[i].bt; //total time = sum of burst time of each process
	}

	int temp = 0, min_pos = 0;
	for (int i = 0; i < n; i++)
	{ //sorting the array of processes in ascending order on the basis of arrival time
		min_pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (p[min_pos].at > p[j].at)
			{
				min_pos = j;
			}
		}
		temp = p[i].at;
		p[i].at = p[min_pos].at;
		p[min_pos].at = temp;
		temp = p[i].bt;
		p[i].bt = p[min_pos].bt;
		p[min_pos].bt = temp;
		temp = p[i].rbt;
		p[i].rbt = p[min_pos].rbt;
		p[min_pos].rbt = temp;
	}

	int current_time = 0, min = INT_MAX, idx = -1;
	while (current_time != total_time)
	{
		//when current time= total time i.e. all the processes have been executed the loop breaks
		for (int i = 0; i < n; i++)
		{
			if (p[i].rbt == 0)
			{ //checks the process with rbt = 0 ie completely executed processes
				p[i].completed = 0;
			}
		}
		min = INT_MAX; //to find the process with minimum remaining burst time at a given current time
		idx = -1;	   //stores the index of process with minimum rbt

		for (int i = 0; i < n; i++)
		{
			// for all the uncompleted processes with arrival time less than current time
			// we find the process with minimum remaining burst time and execute it for 1 unit of time*/
			if (p[i].at <= current_time && p[i].completed != 0)
			{
				if (min > p[i].rbt)
				{
					min = p[i].rbt;
					idx = i;
				}
				if (min == p[i].rbt)
				{
					if (p[i].at < p[idx].at)
					{
						min = p[i].rbt;
						idx = i;
					}
				}
			}
		}

		if (idx != -1)
		{
			p[idx].rbt -= 1; //decrementing the rbt by 1 unit of time
		}

		for (int i = 0; i < n; i++)
		{
			if (p[i].at <= current_time && p[i].completed != 0)
			{
				//turn around time is incremented in each uncompleted process with at<current time
				p[i].tat += 1;
			}
		}

		current_time++; //current time incremented by 1 unit of time
	}

	float total_tat = 0, total_wt = 0; //stores the total turn around and total waiting time
	for (int i = 0; i < n; i++)
	{
		cout << "\n"
			 << p[i].tat;
		total_tat += p[i].tat;
		p[i].wt = p[i].tat - p[i].bt;
		total_wt += p[i].wt;
	}

	cout << "\nARRIVAL TIME             BURST TIME               WAITING TIME                  TURN AROUND TIME";
	for (int i = 0; i < n; i++)
	{
		cout << "\n     " << p[i].at << "                       " << p[i].bt << "                       " << p[i].wt << "                       " << p[i].tat;
	}
	cout << "\nAverage turn around time = " << total_tat / n;
	cout << "\nAverage waiting time = " << total_wt / n;
	return 0;
}