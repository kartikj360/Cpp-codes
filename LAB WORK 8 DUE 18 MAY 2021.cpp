#include <iostream>

using namespace std;

int main() {
	
	cout<<"SPECIFY THE NUMBER OF ELEMENTS YOU ARE GOING TO ENTER:- ";
	int n;
	cin>>n;

	cout<<"NOW ENTER THE ELEMENTS:-\n";
	int elements[n];
	for (int i = 0; i < n; i++)
	{
		cin>>elements[i];
	}

	int totl=0, cnt, cn, ttl=0;
	for (int i = 0; i < n; i++)
	{
		cnt=0; cn=0;
		for (int j = 0; j < n-1; j++)
		{
			if(elements[j]>elements[j+1])
			{ 
				swap(elements[j],elements[j+1]); cnt++;
			}
			cn++;
		}
		
		cout<<"\n\nARRAY AFTER PERFORMING ALL SWAPS IN "<<i+1<<" CYCLE\n{ ";
		for (int i = 0; i < n; i++)
		{ 
			cout<<elements[i]<<" ";
		}
		
		cout<<"}\nNO OF COMPARISONS DONE IN "<<i+1<<" CYCLE IS= "<<cn<<"\n";

		cout<<"NO OF SWAPS DONE IN "<<i+1<<" CYCLE IS= "<<cnt<<endl;
		
		totl+=cnt;	ttl+=cn;
	}
	
	cout<<"\nYOUR SORTED ARRAY IS:-  { ";
	for (int i = 0; i < n; i++)
	{ 
		cout<<elements[i]<<" ";
	}
	cout<<" }";
	
	return 0;
}

