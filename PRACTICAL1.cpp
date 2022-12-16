#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter the number of vertices to represent in the graph: ";
    cin>>x;
    int k[x][x];
    bool check=true;
    for(int i=0;i<x;i++)
    {
        char y=112+i;
        for(int j=0;j<x;j++)
        {
            char z=112+j;
            cout<<"Enter the value of ("<<y<<","<<z<<") cell of adjacency matrix: ";
            cin>>k[i][j];
        }
    }

    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(i==j && k[i][j]!=0)
            {
        l check=false;
            }
             else if(i!=j&&k[i][j]!=1)
             {
        l check=false;
                
            }
        }
    }

    il check)
    {
        cout<<"The graph formed is a complete graph";
    }
    else
    {
        cout<<"The graph formed is a not complete graph";
    }
    return 0;
}