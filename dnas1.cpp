// Implement a Doubly Linked List with nodes
//By Kartik Joshi
#include <iostream>

using namespace std;

template <class K>
class Node
{
public:
    T val;
    Node<int> *nxt = NULL;
    Node<int> *prv = NULL;
    static Node<int> *head;
    static Node<int> *tail;
    static int size;

    Node()
    {
        prv = NULL;
        nxt = NULL;
    }
};

Node<int> *ptr = NULL;

template <class K>
Node<int> *Node<K>::head = ptr;
template <class K>
Node<int> *Node<K>::tail = ptr;

template <class K>
int Node<K>::size = 0;

//a function to insert a node at a given index either at the begining or end
bool insert_any_node(Node<int> *any_node)
{
    //a pointer which will be used furter for traversing the whole linked list
    Node<int> *traversal_pointer1 = new Node<int>();
    Node<int> *traversal_pointer2 = new Node<int>();
    traversal_pointer1 = any_node->head;
    traversal_pointer2 = any_node->tail;

    int inputs;
    if (traversal_pointer1 == NULL && traversal_pointer2 == NULL)
    {
        cout << "\n\t\t\t\t\t\t-->LIST IS EMPTY <-- \n";
        cout << "\n\t\t\t\t\t    --> INSERT ONLY AT THE STARTING <-- \n";

        Node<int> *new_node = new Node<int>();
        cout << "\n\t\t\t\t-->ENTER THE VALUE AT THE NODE : ";
        cin >> inputs;
        new_node->val = inputs;
        new_node->nxt = NULL;
        new_node->prv = NULL;
        new_node->head = new_node;
        new_node->tail = new_node;
        new_node->size++;
        return true;
    }
    else
    {
        string LOC;
        cout << "\n\t\t\t\t--> PLEASE SPECIFY LOCATION AS ( BEFORE/AFTER DATA ): ";
        cin >> LOC >> inputs;
        if (LOC == "BEFORE")
        {
            if (traversal_pointer1->head->val == inputs)
            {
                Node<int> *new_node = new Node<int>();
                cout << "\n\t\t\t\t--> PLEASE ENTER THE VALUE AT THE NODE : ";
                cin >> new_node->val;
                new_node->nxt = new_node->head;
                new_node->prv = NULL;
                new_node->head->prv = new_node;
                new_node->head = new_node;
                new_node->size++;
                return true;
            }
            else
            {

                while (traversal_pointer1->nxt != NULL)
                {
                    if (traversal_pointer1->nxt->val == inputs)
                    {
                        break;
                    }
                    traversal_pointer1 = traversal_pointer1->nxt;
                }

                //if the given node is not present we will not insert the node
                if (traversal_pointer1->nxt == NULL || traversal_pointer1->nxt->val != inputs)
                {
                    cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                    return false;
                }

                Node<int> *new_node = new Node<int>(); //a new node which will be inserted
                cout << "\n\t\t\t\t--> ENTER THE VALUE AT THE NODE : ";
                cin >> new_node->val;
                new_node->nxt = traversal_pointer1->nxt;
                new_node->prv = traversal_pointer1;
                traversal_pointer1->nxt->prv = new_node;
                traversal_pointer1->nxt = new_node;
                traversal_pointer1->size++;
                return true;
            }
        }
        else
        {
            while (traversal_pointer1->nxt != NULL)
            {
                if (traversal_pointer1->val == inputs)
                {
                    break;
                }
                traversal_pointer1 = traversal_pointer1->nxt;
            }

            //if the given node is not present we will not insert the node
            if (traversal_pointer1->val != inputs)
            {
                cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                return false;
            }

            Node<int> *new_node = new Node<int>(); //a new node which will be inserted
            cout << "\n\t\t\t\t-->ENTER THE VALUE AT THE NODE : ";
            cin >> new_node->val;
            new_node->nxt = traversal_pointer1->nxt;
            new_node->prv = traversal_pointer1;
            if (traversal_pointer1 == traversal_pointer1->tail)
                traversal_pointer1->tail = new_node;
            traversal_pointer1->nxt = new_node;
            new_node->size++;
            return true;
        }
    }
}

