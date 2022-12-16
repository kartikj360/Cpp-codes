//By Kartik Joshi 3932
#include <iostream>
#include <windows.h>

#define inc(y) y = (y + 1) % 2;                  //predefining the value of y,that will increment the squence no.

using namespace std;

typedef struct
{
    int data;
} packets;                                      //defining packets

typedef struct
{
    int sequence;
    int acknowledge;
    packets *info;
} frames;                                     //defining frame 

int evnt;
int flag = 0;                                 //for acknowledgement
int sucs;                                     //to confirm if recived
int tmp = -1;   
frames x;                                     //frame to send data
packets buf;                                  //to store data for tempory work
int y = 0;

void netlayerin(packets *p)                   //to set the new squence of the given packet
{
    x.info = p;
    x.sequence = inc(y);
}

void phylayerout(frames *f)                   //to take a frame and print
{
    cout << "\n\t\tDATA : " << f->info->data;
    cout << "\n\t\tSEQUENCE NO. : " << f->sequence;
    cout << "\n\t\tFRAME SENT...";
}

void phylayerin(frames *f)                     //to take a frame and display the info
{
    cout << "\n\n\nRECEIVER : \tFRAME RECIVED.";
    cout << "\n\t\tDATA : " << f->info->data;
    cout << "\n\t\tSEQUENCE NO. : " << f->sequence;
    x.acknowledge = (x.sequence + 1) % 2;
}

void netlayerout(packets *p)                    //to take the packet info
{
    p = x.info;
}

void sending()                                 //sending the packet
{
    if (flag == 0)                             //taking buffer from network layer
    {
        netlayerin(&buf);   
        cout << "\n\n\nSENDER : \tSENDING FRAME...";
        phylayerout(&x);                           //printing the info of flag
    }
    else if (flag == 1)                            //if flag is not zero ,data is not reciceved or lost in the path
    {
        cout << "\n\n\nSENDER : \tTIMEOUT... NO ACK RECIVED."
             << "\n\n\t\tRESENDING FRAME...";
        phylayerout(&x);                            //we resend the frame
    }
    else
    {
        cout << "\n\n\nSENDER : \tACK" << x.acknowledge << " RECIVED SUCCEFULLY."; //send sucessfully
        sucs = 1;                                   //recived
        tmp = -1;
        flag = 0;                                   //send the next frame
    }
}

void recieving()
{
    evnt = rand() % 4;                               //to genrate random
    cout << "\n<EVENT " << evnt << ">\n";
    if (evnt == 0)                                   //checking the issues
    { 
        if (tmp == x.acknowledge)                   //if both are same frame
            cout << "\n\n\nRECEIVER : \tDUPLICATE FRAME RECIVED (FRAME DISCARDED)";
        else
        {
            phylayerin(&x);                         //we have recived the frame
            netlayerout(&buf); 
        }
        cout << "\n\n\t\tACK  " << x.acknowledge << " SENT."; //data is send by this side
        flag = 2;                                    //flag to repersent the data is sent
    }
    else if (evnt == 1 || evnt == 2)
    {
        flag = 1;
    }
    else
    {
        if (tmp == x.acknowledge)                      //the data is already at reciver end but the ackpwledgment is not sucefuly recived
            cout << "\n\n\nRECEIVER : \tDUPLICATED FRAME RECIVED (FRAME DISCARDED)";
        else
        {
            phylayerin(&x);
            netlayerout(&buf);
            tmp = x.acknowledge;
        }
        cout << "\n\n\t\tACK  " << x.acknowledge << " SENT.";
        flag = 1;
    }
}

int main()
{
    int data[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //taking array with 15 data
    for (int i = 0; i < 15; i++)                                       //taking one by one
    { 
        buf.data = data[i];                                             //putting into bufer
        while (true)
        {
            sucs = 0;                                                    //pre set sucess as 0
            sending();                                                   //packet is send
            cout<<"\n================\n";
            // Sleep(800);                                                 // to slow down the program
            if (!sucs)
            {
                recieving();                                             //reciveing by the end
                cout<<"\n----------------------\n";
            }   
            else
                break;
        }
    }
    return 0;
}