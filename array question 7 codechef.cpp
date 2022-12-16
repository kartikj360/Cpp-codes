#include<iostream>
#include<stdio.h>
#include<conio.h>

 
 using namespace std;
 void reverse(int arr[],int start,int end)
{
    int y=end+1;
    while(start<end)
    {
        int a=arr[start];
        arr[start]=arr[end];
        arr[end]=a;
        start++;
        end--;
    }
    for(int q=0;q<=y;q++)
    cout<<arr[q];
}
void breakdidgit(int k)
{
    int n,p=0,o[10],m;
    while(k!=0)
    {   n=k%10;
        k=k/10;
        o[p]=n;
        p++;

    }
    m=sizeof(o)/sizeof(o[0]);
    reverse(o,0,m-1);
}

 int main
  {  
     int a[10];
	 int j;
     cin>>j;
     for(int i=0;i<=j;j++)
     {
	 
         cin>>a[i];
     }
     for(int r=0;r<=j;j++)
    {
	    breakdigit(a[i]);
    }
      return 0;
 }
 
