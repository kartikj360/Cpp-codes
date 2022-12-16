#include <iostream>
// #include <cmath>
// #include <string>
// #include <fstream>
// #include <stdio.h>
// #include <conio.h>
// #include <ctime>
// #include <fstream>
#include "HEK1.h"



int main()
{   
	system("color F5"); //setting background white and text color purple
	Customer cs1;      //customer object creation
	Taxi t1;           // taxi object creation
	Flight f1;         //flight object creation
	Hotel h1;          //hotel object creatioin
	int input = 1;    // input for do while loop
	int k, x, n, uid,z;
	// settextstyle(4,0,4);
	// outtextxy(5,10,);
	// string *quote;
	
	cout<<"\n\n\n\n\t\t\t\t\tOnce a year, go someplace you've never been before-\n";
	 cout<<"\t\t\t\t\t\t\t\t\t\tDalai Lama";
	 cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\tPress any key to continue!!";
				getch();
				system("color 07");
				
	system("CLS");
	cout << "\n\n\t \t \t \t Welcome to HEK Travellers \n"<< endl<< endl;
	cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
	cout << "\t   Book your  tickets at affordable prices!" << endl;
	cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>";
	cout << "Select your desirable option:-\n";
	cout << "1.New user\n";
	cout << "2.User login \n";
	cin >> n;
	switch (n)
	{
	case 1:
	{ 
		cs1.getuserdetails();
		createfile_c(cs1);
		f1.userid=cs1.userid;
		h1.userid=cs1.userid;
		t1.userid=cs1.userid;
        cout<<f1.userid;
        cout<<h1.userid;
        cout<<t1.userid;
		uid=f1.userid;
		break;
	}
	case 2:
	{
		cout << "Enter user id  : ";
		cin >> uid;
		
		int f = 0;
		ifstream fout("Customer.dat", ios::binary); //opening file
		fout.read((char *)&cs1, sizeof(cs1));		//reading file
		while (fout)
		{
			cout<<cs1.userid;
			if (cs1.getuserid() == uid)
			{
				f1.usd(uid);
				
				f++;
				break;
			}
		fout.close();	
		}
		
		if (f == 0)
		{
			int N;
			cout << "User not found \n";
			cout << "Press any key\n";
			getch();
			return main();
		}
		else
		{
			cout << "Success \t User found!!!!\n";
			cout << "Press any key......";
			getch();
		}
		
		// cs1.getuserid()=uid;
	}
	}

	do
	{
		int i, n, choice;
		system("CLS");
	start:
		cout << "We will provide you with one of the best world class Airline!! :) \n";
		cout << "Please select the desireble option \n";
		cout << "\t\t\t1.Book flight \n";
		cout << "\t\t\t2.Check status of your flight \n";
		cout << "\t\t\t3.Make changes in flight booking \n";
		cout << "\t\t\t4.Cancel the flight booking \n";
		cout << "\t\t\t5.In flight services(extra paid) \n";
		cout << "\t\t\t6.Taxi Services \n";
		cout << "\t\t\t7.Hotel services \n";
		cout << "\t\t\t8.Update or make changes in the given user informations \n";
		cout << "\t\t\t9.Checkout \n";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			f1.flightBook();
			
			createfile_f(f1);
			break;
		}

		case 2:{
			checkflight(uid);
			break;
		}
		case 3:
		{
			f1.flightupdate(uid);
			break;
		}

		case 4:
		{
			flightcancel(uid);
			break;
		}

		case 5:
		{

			f1.inflights();
			break;
		}

		case 6:
			cout << "Welcome to our very own taxi  providers \n";
			cout << "Please selct your desriable option \n";
			cout << "1.Book a taxi \n";
			cout << "2.Cancel the taxi \n";
			cin >> k;
			switch (k)
			{
			case 1:
			{
				t1.taxiselect();
				createfile(t1);
				goto start;
				break;
			}

			case 2:
			{
				canceltaxi(uid);
				goto start;
				break;
			}

			default:
			{
				break;
				cout << "Invail option selcted,Please select  a correct option" << endl;
				return main();
			}
			}

		case 7:
		{
			system("cls");
			cout << "**********************************WELCOME TO HEK HOTEL***************************" << endl;
			cout << "**************************THE FINEST HOTEL AT THE BEST PRICE************************" << endl;
			cout << "\n ";
			cout << "\n\n\n\t\t\t1.Book A Room";
			cout << "\n\n\n\t\t\t2.Avail Hotel services";
			cout << "\n\n\n\t\t\t3.Display Customer Record";
			cout << "\n\n\n\t\t\t4.Cancel Customer Record";
			cout << "\n\n\n\t\t\t5.Exit";
			cout << "\n\n\t\t\tEnter Your Choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				h1.addHotel();
				createfile_h(h1);
				break;
			}

			case 2:
			{
				h1.services();
				break;
			}
			case 3: //cout<<"Please enter the user id"<<endl;
					// 		cin>>n;
				checkhotel(uid);
				break;
			case 4:
				cancel_rec(uid);
				break;

			case 5:
				break;
			default:
			{
				cout << "\n\n\t\t\tWrong choice!!!";
				cout << "\n\t\t\tPress any key to continue!!";
				getch();
			}
			}
		}
		break;
		case 8:
			cs1.Updateuser(uid);
			break;
		case 9:
			checkcustomer(uid);
			checkflight(uid);
			checkhotel(uid);
			checktaxi(uid);
			total(uid);
			cout<<"We will now take to payment menu\n";
			payment();
			input=0;
			break;
		default:
		{
          
			cout << "Invaild option,Please select the correct option \n";
		}
			
		}
		cout<<"\n\nDo you want to exit...If so press any number other then 1";
		cin>>input;
		
	} while (input == 1);
	//if(input=='y'||input=='Y')
	//	goto start;

	return 0;

}



