//Done by Kartik Joshi 3932
#include<iostream>
using namespace std;

struct process{
	public:
		int burstTime;
		int priority;
		int waitTime;
		int turnAroundTime;
		
		void input(int i){
			cout<<"\n\nEnter burst time/run time of process for the system-> "<<i+1<<" : \n";
			cin>>burstTime;
			cout<<"\n\nEnter priority of process to be run -> "<<i+1<<" : \n";
			cin>>priority;
			waitTime=0;
			turnAroundTime=0;
		}
		
		static void sort(process *p,int n){
			int minpos=0,temp=0;
			for(int i=0;i<n-1;i++){
				minpos=i;
				for(int j=i+1;j<n;j++){
					if(p[minpos].priority>p[j].priority){
						minpos=j;
					}
				}
				temp=p[i].priority;
				p[i].priority=p[minpos].priority;
				p[minpos].priority=temp;
				
				temp=p[i].burstTime;
				p[i].burstTime=p[minpos].burstTime;
				p[minpos].burstTime=temp;
			}
			
		}
		
		static float findWaitTime(process *p,int n){
			p[0].waitTime=0;
			float totalWaitTime=0;
			for(int i=1;i<n;i++){
				p[i].waitTime=p[i-1].waitTime+p[i-1].burstTime;
				cout<<endl<<p[i].waitTime;
				totalWaitTime+=p[i].waitTime;
			}
			return totalWaitTime/n;
		}
		
		static float findTurnAroundTime(process *p,int n){
			float totalTurnAroundTime=0;
			
			for(int i=0;i<n;i++){
				p[i].turnAroundTime=p[i].waitTime+p[i].burstTime;
				totalTurnAroundTime+=p[i].turnAroundTime;
			}
			
			return totalTurnAroundTime/n;
		}
};

int main(){
	int n=0;
	cout<<"\n \nEnter the number of processes ->\n";
	cin>>n;
	process p[n];
	for(int i=0;i<n;i++){
		p[i].input(i);
	}
	process::sort(p,n);
	float avgWaitTime=process::findWaitTime(p,n);
	float avgTurnAroundTime=process::findTurnAroundTime(p,n);
	
	cout<<"\nRUN TIME                                         PRIORITY\n";
	for(int i=0;i<n;i++){
		cout<<"\n            "<<p[i].burstTime<<"                                             "<<p[i].priority;
	}
	
	cout<<"\nAVERAGE TURN AROUND TIME IS -> "<<avgTurnAroundTime<<endl;
	cout<<"\nAVERAGE WAITING TIME IS -> "<<avgWaitTime<<endl<<endl;
	
	return 0;
}