#include<iostream>

using namespace std;

int main() {
	int size;
	cout<<"Enter the no. of elements u wanna write :- ";
    cin>>size;

    int arr[size];
    cout<<"Enter the elements :- ";
    for(int i=0;i<size;i++) 
	cin>>arr[i];

    int no_of_comparisons=0, no_of_substitutions=0;;
    for(int i=1;i<size;i++){
        int j=i-1, temp=arr[i];

        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j]; 
			no_of_substitutions++;
            no_of_comparisons++; 
			j--;
        }
        arr[j+1]=temp; 
		no_of_substitutions++;
        no_of_comparisons++;
    }
	cout<<"Arranged elements are :- ";
    for(int i=0;i<size;i++) 
	cout<<arr[i]<<" ";

    cout<<"\n\nNUMBER OF ELEMENTS PRESENT= "<<size;
    cout<<"\n\nNUMBER OF COMPARISONS DONE= "<<no_of_comparisons;
    cout<<"\n\nNUMBER OF SUBSTITUTIONS DONE= "<<no_of_substitutions;
	return 0;
}

