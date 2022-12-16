#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
int isArmStrong(int );//prototype
int main(int argc,char *argv[])
{
    int a[10],b[10],flag=0;
  ofstream fout;
  fout.open("ArmStrong1.txt",ios::out);
  
  for(int j=0;j<10;j++)
  {
  for(int i=1;i<argc;i++)
  {
   a[j]=atoi(argv[i]);
   fout<<a[j];
  }
}
  fout.close();
  ifstream fin;
  fin.open("ArmStrong1.txt",ios::in);
  for(int k=0;k<10;k++)
  {
      fin>>b[k];
  }
  
  fin.close();

  ofstream fout1;
  fout1.open("ArmStrong.txt",ios::out);

for(int p=0;p<10;p++)
{
    flag=isArmStrong(b[p]);
    if(flag==0)
        {
        fout1<<b[p];
        cout<<b[p]<<"Is a armstrong no. and is stored in the file";
        }
        else
        {
        cout<<b[p]<<"Is not a armstrong no.....";
        }
}
 fout1.close();
}
int isArmStrong(int p)
{
int num, originalNum, remainder, result = 0;
    p=num;
    originalNum = num;

    while (originalNum != 0) {
       // remainder contains the last digit
        remainder = originalNum % 10;
        
       result += remainder * remainder * remainder;
        
       // removing last digit from the orignal number
       originalNum /= 10;
    }

    if (result == num)
        return 0;
    else
        return 1;

}