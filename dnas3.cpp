//Bubble, insertion and selection algos
// By Kartik Joshi 3932

#include <iostream>

using namespace std;

template <typename K>
void display_array(K array[], int array_size)
{

    cout << "\n\t\t\tArray is:- ";

    cout << "{ ";

    for (int i = 0; i < array_size; i++)
    {

        if (i != array_size - 1)
            cout << array[i] << ", ";

        else
            cout << array[i] << " ";
    }

    cout << "}\n\n";
}

template <typename K>
bool check(K array[], int array_size)
{

    for (int i = 0; i < array_size - 1; i++)
    {
        if (array[i] <= array[i + 1])
        {
        }
        else
            return false;
    }
    return true;
}

template <typename K>
void bublesort(K array[], int array_size)
{

    cout << "\t\t\t\t\t--> BUBBLE SORTING <-- \n\n";

    K tempar[array_size];

    for (int i = 0; i < array_size; i++)
        tempar[i] = array[i];

    int pass = 0;

    for (pass = 1; pass <= array_size - 1; pass++)
    {

        for (int j = 0; j < array_size - pass; j++)
        {

            if (tempar[j] > tempar[j + 1])
                swap(tempar[j], tempar[j + 1]);
        }

        cout << "\t\t\tAfter the ";

        pass == 1 ? cout << "1st " : pass == 2 ? cout << "2nd "
                                 : pass == 3   ? cout << "3rd "
                                               : cout << pass << "th ";

        cout << " pass...";

        display_array(tempar, array_size);

        if (check(tempar, array_size))
        {
            break;
        }
    }

    cout << "\t\t\t\t--> SORTED IN ASCENDING ORDER <-- \n\n";

    cout << "\t\t\tNUMBER OF PASSES : " << pass << "\n";

    display_array(tempar, array_size);

    cout << "\n\n\n\n";
}

template <typename K>
void insrtsort(K array[], int array_size)
{

    cout << "\t\t\t\t\t--> INSERTION SORTING <-- \n\n";

    K tempar[array_size];

    for (int i = 0; i < array_size; i++)
        tempar[i] = array[i];

    int pass = 0;

    for (pass = 1; pass <= array_size - 1; pass++)
    {

        K temp = tempar[pass], j = pass - 1;

        while (j >= 0 && tempar[j] > temp)
        {
            tempar[j + 1] = tempar[j];
            j--;
        }

        tempar[j + 1] = temp;

        cout << "\t\t\tAfter the ";

        pass == 1 ? cout << "1st " : pass == 2 ? cout << "2nd "
                                 : pass == 3   ? cout << "3rd "
                                               : cout << pass << "th ";

        cout << " pass...";

        display_array(tempar, array_size);

        if (check(tempar, array_size))
        {
            break;
        }
    }

    cout << "\t\t\t\t--> SORTED IN ASCENDING ORDER <-- \n\n";

    cout << "\t\t\tNUMBER OF PASSES TAKEN TO SORT:- " << pass << "\n";

    display_array(tempar, array_size);

    cout << "\n\n\n\n";
}

template <typename K>
void selsort(K array[], int array_size)
{

    cout << "\t\t\t\t\t--> SELECTION SORTING<-- \n\n";

    K tempar[array_size];

    for (int i = 0; i < array_size; i++)
        tempar[i] = array[i];

    int pass = 0;

    for (pass = 1; pass <= array_size - 1; pass++)
    {

        int index_min = pass - 1;

        for (int j = pass - 1; j < array_size; j++)
        {

            if (tempar[j] < tempar[index_min])
            {

                index_min = j;
            }
        }

        swap(tempar[pass - 1], tempar[index_min]);

        cout << "\t\t\tAfter the ";

        pass == 1 ? cout << "1st " : pass == 2 ? cout << "2nd "
                                 : pass == 3   ? cout << "3rd "
                                               : cout << pass << "th ";

        cout << " pass...";

        display_array(tempar, array_size);

        if (check(tempar, array_size))
        {
            break;
        }
    }

    cout << "\t\t\t\t--> SORTED IN ASCENDING ORDER <-- \n\n";

    cout << "\t\t\tNUMBER OF PASSES TAKEN TO SORT:- " << pass << "\n";

    display_array(tempar, array_size);

    cout << "\n\n\n\n";
}

int main()
{

    //taking input the number of elements to begin with

    cout << "\t\t\tEnter the number of elements to be enter:- ";

    int num;
    cin >> num;

    //declaring a 1-D array of size entered above to store the elements to be entered by the user

    int array[num];

    //taking input the elements

    for (int i = 0; i < num; i++)
    {

        cout << "\t\t\tPlease enter the ";

        i + 1 == 1 ? cout << "1st " : i + 1 == 2 ? cout << "2nd "
                                  : i + 1 == 3   ? cout << "3rd "
                                                 : cout << i + 1 << "th ";

        cout << "element:- ";

        cin >> array[i];
    }

    display_array(array, num);

    bublesort(array, num);

    insrtsort(array, num);

    selsort(array, num);

    return 0;
}
