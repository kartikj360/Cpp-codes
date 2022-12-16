// By Kartik Joshi
// Impelementing circular link list 
#include <iostream>
#include <stdio.h>
using namespace std;

template <class K>
class node
{
public:
    K data;
    node<K> *next;

    node(K val)
    {
        data = val;
        next = NULL;
    }
};

template <class T>
class circular_link_list
{
public:
    void insrtbeg(node<T> *&user_ll, T val)
    { 
        node<T> *n = new node<T>(val);

        if (user_ll == NULL)
        {
            n->next = n;
            user_ll = n;
            return;
        }
        node<T> *temp = user_ll;

        while (temp->next != user_ll)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = user_ll;
        user_ll = n;
    }
    void insrtend(node<T> *&user_ll, int val)
    { 

        node<T> *n = new node<T>(val);
        node<T> *temp = user_ll;

        while (temp->next != user_ll)
        {
            temp = temp->next;
        }

        temp->next = n;
        n->next = user_ll;
    }
    void insrtafter(node<T> *&user_ll, T new, T val)
    { 

        node<T> *n = new node<T>(new); 

        node<T> *ptr = user_ll;

        if (user_ll == NULL)
        { 
            user_ll = n;
            return;
        }

        while (ptr->data != val)
        { 

            ptr = ptr->next;
            if (ptr->next == NULL)
            { 
                cout << "\nValue not found!" << endl;
                return;
            }
        }

        n->next = ptr->next;
        ptr->next = n;
    }

    void insrtbefore(node<T> *&user_ll, T new, T val)
    {                                     
        node<T> *n = new node<T>(new); 

        node<T> *ptr = user_ll; 

        if (user_ll == NULL)
        { 
            user_ll = n;
            return;
        }

        while (ptr->next->data != val)
        { 
            ptr = ptr->next;
            if (ptr->next == NULL)
            {
                cout << "\nValue not found!" << endl;
                return;
            }
        }

        n->next = ptr->next;
        ptr->next = n; 
    }
    void dltatbeg(node<T> *&user_ll)
    { 
        node<T> *temp = user_ll;

        while (temp->next != user_ll)
        {
            temp = temp->next;
        }

        node<T> *del = user_ll;
        temp->next = user_ll->next;
        user_ll = user_ll->next;

        free(del);
    }

    void dlt(node<T> *&user_ll, int pos)
    { 
        if (pos == 1)
        { 
            dltatbeg(user_ll);
            return;
        }

        node<T> *temp = user_ll;
        int count = 1;

        while (count != pos - 1)
        {
            temp = temp->next;
            count++;
        }

        node<T> *del = temp->next;
        temp->next = temp->next->next;

        free(del);
    }
    void display(node<T> *user_ll)
    {
        node<T> *temp = user_ll;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != user_ll);
        cout << endl;
    }
};

int main()
{
    int input;
    circular_link_list<int> cll;
    node<int> *user_ll = NULL;

    do
    {
        cout << "\n\t\t\t\tChoose the operation you want to perform:\n \n";
        cout << "1.Insert at begining \n";
        cout << "2.Insert at end \n";
        cout << "3.Insert after a value \n";
        cout << "4.Insert before a value \n";
        cout << "5.Delete from begining \n";
        cout << "6.Delete from some Position  \n";
        cout << "7.Exit" << endl;
        int input;
        cout << "\nEnter choice: ";
        cin >> input;

        switch (input)
        {
        case 1:
        {
            cout << "\nEnter a value to insert: ";
            int val;
            cin >> val;
            cll.insrtbeg(user_ll, val);
            cout << "\nLinkedlist after insertion:" << endl;
            cll.display(user_ll);
            break;
        }
        case 2:
        {
            cout << "\nEnter a value to insert: ";
            int val;
            cin >> val;

            cll.insrtend(user_ll, val);
            cout << "\nLinkedlist after insertion:" << endl;
            cll.display(user_ll);
            break;
        }
        case 3:
        {
            cout << "\nEnter a value to insert: ";
            int new;
            cin >> new;

            cout << "\nEnter the value after which you want to insert: ";
            int val;
            cin >> val;

            cll.insrtafter(user_ll, new, val);
            cout << "\nLinkedlist after insertion:" << endl;
            cll.display(user_ll);
            break;
        }
        case 4:
        {
            cout << "\nEnter a value to insert: ";
            int new;
            cin >> new;

            cout << "\nEnter the value before which you want to insert: ";
            int val;
            cin >> val;

            cll.insrtbefore(user_ll, new, val);
            cout << "\nLinkedlist after insertion:" << endl;
            cll.display(user_ll);
            break;
        }
        case 5:
        {
            cll.dltatbeg(user_ll);
            cout << "\nLinkedlist after dlt:" << endl;
            cll.display(user_ll);
            break;
        }
        case 6:
        {
            cout << "\nEnter a position to delete the node: ";
            int pos;
            cin >> pos;

            cll.dlt(user_ll, pos);
            cout << "\nLinkedlist after dlt:" << endl;
            cll.display(user_ll);
            break;
        }

        case 7:
        {
            return 0;
        }
        default:
        {
            cout << "\ninvalid choice!";
        }
        }
    } while (input != 7);

    return 0;
}
