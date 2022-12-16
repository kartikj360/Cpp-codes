// By Kartik Joshi 3932
// Implementing of stack 
#include <iostream>
using namespace std;

template <class K>
class stacks
{
    int n, top = -1;
    K stack[100];

public:
    stacks()
    {
        cout << " \n ENTER THE UPPER BOUND OF STACK :- ";
        cin >> n;
    }

    void push(K val)
    {
        if (top >= n - 1)
            cout << "\n\nStack Overflow" << endl;
        else
        {
            top++;
            stack[top] = val;
        }
    }

    void pop()
    {
        if (top <= -1)
            cout << "\n\nSTACK UNDERFLOW" << endl;
        else
        {
            cout << "\n\VALUE " << stack[top] << endl;
            top--;
        }
    }

    void display()
    {
        if (top >= 0)
        {
            cout << "\n\nSTACK ELEMENTS ARE:";
            for (int i = top; i >= 0; i--)
                cout << stack[i] << " ";
            cout << endl;
        }
        else
            cout << "\n\nSTACK EMPTY";
    }
};

int main()
{

    int INPUT, val;

    stacks<int> USER_STACK;
    do
    {
        cout << "\n\n1) PUSH OPERATION" << endl;
        cout << "2) POP OPERATION " << endl;
        cout << "3) DISPLAY STACK " << endl;
        cout << "4) EXIT  " << endl;
        cout << " ENTER INPUTOICE :- " << endl;
        cin >> INPUT;
        switch (INPUT)
        {
        case 1:
        {
            cout << " ENTER THE VALUE: ";
            cin >> val;
            USER_STACK.push(val);
            break;
        }
        case 2:
        {
            USER_STACK.pop();
            break;
        }
        case 3:
        {
            USER_STACK.display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } while (INPUT != 4);

    return 0;
}
