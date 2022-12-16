// Done by Kartik Joshi 3932
#include<iostream>          //including header file
 
using namespace std;    
 
int main()              //main function
{
    int w,i,f;
 	
 	cout<<"\t\t\tSliding Window Protocol \n\n";
    cout<<"\nEnter window size to be used: ";        
    cin>>w;                                     //taking input for the window size
 
    cout<<"\n\nEnter number of frames to be transmitted through: ";
    cin>>f;                                         //taking input for number of frames
    int frames[f];

    cout<<"\nEnter "<<f<<" number of frames: ";
 
    for(i=0;i<f;i++)                            //taking input of values in frames
        cin>>frames[i];             
 
    
    for(i=0;i<f;i++)                            //loop for showing the working of code
    {
        if((i+1)%w==0)                              
        {
            cout<<"   "<<frames[i]<<" <====frames sent\n\n";
            cout<<"Waiting for Acknowledgement to be recivesd\n\n";
            cout<<"Acknowledgement of above frames sent is received by sender succesfully\n\n";
        }
        else
            cout<<"   "<<frames[i];
    }
 
    if(f%w!=0)
        cout<<"\nWaiting for Acknowledgement to be recived \n\n";
        cout<<"Acknowledgement of above frames sent is received by sender sucefully\n\n";
 
    return 0;
}