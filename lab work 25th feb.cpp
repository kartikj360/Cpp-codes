#include<iostream>
using namespace std;

class Person{
	protected:
		string name;
	public:
		void input()
		{
			cout<<"Enter Name --";
			getline(cin,name);
		}
		void display()
		{
			cout<<"\nName in base class(person) :- "<<name;
		}
};

class Student:protected Person{
	private:
		string course;
		int marks,year;
	public:
		void input()
		{
			cout<<"Enter Name -- ";
			getline(cin,name);
			cout<<"Enter  Course -- ";
			getline(cin,course);
			cout<<"Enter Marks -- ";
			cin>>marks;
			cout<<"Enter Year -- ";
			cin>>year;
		}
		void display()
		{
			cout<<"\nName in derived class(inherited member \"name\") -- "<<name;
			cout<<"\nCourse -- "<<course;
			cout<<"\nMarks -- "<<marks;
			cout<<"\nYear -- "<<year;
		}
};

class Employee:protected Person{
	private:
		string department;
		int salary;
	public:
		void input()
		{
			cout<<"Enter Name -- ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Department -- ";
			getline(cin,department);
			cout<<"Enter Salary -- ";
			cin>>salary;
		}
		void display()
		{
			cout<<"\nName in derived class(inherited member \"name\") -- "<<name;
			cout<<"\nDepartment -- "<<department;
			cout<<"\nSalary -- "<<salary;
		}
};

int main()
{
	Person P1;
	Student S1;
	Employee E1;
	cout<<"Entry in Base class :- \n";
	P1.input();
	cout<<"Entry in derived Student Class :- \n";
	S1.input();
	cout<<"Entry in derived Employee Class :- \n";
	E1.input();
	
	cout<<"\n\nEnteries in Base Class\n";
	P1.display();
	cout<<"\n\nEnteries in Derived Student Class\n";
	S1.display();
	cout<<"\n\nEnteries in Derived Employee Class\n";
	E1.display();
	
	return 0;
}