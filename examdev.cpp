#include<iostream>
#include<cmath>
using namespace std;

class NewFloat
{
  public:
  float floatData = 0.0;

  NewFloat() {}
  NewFloat(float a):floatData{a} {}

  inline void printData()
  {
    cout<<"Float value is: "<<floatData<<endl;
  }

  float deciData ()
  {
    int intPart = abs(floatData);
    return (floatData - intPart);
  }

  void operator ++ (int)
  {
    floatData++;
  }

  friend int operator < (const NewFloat&, const NewFloat&);

  operator int() const
  {

    return (int)floatData;
  }

};

int operator < (const NewFloat& D1, const NewFloat& D2)
  {
    if (D1.floatData < D2.floatData)
      return 1;
    else
      return 0;
  }

int main()
{
  float f,k ;
  cout<<"Enter the firstno.";
  cin>>f;
  NewFloat n1(f),n2;
  cout<<"Enter the second no.";
  cin>>k;
  n2.floatData= k;
  n1.printData();
  cout<<n2.deciData()<<endl;
  n1++;
  n2.printData();

  if(n1<n2)
    cout<<"n1 is smaller\n";
  else
    cout<<"n2 is smaller\n";

  cout<<(int)n1;
  return 0;
}
