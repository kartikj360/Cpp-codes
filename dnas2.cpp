//IMPLEMRNTING BINARY SEARCH
// By Kartik Joshi 3932
#include <iostream>

using namespace std;

template <typename K>
void binarysearch(K x, int n, K array[])
{

    int left = 0, right = n - 1;

    while (left <= right)
    {
        K mid = left + (right - left) / 2;

        //if target found at the mid index ,output its index(i.e. mid)
        if (array[mid] == x)
        {
            cout << "\t\t\tThe Element is found at " << mid + 1 << " index.\n";
            return;
        }

        //if mid index element is greater than the target element we will move towards left side
        else if (array[mid] > x)
            right = mid - 1;

        //if mid index element is greater than the target element we will move towards right side
        else
            left = mid + 1;
    }

    //if whole array is traverssed
    //then we will print the element is not found
    cout << "\t\t\tElement not found\n";
}

int main()
{

    //taking input the number of elements in the array
    cout << "\t\t\tEnter the number of elements to be search: ";
    int n;
    cin >> n;

    int array[n];
    cout << "\n\n\t\t\t---> ENTER THE ELEMENTS OF THE ARRAY(SORTED) <---\n\n";

    //taking input the whole array
    for (int i = 0; i < n; i++)
    {
        cout << "\t\t\tEnter the ";
        i + 1 == 1 ? cout << "1st " : i + 1 == 2 ? cout << "2nd "
                                  : i + 1 == 3   ? cout << "3rd "
                                                 : cout << i + 1 << "th ";
        cout << "element:- ";
        cin >> array[i];
    }

    //taking input the target which we want to search in the array
    cout << "\t\t\tEnter the element which to searched : ";
    int x;
    cin >> x;

    binarysearch(x, n, array);

    return 0;
}
