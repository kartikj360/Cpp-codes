//check if the linked list is a Palindrome or not.

//done by KARTIK JOSHI 3932
#include <iostream>
using namespace std;

class Node
{ //class Node is defined
public:
    int data;   //data part(or information part) of Node
    Node *link; //link par(or address part) of Node

    Node()
    {                //default constructor
        data = NULL; //data part initialized
        link = NULL; //address part initialized to NULL
    }
};

void display(Node *save)
{                   //display function to display elements and address of elements in memory
    Node *S = save; //saving the start of the linked list
    cout << "\n  List elements are below\n\t\t";
    while (S != NULL)
    { //traversal loop
        cout << "  " << S->data << "  ";
        S = S->link;
    }
    cout << "\n\n\n";
}

void insertend(Node *start)
{                         //insertion function for insertion of element at end
    Node *n = new Node(); //new Node
    n->link = NULL;
    Node *S = start; //saving the start of the linked list
    int value;
    cout << "Enter the value You want to add in the list :- ";
    cin >> n->data; //user input for data value of new Node
    if (S == NULL)
    {
        start = n;
    }
    else
    {
        while (S->link != NULL)
        { //traversal loop to reach end of list
            S = S->link;
        }
    }
    S->link = n;
}

Node *reverseList(Node *temp)
{
    Node *current = temp;
    Node *previous = NULL, *next = NULL;

    //Swap the previous and next Nodes of each Node to reverse the direction of the list
    while (current != NULL)
    {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    return previous;
}

//checkpalindrome() will determine whether given list is palindrome or not.
void checkpalindrome(Node *head)
{
    Node *current = head;
    bool flag = true;

    //Reverse the list after middle Node to end
    Node *revHead = reverseList(current->link);

    //Compare elements of list to its reversed list
    while (head != NULL && revHead != NULL)
    {
        if (head->data != revHead->data)
        {
            flag = false;
            break;
        }
        head = head->link;
        revHead = revHead->link;
    }

    cout << "\n\n\t\t==========================\n ";
    cout << "\t\t     Result   \n";
    cout << "\t\t==========================\n";

    if (flag)
        cout << "Given singly linked list is a palindrome\n";
    else
        cout << "Given singly linked list is not a palindrome\n";
}
int main()
{
    //Add Nodes to the list
    Node *p1 = new Node(); //1st element of list before any function
    Node *p2 = new Node();
    cout << "\n\t\tPAlINDROME IN LINKED LIST CHECKER\n";
    cout << "\n\nEnter the value of 1st element :- ";
    cin >> p1->data; //user input for data value of 1st element
    Node *Start = new Node();
    Start->link = p1; //START pointer Node with data = null
    int l;
    char c = 'n';
    cout << "\t\t\tDo you wanna add more elements in the list ??\n\t\t\tPress y for yes:- ";
    cin >> c;
    while (c == 'y')
    {                     //user input loop for more element he/she wants enter
        insertend(Start); //AS always new element add in ending so insertion at end function called
        cout << "\t\t\tDo you wanna add more elements in the list ??\n\t\t\tPress y for yes:- ";
        cin >> c;
    }

    display(p1); //display of entered linked list

    //Checks whether given list is palindrome or not
    checkpalindrome(p1);
    // display(p1);

    return 0;
}
