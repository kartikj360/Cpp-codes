// By Kartik Joshi 3932
// Impelementing circular queue
#include <iostream>
using namespace std;

template <class K>
class circular_q
{
    int n, tail = 1, head = -1;
    K queue[100];

public:
    circular_q()
    {
        cout << " \n ENTER THE UPPER BOUND OF QUEUE : ";
        cin >> n;
    }

    void enqueue()
    {
        if ((tail > n && head == 1) || (tail == head - 1))
        {
            cout << " \n\n QUEUE IS ALREADY FULL..\n";
            return;
        }
        else
        {
            K value;
            cout << " \n ENTER THE VALUE TO ENQUEUE : ";
            cin >> value;
            queue[tail] = value;
            if (head != 1)
            {
                tail == n ? tail = 1 : tail++;
            }
            else
                tail++;
            head == -1 ? head = 1 : head += 0;
        }
        cout << head << " " << tail << "\n";
    }

    void dequeue()
    {

        if (head == -1 || head == tail)
        {
            cout << " \n\n QUEUE IS ALREADY EMPTY...\n";
            return;
        }
        else
        {
            queue[head] = NULL;
            head == n ? head = 1 : head++;
        }
        cout << head << " " << tail << "\n";
    }

    void display()
    {
        cout << head << " " << tail << "\n";
        if (head > tail)
        {
            for (int i = head; i <= n; i++)
            {
                if (queue[head] != NULL)
                    cout << queue[i] << " ";
            }
            for (int i = 1; i <= tail; i++)
            {
                if (queue[head] != NULL)
                    cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = 1; i < tail; i++)
            {
                if (queue[head] != NULL)
                    cout << queue[i] << " ";
            }
        }
    }
};

int main()
{

    int input, val;

    circular_q<int> user_q;
    do
    {
        cout << "\n\n1) PERFORM ENQUEUE OPERATION" << endl;
        cout << "2) PERFORM DEQUEUE OPERATION " << endl;
        cout << "3) DISPLAY OUR QUEUE " << endl;
        cout << "4) EXIT FROM THE PROGRAM " << endl;
        cout << " ENTER YOUR CHOICE :- ";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            user_q.enqueue();
            cout << "\n\n AFTER OPERATION :- \n";
            user_q.display();
            break;
        }
        case 2:
        {
            user_q.dequeue();
            cout << "\n\n AFTER OPERATION :- \n";
            user_q.display();
            break;
        }
        case 3:
        {
            user_q.display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (input != 4);

    return 0;
}
