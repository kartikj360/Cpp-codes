#include<iostream>

//3912 Pushpender labwork june 08 2021

using namespace std;
int main()
{
    int i,l,m;               //i:- internal vertices; l:- Leaf nodes/leaves; m:- children in full m-ary tree
    cout<<"\t\tEnter the value of m of full m-ary tree :- \n";
    cin>>m;
    cout<<"\n\t\tEnter the no. of internal vertices i :- \n";
    cin>>i;

    l=((m-1)*i)+1;            //formula for leaf nodes

    cout<<"\n\n\t\tTotal no. of leaf nodes :- "<<l;

    return 0;
}