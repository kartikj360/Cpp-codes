//3912 Pushpender binary search
#include <iostream>
using namespace std;

int binarySearch(int[], int, int, int); 

int main() 
{ 
  int arr[15] = {10, 15,18, 20, 22, 25, 28, 29, 30, 35, 36, 39, 42, 47, 50}; 
  int search_element, location=-1;

  cout<<"Enter the element which you want to search: "; 
  cin>>search_element;

  location = binarySearch(arr, 0, 14, search_element); 

  if(location != -1) 
  { 
    cout<<"Search element found at "<<location<<" location"; //Printing the result.
  } 
  else 
  { 
    cout<<"Search element not present"; 
  } 
  return 0;
} 

int binarySearch(int a[], int left, int right, int search_element) 
{ 
  int middle; 
  if(right >= left) 
  { 
    middle = (left + right)/2; 
    if(a[middle] == search_element) //Checking if elemnet is present at middle.
    { 
      return middle+1; 
    } 
    else if(a[middle] < search_element) //Checking if elemnet is present in greater half.
    { 
      return binarySearch(a,middle+1,right,search_element); 
    } 
    else //Checking if elemnet is present in samller half.
    { 
      return binarySearch(a,left,middle-1,search_element); 
    }

  } 
  return -1; 
}

