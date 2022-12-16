#include <iostream>
using namespace std;

template <typename K>
class Node
{
public:
    K val;
    Node *next = NULL;
    static Node *HEAD;

    Node()
    {
        next = NULL;
    }

    int GETSZ()
    {

        int length = 0;

        Node<K> *TEMP_PTR = new Node<T>();
        TEMP_PTR = HEAD;

        while (TEMP_PTR != NULL)
        {

            length++;
            TEMP_PTR = TEMP_PTR->next;
        }

        return length;
    }

    int SRCH()
    {

        int LOC = 1, KEY, INDEX = -1;

        if (HEAD == NULL)
        {

            return -2;
        }

        else
        {

            cout << "\n\t\t\t\t-->ENTER THE VALUE TO FIND :- ";
            cin >> KEY;

            Node<T> *TEMP_PTR = new Node<T>();
            TEMP_PTR = HEAD;

            while (TEMP_PTR != NULL)
            {

                if (TEMP_PTR->val == KEY)
                {

                    cout << "\n--> FOUND IN THE LIST " << LOC << ". \n";
                }

                TEMP_PTR = TEMP_PTR->next;
                LOC++;
            }

            return INDEX;
        }
    }
};

Node<int> *PTR = NULL;

template <class T>
Node<T> *Node<T>::HEAD = PTR;

template <class T>
void DISPLAY(Node<T> *any_object)
{

    Node<T> *TEMP_PTR = any_object->HEAD;

    if (TEMP_PTR == NULL)
    {
        cout << "\n\t\t\t\t\t\t--> NOT FOUND IN THE LIST <-- \n";
        return;
    }

    cout << "\n\n--> UPDATED LIST <-- \n\n";

    int LOC = 1;

    while (TEMP_PTR != NULL)
    {

        cout << "VALUE AT THE NODE " << LOC << " :- " << TEMP_PTR->val << "\n";

        TEMP_PTR = TEMP_PTR->next;
        LOC++;
    }
}

//a function to insert a node at a given index either at the begining or end

template <class T>
bool INSERT(Node<T> *any_node)
{

    //a pointer which will be used furter for traversing the whole linked list

    Node<T> *TEMP_PTR = new Node<T>();

    TEMP_PTR = any_node->HEAD;

    int position_now = 1, INPUT;

    if (TEMP_PTR == NULL)
    {

        cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY <-- \n";

        cout << "\n\t\t\t\t\t    --> INSERT ONLY AT THE STARTING <-- \n";

        Node<T> *new_node = new Node<T>();

        cout << "\n\t\t\t\t--> ENTER THE VALUE AT THE NODE : ";
        cin >> INPUT;

        new_node->val = INPUT;
        new_node->next = NULL;

        new_node->HEAD = new_node;
        return true;
    }

    else
    {

        string loc;

        cout << "\n\t\t\t\t--> SPECIFY  LOCATION OF THE NODE DATA TO INSERT AS ( BEFORE/AFTER NODE DATA ): ";
        cin >> loc >> INPUT;

        if (loc == "BEFORE")
        {

            if (TEMP_PTR->HEAD->val == INPUT)
            {

                Node<T> *new_node = new Node<T>();

                cout << "\n\t\t\t\t--> ENTER THE VALUE AT THE NODE : ";
                cin >> new_node->val;

                new_node->next = new_node->HEAD;

                new_node->HEAD = new_node;
                return true;
            }

            else
            {

                while (TEMP_PTR->next != NULL)
                {

                    if (TEMP_PTR->next->val == INPUT)
                    {
                        break;
                    }

                    TEMP_PTR = TEMP_PTR->next;
                }

                //if the given node is not present we will not insert the node

                if (TEMP_PTR->next != NULL && TEMP_PTR->next->val != INPUT)
                {
                    cout << "\n\t\t\t\t--> NOT FOUND IN THE LIST <-- \n";
                    return false;
                }

                Node<T> *new_node = new Node<T>(); //a new node which will be inserted

                cout << "\n\t\t\t\t--> ENTER THE VALUE AT THE NODE : ";
                cin >> new_node->val;

                new_node->next = TEMP_PTR->next;

                TEMP_PTR->next = new_node;

                return true;
            }
        }

        else
        {

            while (TEMP_PTR->next != NULL)
            {

                if (TEMP_PTR->val == INPUT)
                {
                    break;
                }

                TEMP_PTR = TEMP_PTR->next;
            }

            //if the given node is not present we will not insert the node

            if (TEMP_PTR->val != INPUT)
            {
                cout << "\n\t\t\t\t--> NOT FOUND IN THE LIST <-- \n";
                return false;
            }

            Node<T> *new_node = new Node<T>(); //a new node which will be inserted

            cout << "\n\t\t\t\t--> ENTER THE VALUE AT THE NODE : ";
            cin >> new_node->val;

            new_node->next = TEMP_PTR->next;
            TEMP_PTR->next = new_node;

            return true;
        }
    }
}

//a function to insert a node at a given index either at the begining or end

