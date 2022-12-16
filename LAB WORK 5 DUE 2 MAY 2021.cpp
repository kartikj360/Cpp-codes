#include <iostream>

using namespace std;

int binary_search(int arr[],int s, int e,int key){
		if(s>e) return -1;

		int mid=(s+e)/2;
		if(arr[mid]==key) 
		return mid+1;
		else 
			if(arr[mid]<key) 
				binary_search(arr,mid+1,e,key);
		else 
			binary_search(arr,s,mid-1,key);
}
void sort_array(int arr[],int s)
		{
			int temp;
			for(int i=0;i<s;i++)
			{		
				for(int j=i+1;j<s;j++)
				{
					if(arr[i]>arr[j])
					{
						temp  =arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
					}
				}
			}
		}

int main() {
	
	cout<<"NO OF ELEMENTS YOU WANNA  ENTER= ";
	int n; 
	cin>>n;

	cout<<"ENTER THE ELEMENTS:-\n";
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	sort_array(arr,n);
	
	cout<<"\n\nENTER THE ELEMENT TO FIND IN THE ABOVE ENTERED ELEMENTS= ";
	int key; 
	cin>>key;

	int result=binary_search(arr,0,n-1,key);
	if(result==-1) cout<<"\n\nSORRY THE ELEMENT NOT FOUND";
	else cout<<"\n\nELEMENT FOUND AT POSITION= "<<result;

	return 0;
}