//a function to insert a node at a given index either at the begining or end
bool delete_any_node(Node<int> *any_node)
{
    //a pointer which will be used furter for traversing the whole linked list
    Node<int> *traversal_pointer = new Node<int>();
    traversal_pointer = any_node->head;

    int inputs;
    if (traversal_pointer == NULL)
    {
        cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY <-- \n";
        cout << "\n\t\t\t\t\t\t--> YOU CAN'T DELETE ANY NODE <-- \n";

        return false;
    }
    else
    {
        string LOC;
        cout << "\n\t\t\t\t--> PLEASE SPECIFY LOCATION AS ( BEFORE/AFTER DATA ): ";
        cin >> LOC >> inputs;
        if (LOC == "BEFORE")
        {
            if (traversal_pointer->nxt == NULL)
            {
                cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                return false;
            }
            else if (traversal_pointer->nxt->nxt == NULL)
            {
                if (traversal_pointer->nxt->val == inputs)
                {
                    Node<int> *to_delete = new Node<int>();
                    to_delete = traversal_pointer->nxt;
                    traversal_pointer->nxt = NULL;
                    traversal_pointer->tail = traversal_pointer;
                    traversal_pointer->size--;
                    delete (to_delete);
                    return true;
                }
                else
                {
                    cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                    return false;
                }
            }
            else if (traversal_pointer->nxt != NULL && traversal_pointer->nxt->nxt != NULL)
            {

                if (traversal_pointer->nxt->val == inputs)
                {
                    Node<int> *to_delete = new Node<int>();
                    to_delete = traversal_pointer;
                    traversal_pointer->head = traversal_pointer->nxt;
                    traversal_pointer->nxt->prv = NULL;
                    delete (to_delete);
                    return true;
                }

                while (traversal_pointer->nxt->nxt->nxt != NULL)
                {
                    if (traversal_pointer->nxt->nxt->val == inputs)
                    {
                        break;
                    }
                    traversal_pointer = traversal_pointer->nxt;
                }

                //if the given node is not present we will not delete the node
                if (traversal_pointer->nxt->nxt->nxt == NULL)
                {
                    cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                    return false;
                }
                else if (traversal_pointer->nxt->nxt->val != inputs)
                {
                    cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                    return false;
                }

                Node<int> *to_delete = new Node<int>();
                to_delete = traversal_pointer->nxt;
                traversal_pointer->nxt = traversal_pointer->nxt->nxt;
                traversal_pointer->nxt->prv = traversal_pointer;
                traversal_pointer->size--;
                delete (to_delete);
                return true;
            }
        }
        else
        {
            if (traversal_pointer->nxt == NULL)
            {
                cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                return false;
            }

            traversal_pointer = any_node->head;
            while (traversal_pointer->nxt->nxt != NULL)
            {
                if (traversal_pointer->val == inputs)
                {
                    break;
                }
                traversal_pointer = traversal_pointer->nxt;
            }

            //if the given node is not present we will not insert the node
            if (traversal_pointer->val != inputs)
            {
                cout << "\n\t\t\t\t--> NODE NOT FOUND <-- \n";
                return false;
            }

            Node<int> *to_delete = new Node<int>();
            to_delete = traversal_pointer->nxt;
            if (to_delete == traversal_pointer->tail)
            {
                traversal_pointer->tail = traversal_pointer;
                traversal_pointer->nxt = traversal_pointer->nxt->nxt;
            }
            else
            {
                traversal_pointer->nxt = traversal_pointer->nxt->nxt;
                traversal_pointer->nxt->prv = traversal_pointer;
            }
            delete (to_delete);
            traversal_pointer->size--;
            return true;
        }
    }
}

void DISPALY_LL(Node<int> *any_object)
{

    Node<int> *traversal_pointer = any_object->head;
    if (traversal_pointer == NULL)
    {
        cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY <-- \n";
        return;
    }

    cout << "\n\n--> YOUR LINK LIST IS(TOP TO BOTTOM) <-- \n\n";

    int pos_now = 1;
    while (traversal_pointer != NULL)
    {
        cout << "\tVALUE AT THE NODE " << pos_now << " :- " << traversal_pointer->val << "\n";
        traversal_pointer = traversal_pointer->nxt;
        pos_now++;
    }

    cout << "\n\n--> YOUR LINKED LIST IS( BOTTOM TO TOP ) <-- \n\n";
    pos_now = traversal_pointer->size;
    traversal_pointer = any_object->tail;
    while (traversal_pointer != NULL)
    {
        cout << "\tVALUE AT THE NODE " << pos_now << " :- " << traversal_pointer->val << "\n";
        traversal_pointer = traversal_pointer->prv;
        pos_now--;
    }
}

