#include <string>
#include<iostream>
#include<stdio.h>
using namespace std;

class node
{                                                    //class defined
public:
    int data;                                        //store data
    node *left;                                      //left child pointer
    node *right;                                     //right child pointer

    node(int val)
    {                                                //constructor
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insertion(node *userbst, int val)
{
    if (userbst == NULL)
    {                                            //inserting the new node by pasing through the constructor
        return new node(val);
    }
    if (val < userbst->data)
    {
        userbst->left = insertion(userbst->left, val); //insert if the val is smaller then userbst data
    }
    else
    {                                            //insert if the val is greater or equal to the userbst data
        userbst->right = insertion(userbst->right, val);
    }
}

void inOrder(node *&userbst)
{                                                //function to do inorder traversal
    if (userbst == NULL)                         // base conditon
    {
        return;
    }
    inOrder(userbst->left);                      //recursive call for left
    cout << userbst->data << "\t";
    inOrder(userbst->right);                     //recursive call for right
}


void preorder(node *&userbst)
{                                                //function to do preorder traversal
    if (userbst == NULL)
    {                                            //base check
        return;
    }
    cout << userbst->data << "\t";
    preorder(userbst->left);                     //recursive call for left
    preorder(userbst->right);                    //recursive call for right
}


string postorder(node *&userbst)
{                                                //function to do postorder traversal
    string post;
    if (userbst == NULL)
    {                                            //base check
        return "";
    }
    
    postorder(userbst->left);                     //recursive call for left
    postorder(userbst->right);                   //recursive call for right
    cout << userbst->data << "\t";
    post=post+(char(userbst->data));
    return post;
}


node *insuc(node *userbst)
{
    node *suc = userbst;
    while (suc == NULL && suc->left == NULL)
    { 
        suc = suc->left;
    }
    return suc;
}

node *dlt(node *userbst, int x)
{                                                  //checking for the value x in the tree
    
    if (x < userbst->data)
    {
        userbst->left = dlt(userbst->left, x);
    }
    else if (x > userbst->data)
    {
        userbst->right = dlt(userbst->right, x);
    }

    else if (x == userbst->data)                    //if the value x is found
    {
        if (userbst->left == NULL)
        {                                          
            node *newnode = userbst->right;         //only when we have right child ,set the right value then  delete the node
            free(userbst);
            return newnode;
        }
        else if (userbst->right == NULL)
        {                                
            node *newnode = userbst->left;          //only when we have right child ,set the right value then  delete the node
            free(userbst);
            return newnode;
        }
        else
        { 
            node *newnode = insuc(userbst->right);    //both right and left are present,swap the inorder succersor the key node.
            userbst->data = newnode->data;
            userbst->right = dlt(userbst->right, newnode->data);
        }
        return userbst;
    }
                                                       //if the key is not found
    else
    {
        cout << "\nThe key is not in the given tree" << endl;
        return NULL;
    }
}


void lvl(node *userbst, int level);
int height(node *n);


void lvlorder(node *userbst)                           //for lvl order traversal
{
    int h = height(userbst);
    int i;
    cout <<"\n";
    for (i = 1; i <= h; i++)
    {
        lvl(userbst, i);
        cout << "\n";
    }
}


void lvl(node *userbst, int level)                   //for printing the existing  lvl
{
    if (userbst == NULL)
        return;
    if (level == 1)
        cout << userbst->data << " ";
    else if (level > 1)
    {
        lvl(userbst->left, level - 1);
        lvl(userbst->right, level - 1);
    }
}


int height(node *n)                                    //for calculating height of the tree
{
    if (n == NULL)
        return 0;
    else
    {
        
        int lefthigh = height(n->left);                //left subtree
        int righthigh = height(n->right);             //right subtree

    
        if (lefthigh > righthigh)
        {
            return (lefthigh + 1);
        }
        else
        {
            return (righthigh + 1);
        }
                                                             //checking which one is large and returning
    }
}

void check(node *userbst)                                   //function to comapare the 2 BST
{
    node *root2 = NULL;
    cout << "\n\t\t\tEnter the data in the 2nd BST" << endl;
    cout << "\nEnter the root node ";
    int val;
    cin >> val;
    root2 = insertion(root2, val);
    cout << "\nWant to add more nodes \n1.Yes \n2.No \nEnter the choice: ";
    int choice;
    cin >> choice;

    while (choice != 2)
    {
        cout << "\nEnter value to be inserted: ";
        cin >> val;
        insertion(root2, val);
        cout << "\nWant to add more nodes \n1.Yes \n2.No \nEnter the choice: ";
        cin >> choice;
    }
    string user1 = postorder(userbst);
    string user2 = postorder(root2);
    if (user1 == user2)
    {
        cout << "\nBoth the bst are same." << endl;
    }
    else
    {
        cout << "\nThe given bst aren't same." << endl;
    }
}




                                                            //driver code

int main()
{

    int input, val;
    cout << "\nEnter the value for the root node: ";
    cin >> val;
    node *userbst = NULL;
    userbst = insertion(userbst, val);                           //insertion in the user tree
                                                                 //main menu
    while (true)
    { 
        cout << "\n\t\t\t\t\tSelect the option:- \n\t\t\t\t\t\t1.Enter a value \n\t\t\t\t\t\t2.Display in-order \n\t\t\t\t\t\t3.Display pre-oreder \n\t\t\t\t\t\t4.Display post-order \n\t\t\t\t\t\t5.Display level-order \n\t\t\t\t\t\t6.Remove a node \n\t\t\t\t\t\t7.Check the equallency of 2 BST \n\t\t\t\t\t\t8.Exit the program" << "\n";
        cout << "Enter the option: ";
        cin >> input;

        switch (input)
        {
        case 1:
        {
            cout << "\nEnter value to be inserted: ";
            cin >> val;
            insertion(userbst, val);
            break;
        }
        case 2:
        {
            cout << "\nIn-order:" << endl;
            inOrder(userbst);
            break;
        }
        case 3:
        {
            cout << "\nPre-order: " << endl;
            preorder(userbst);
            break;
        }
        case 4:
        {
            cout << "\nPost-order: " << endl;
            postorder(userbst);
            break;
        }
        case 5:
        {
            cout << "\nLevel-order: ";
            lvlorder(userbst);
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "\nEnter value to be removed: ";
            int del;
            cin >> del;
            userbst = dlt(userbst, del);
            cout << "\nValue is sucefully removed" << endl;
            break;
        }
        case 7:
        {
            check(userbst);
            break;
        }
        case 9:
        {
            cout << "\nThanks" << endl
                 << endl;
            return 0;
        }
        default:
        {
            cout << "\nYou have select a wrong,PLEASE enter the correct option" << endl;
            break;
        }
        }
    }
    return 0;
}