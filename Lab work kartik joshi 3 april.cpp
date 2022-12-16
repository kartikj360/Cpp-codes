#include<iostream>
#include<math.h>
using namespace std;
bool ismember(char a[],int s,char f);
void powerset(char *set, int set_size)
{
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    for(counter = 0; counter < pow_set_size; counter++)
    {
    	cout<<"{";
    	for(j = 0; j < set_size; j++)
    	{
    	    if(counter & (1 << j))
    	        cout <<set[j];
    	}
    	cout<<"}"<<endl;
    }
}
int main()
{
	int size,count=0,n=1;

	cout<<"Enter the size of array:- ";
	cin>>size;
	char seta[size],temp,search;
	cout<<endl<<"Enter the "<<size<<" element in set :- \n";
	for(int i=0;i<size;i++)
	{
		cin>>seta[i];
	}
	for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(seta[i]>seta[j])
			{
				temp  =seta[i];
				seta[i]=seta[j];
				seta[j]=temp;
			}
		}
	}
	for(int i=0;i<size;i++)
	{	
			
		cout<<n;
		if(seta[i]!=seta[n])
			count++;
		n++;	
	}
	cout<<"Entered set in order is :- \n{";
	for(int i=0;i<size;i++)
	cout<<seta[i];
	cout<<"}";
	cout<<"\n\nCardinality of the entered set is :- "<<count;

	cout<<"\nEnter the element u wanna search :- ";
	cin>>search;
	
	cout<<"Result of the search :- "<<ismember(seta,size,search);
	cout<<"\n\n\nElements in Power set :- \n";
	powerset(seta,size);
	return 0;
}
bool ismember(char a[],int s,char f)
{
	int flag=0;
	a[s];
	for(int i=0;i<s;i++)
	{
		if(a[i]==f)
		flag++;
	}
	if(flag)
	return true;
	else 
	return false;
}
