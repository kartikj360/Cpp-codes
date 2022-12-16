#include<iostream>
using namespace std;
int main()
{
    int v;
    int OutDegree=0,InDegree=0;
    cout<<"Enter the number of vertices of graph ";
    cin>>v;
    int graph[v][v];
    cout<<"Enter the values of adjacency matrix of Graph"<<endl;
    for (int i = 0; i < v; i++)
    {
        char r= 97+i;
        for (int j = 0; j < v; j++)
        {
            char c=97+j;
            cout<<"Enter the value of ("<<r<<","<<c<< ") position : ";
            cin>>graph[i][j];
        }
    }

    for (int i = 0; i < v; i++)
    {
        OutDegree=0;
        for (int j = 0; j < v; j++)
        {
            OutDegree=OutDegree+graph[i][j];
        } 
        char vertex = 97+i;
        cout<<"The Out Degree of vertex "<<vertex<<" " <<OutDegree<<endl;
    }
    // Calculating in degree
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            InDegree=InDegree+graph[j][i];
        } 
        char vertex = 97+i;
        cout<<"The In Degree of vertex "<<vertex<<" "<< InDegree<<endl;
        InDegree=0;
    }  
     return 0;
}
