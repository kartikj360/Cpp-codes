
#include<iostream>
using namespace std;
int main()
{
    int x=14;
    while(x<20)
    {
        ++x;
        if(x>=16 && x<=18)
        {
            continue;
            }
            cout<<x;
    }
return 0;
}
