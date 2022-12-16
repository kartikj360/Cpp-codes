// C++ program to implement Shortest Job first with Arrival
// Time
//BY KARTIK JOSHI 3932
#include <iostream>
using namespace std;
int matrx[10][6]; //predefined matrix to store data

void swap(int *a, int *b) //function to swap the data of processes
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrange(int num, int matrx[][6])  //function to arrange the process on the bases of smallest job 
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (matrx[j][1] > matrx[j + 1][1])
            {
                for (int k = 0; k < 5; k++)
                {
                    swap(matrx[j][k], matrx[j + 1][k]); //swap the smaller process 
                }
            }
        }
    }
}

void calculation(int num, int matrx[][6])   //calculation of diffrent process
{
    int temp, val;
    matrx[0][3] = matrx[0][1] + matrx[0][2];       //x=arrival + burst is stored in a variable
    matrx[0][5] = matrx[0][3] - matrx[0][1];       //turn around time=x-arrival time
    matrx[0][4] = matrx[0][5] - matrx[0][2];       //waiting time=turn around time -burst time

    for (int i = 1; i < num; i++)
    {
        temp = matrx[i - 1][3];                //storing in a temp variable
        int low = matrx[i][2];
        for (int j = i; j < num; j++)
        {
            if (temp >= matrx[j][1] && low >= matrx[j][2])  //comparing first and elemnt before it
            {
                low = matrx[j][2];                        //setting low as the value of matrix[j][2]
                val = j;                                //setting val=j
            } 
        }
        matrx[val][3] = temp + matrx[val][2];              //x=temp+burst time
        matrx[val][5] = matrx[val][3] - matrx[val][1];       //turnaround time=x-arrival time
        matrx[val][4] = matrx[val][5] - matrx[val][2];       //waiting time =tat-burst time
        for (int k = 0; k < 6; k++)
        {
            swap(matrx[val][k], matrx[i][k]);              //swaping the values
        }
    }
}

int main()
{
    int num, temp;                                     //number of processes and temp variable
    double avgwt=0,avgtat=0;
    cout << "ENTER THE NUMBER OF PROCESS TO BE EXECUTED:- ";
    cin >> num;                                        //number of processes

    cout << "ENTER THE PROCESS ID :\n";
    for (int i = 0; i < num; i++)
    {
        cout << "PROCESS NO. " << i + 1 << "...\n";
        cout << "PROCESS ID: ";
        cin >> matrx[i][0];                              //process id of the process
        cout << "ENTER THE ARRIVAL TIME: ";
        cin >> matrx[i][1];                              //process's arrival time
        cout << "ENTER THE BURST TIME: ";
        cin >> matrx[i][2];                              //burst time of process
    }

    cout << "BEFORE ARRANGE\n";                     //displaying the current matrix
    cout << "PROCESS\tARRIVAL TIME\tBURST TIME\n";
    for (int i = 0; i < num; i++)
    {
        cout << matrx[i][0] << "\t\t" << matrx[i][1] << "\t\t"
             << matrx[i][2] << "\n";
    }

    arrange(num, matrx);                           //arranging the data 
    calculation(num, matrx);                           //calulating the values
    cout << "COMPELETED RESULT\n";                        //displaying the process chart
    cout << "PROCESS ID\tARRIVAL TIME\tBURST TIME\tWAITING "
            "TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < num; i++)
    {
        cout << matrx[i][0] << "\t\t" << matrx[i][1] << "\t\t"
             << matrx[i][2] << "\t\t" << matrx[i][4] << "\t\t"
             << matrx[i][5] << "\n";
        avgwt+=matrx[i][4];
        avgtat+=matrx[i][5];


    }
    cout<<"AVERAGE WAITING TIME ="<<avgwt/num<<endl;
    cout<<"AVERAGE TURN AROUND TIME ="<<avgtat/num<<endl;


}