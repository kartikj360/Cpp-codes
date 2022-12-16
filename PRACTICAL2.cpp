#include <iostream>
using namespace std;

int bnsrch(int arr[], int y, int strt, int lst)
{
 int mid;
 
 if (strt > lst)
 {
  
  cout << "not found";
  return 0;
  
 } else
  {
  
  mid = (strt + lst) / 2;
  
  if(arr[mid] == y)
  {
   
   cout << "Number is found at " << mid+1 << " index \n";
   return 0;
  
  } else 
  if (y > arr[mid])
   {
   
   bnsrch (arr, y, mid+1, lst);
   
  } else
   if (y < arr[mid]) 
   {
   
   bnsrch (arr, y, strt , mid-1);
  }
 }
 
 
}
 
int main() 
{
 
 int arr[100], y, i, n, strt, lst;
 
 cout <<"Enter the size of an array  \t";
 cin >> n;

 
 for(i=0; i<n; i++) 
 {
  cout<<"Enter the ["<<i+1<<"]value of array index\t";
  cin >> arr[i];
 }
 
 cout <<"Enter a value to be search \n";
 cin >> y;
 
 strt = 0;
 lst = n-1;
 
 bnsrch (arr, y, strt, lst);
 
 return 0;
}