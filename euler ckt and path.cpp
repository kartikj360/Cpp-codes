#include<iostream>
using namespace std;

int main()
{
    int n,sum_d=0,count=0;
    cout<<"Enter the size of adjacency matrix :- ";
    cin>>n;
    cout<<"\nYour entered size is  "<<n;
    bool adjmat[n][n],check;
    char r='a',c='a';
    cout<<"\n\nNow enter the values in adjacency matrix:- "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"Enter the value in index ("<<r<<","<<c<<") :-\t";
            cin>>adjmat[i][j];
            c++;
        }
        c='a';
        r++;
    }

    //check adjacency matrix is euler ckt or not

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum_d+=adjmat[i][j];
        }
        if(sum_d%2==0)
        {
            check=true;
            sum_d=0;
        }
        else
        {
            check=false;
            break;
        }
    }

    sum_d=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum_d+=adjmat[i][j];
            
        }
        if(sum_d%2==1)
            ++count;
        sum_d=0;
    }

    if(check)
        cout<<"!!YOUR GRAPH IS AN EULER CIRCUIT!!";
    else if(count==2)
            cout<<"!!YOUR GRAPH IS NOT AN EULER CIRCUIT BUT IT IS EULER PATH!!";
        else    
            cout<<"!!YOUR GRAPH IS NEITHER AN EULER CIRCUIT NOR AN EULER PATH!!";
    
    
}