template <class T>
bool DLT(Node<T> *any_node)
{

    //a pointer which will be used furter for traversing the whole linked list

    Node<T> *TEMP_PTR = new Node<T>();

    TEMP_PTR = any_node->HEAD;

    int position_now = 1, INPUT;

    if (TEMP_PTR == NULL)
    {

        cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY<-- \n";

        cout << "\n\t\t\t\t\t\t--> DELETION NOT POSSSIBLE <-- \n";

        return false;
    }

    else
    {

        string loc;

        cout << "\n\t\t\t\t--> SPECIFY LOCATION AS ( BEFORE/AFTER DATA ):- ";
        cin >> loc >> INPUT;

        if (loc == "BEFORE")
        {

            if (TEMP_PTR->next == NULL)
            {

                cout << "\n\t\t\t\t--> NOT FOUND <-- \n";
                return false;
            }

            else if (TEMP_PTR->next->next == NULL)
            {

                if (TEMP_PTR->next->val == INPUT)
                {

                    Node<T> *to_delete = new Node<T>();
                    to_delete = TEMP_PTR->next;

                    TEMP_PTR->next = NULL;

                    delete (to_delete);
                    return true;
                }

                else
                {

                    cout << "\n\t\t\t\t--> NOT FOUND <-- \n";
                    return false;
                }
            }

            else if (TEMP_PTR->next != NULL && TEMP_PTR->next->next != NULL)
            {

                if (TEMP_PTR->next->val == INPUT)
                {

                    Node<T> *to_delete = new Node<T>();
                    to_delete = TEMP_PTR;

                    TEMP_PTR->HEAD = TEMP_PTR->next;

                    delete (to_delete);
                    return true;
                }

                while (TEMP_PTR->next->next->next != NULL)
                {

                    if (TEMP_PTR->next->next->val == INPUT)
                    {
                        break;
                    }

                    TEMP_PTR = TEMP_PTR->next;
                }

                //if the given node is not present we will not delete the node

                if (TEMP_PTR->next->next->next == NULL)
                {
                    cout << "\n\t\t\t\t--> NOT FOUND <-- \n";
                    return false;
                }

                else if (TEMP_PTR->next->next->val != INPUT)
                {
                    cout << "\n\t\t\t\t--> NOT FOUND <-- \n";
                    return false;
                }

                Node<T> *to_delete = new Node<T>();
                to_delete = TEMP_PTR->next;

                TEMP_PTR->next = TEMP_PTR->next->next;

                delete (to_delete);
                return true;
            }
        }

        else
        {

            if (TEMP_PTR->next == NULL)
            {

                cout << "\n\t\t\t\t--> NOT FOUND <-- \n";
                return false;
            }

            TEMP_PTR = any_node->HEAD;

            while (TEMP_PTR->next->next != NULL)
            {

                if (TEMP_PTR->val == INPUT)
                {
                    break;
                }

                TEMP_PTR = TEMP_PTR->next;
            }

            //if the given node is not present we will not insert the node

            if (TEMP_PTR->val != INPUT)
            {
                cout << "\n\t\t\t\t--> NOT FOUND <-- \n";
                return false;
            }

            Node<T> *to_delete = new Node<T>();
            to_delete = TEMP_PTR->next;

            TEMP_PTR->next = TEMP_PTR->next->next;
            delete (to_delete);

            return true;
        }
    }
}

int main()
{

    int INPUT;

    while (1)
    {

        cout << "\n\t\t\t\t --> 1. PERFORM AN OPERATION";

        cout << "\n\t\t\t\t --> 2. TERMINATE THE PROCESS";

        cout << "\n\n\n\t\t\t\t --> ENTER YOUR CHOICE : ";

        cin >> INPUT;

        if (INPUT == 1)
        {

            cout << "\n\n\t\t\t\t --> 1. INSERTION OF A NODE ";

            cout << "\n\t\t\t\t --> 2. DELETION OF A NODE ";

            cout << "\n\t\t\t\t --> 3. DISPLAY LINKED LIST ";

            cout << "\n\t\t\t\t --> 4. DISPLAY THE VALUE AT THE HEAD NODE";

            cout << "\n\t\t\t\t --> 5. DISPLAY THE SIZE";

            cout << "\n\t\t\t\t --> 6. DISPLAY FOR AN ELEMENT ";

            cout << "\n\n\n\t\t\t\t --> ENTER YOUR CHOICE : ";
            cin >> INPUT;

            switch (INPUT)
            {

            case 1:
            {

                bool verify = INSERT(PTR);

                if (verify)
                    DISPLAY(PTR);

                break;
            }

            case 2:
            {

                bool verify = DLT(PTR);

                if (verify)
                    DISPLAY(PTR);

                break;
            }

            case 3:
            {

                DISPLAY(PTR);

                break;
            }

            case 4:
            {

                if (PTR->HEAD == NULL)
                {
                    cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY <-- \n";
                }

                else
                {
                    cout << "\n\n\t\t\t\t DATA IN HEAD NODE : ";
                    cout << PTR->HEAD->val << "\n\n";
                }

                break;
            }

            case 5:
            {

                DISPLAY(PTR);

                cout << "\n\n\t\t\t\t\t --> LINKED LIST SIZE IS " << PTR - GETSZ() << "\n\n";

                break;
            }

            case 6:
            {

                int verify = PTR->SRCH();

                if (verify == -2)
                {

                    cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY <-- \n";

                    cout << "\n\t\t\t\t\t\t--> SEARCH NOT POSSIBLE <-- \n";
                }

                else if (verify == -1)
                {

                    cout << "\n\t\t\t\t\t\t--> NOT FOUND <-- \n";
                }

                else
                {

                    ///cout<<"\n\t\t\t\t\t--> YOUR GIVEN ELEMENT IS PRESENT AT NODE "<<verify<<". \n\n";
                }

                break;
            }

            default:
            {

                cout << "\n\n\t\t\t\t --> WRONG INPUT CHOSEN KINDLY CORRECT THIS <-- \n";

                break;
            }
            }
        }

        else if (INPUT == 2)
        {

            cout << "\n\n\t\t\t\t\t-->TERMINATING THE PROCESS <-- \n";
            break;
        }

        else
        {

            cout << "\n\n\t\t\t\t --> WRONG INPUT CHOSEN KINDLY CORRECT THIS <-- \n";
        }
    }

    return 0;
}
