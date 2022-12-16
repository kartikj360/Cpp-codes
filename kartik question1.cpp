#include<iostream>

using namespace std;

class Array{
	int numbers[];
	int size;
	public:
	 Array(int arr[],int size);//parameterised const
	 Array(){
		    	
		}
         Array (Array &p);//copy const 
         Array operator + (Array p)
         {
	     Array add;
		for(int i=0;i<size;i++){
			add.numbers[i]=numbers[i]+p.numbers[i];
		}
		return add;
	}	 
void toshow()//display function
{
	for(int j=0;j<size;j++){
		cout<<numbers[j]<<endl;
	}
}	
};//class closed
  Array::Array(int ar[],int size)//defination out side the class
          {
			for(int x = 0 ;x < size; x++)
            {
				numbers[x] = ar[x];
			}
		}
     Array::Array (Array &p)//defination outside the class
     {
         	for(int y = 0 ;y<p.size;y++){
         		numbers[y]=p.numbers[y];
			 }
		 }
		 
int main()//main start
{
int o;	
cout<<"Enter the no. of values to be entered in array";
cin>>o;
int arr[o];//creating array of user defined size
cout<<"Enter the no. one by one"<<endl;
for (int t=0;t<o;t++){
	cin>>arr[t];
	cout<<endl;
}	 
Array first(arr,o);//its a 'o' not a zero
Array second(first);
Array addit;
addit=first+second;//using of overloaded function
addit.toshow();
	return 0;
}