bool SEARCH(Node<int> *&a_pointer, bool &verify, int &pos_now, int target)
{
    if (a_pointer == NULL)
    {
        return false;
    }
    else
    {
        while (a_pointer != NULL)
        {
            if (a_pointer->val == target)
            {
                cout << "\n--> FOUND AT " << pos_now;
                a_pointer = a_pointer->nxt;
                pos_now++;
                return true;
            }
            a_pointer = a_pointer->nxt;
        }

        return false;
    }
}

int main()
{
    int inputs;
    while (1)
    {
        cout << "\n\t\t\t\t --> 1. WANT TO PERFORM AN OPERATION";
        cout << "\n\t\t\t\t --> 2. WANT TO TERMINATE THE PROCESS";

        cout << "\n\n\n\t\t\t\t --> ENTER YOUR CHOICE PLEASE :- ";
        cin >> inputs;

        if (inputs == 1)
        {
            cout << "\n\n\t\t\t\t --> 1. INSERTION OF A NODE";
            cout << "\n\t\t\t\t --> 2. DELETION OF A NODE ";
            cout << "\n\t\t\t\t --> 3. DISPLAY LINKED LIST ";
            cout << "\n\t\t\t\t --> 4. DISPLAY VALUE AT THE HEAD NODE";
            cout << "\n\t\t\t\t --> 5. DISPLAY THE VALUE AT THE LAST NODE ";
            cout << "\n\t\t\t\t --> 6. DISPLAY THE SIZE ";
            cout << "\n\t\t\t\t --> 7. SEARCH FOR AN ELEMENT";
            cout << "\n\n\n\t\t\t\t --> ENTER YOUR CHOICE PLEASE :- ";
            cin >> inputs;

            switch (inputs)
            {
            case 1:
            {
                bool verify = insert_any_node(ptr);
                if (verify)
                    DISPALY_LL(ptr);
                break;
            }
            case 2:
            {
                bool verify = delete_any_node(ptr);
                if (verify)
                    DISPALY_LL(ptr);
                break;
            }
            case 3:
            {
                DISPALY_LL(ptr);
                break;
            }
            case 4:
            {
                if (ptr->head == NULL)
                {
                    cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY HENCE THERE IS NO NODE <-- \n";
                }
                else
                {
                    cout << "\n\n\t\t\t\t DATA AT THE HEAD NODE :- ";
                    cout << ptr->head->val << "\n\n";
                }
                break;
            }
            case 5:
            {
                if (ptr->tail == NULL)
                {
                    cout << "\n\t\t\t\t\t\t--> LIST IS EMPTY HENCE THERE IS NO NODE <-- \n";
                }
                else
                {
                    cout << "\n\n\t\t\t\t DATA AT THE LAST NODE :- ";
                    cout << ptr->tail->val << "\n\n";
                }
                break;
            }
            case 6:
            {
                DISPALY_LL(ptr);
                cout << "\n\n\t\t\t\t\t --> HENCE CURRENT LINKED LIST SIZE IS " << ptr->size << "\n\n";
                break;
            }
            case 7:
            {
                bool ult_verify = false, sec_verify = true;
                Node<int> *p = new Node<int>();
                p = p->head;
                int pos_now = 1, target = 0;
                cout << "\n\t\t\t\t--> PLEASE ENTER THE VALUE TO FIND :- ";
                cin >> target;

                while (sec_verify)
                {
                    sec_verify = SEARCH(p, sec_verify, pos_now, target);
                    if (sec_verify)
                    {
                        ult_verify = true;
                    }
                }

                if (!ult_verify)
                {
                    cout << "\n\t\t\t\t--> NODE NOT FOUND <-- ";
                }
                cout << "\n\n";
                break;
            }
            default:
            {
                cout << "\n\n\t\t\t\t --> WRONG INPUT CHOSEN KINDLY CORRECT THIS <-- \n";
                break;
            }
            }
        }
        else if (inputs == 2)
        {
            cout << "\n\n\t\t\t\t\t--> TERMINATING THE PROCESS <-- \n";
            break;
        }
        else
        {
            cout << "\n\n\t\t\t\t --> WRONG INPUT CHOSEN /n KINDLY CORRECT THIS <-- \n";
        }
    }

    return 0;
}
