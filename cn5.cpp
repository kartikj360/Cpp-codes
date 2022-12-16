//Kartik Joshi class roll 3932
#include <iostream>

using namespace std;

int main()
{
    int dmate[50][50];
    int i, j, k, x;
    int nod;

    cout << "\n ENTER NO. OF NODES IN THE SYSTEM:";
    cin >> nod;

    //setting up in the first matrix
    for (i = 0; i < nod; i++)
    {
        for (j = 0; j < nod; j++)
        {
            dmate[i][j] = -1;
        }
    }

    //setting the name for the vertex
    char chr[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    //taking the inputs
    for (i = 0; i < nod; i++)
    {
        for (j = 0; j < nod; j++)
        {
            if (i == j)
            {
                dmate[i][j] = 0;
            }
            if (dmate[i][j] == -1)
            {
                cout << "\n ENTER THE DISTANCE BETWEEN THESE 2 NODES " << chr[i] << " - " << chr[j] << " : ";
                cin >> x;
                dmate[i][j] = dmate[j][i] = x;
            }
        }
    }

    //setting up the path
    int path[50][50];
    for (i = 0; i < nod; i++)
    {
        for (j = 0; j < nod; j++)
        {
            path[i][j] = -1;
        }
    }

    cout << "\n 1ST INITIALIZATION";
    //showing up the intialize table of vector
    for (i = 0; i < nod; i++)
    {
        cout << "\n"
             << chr[i] << " TABLE";
        cout << "\nNODE\tDISTANCE\tTHROUGH";
        for (j = 0; j < nod; j++)
        {
            cout << "\n"
                 << chr[j] << "\t" << dmate[i][j] << "\t\t" << path[i][j];
        }
    }

    //showing the  shared table
    int sh[50][50][50];
    for (i = 0; i < nod; i++)
    {
        for (j = 0; j < nod; j++)
        {
            for (k = 0; k < nod; k++)
            { //checking the edge exist or not

                if ((dmate[i][j] > -1) && (dmate[j][k] > -1))
                {
                    sh[i][j][k] = dmate[j][k] + dmate[i][j];
                }
                else
                {
                    sh[i][j][k] = -1;
                }
            }
        }
    }

    //showing the  shared table
    for (i = 0; i < nod; i++)
    {
        cout << "\n=================================";
        cout << "\n\n FOR " << chr[i];
        cout << "\n------------------";
        for (j = 0; j < nod; j++)
        {
            cout << "\n FROM " << chr[j];
            for (k = 0; k < nod; k++)
            {
                cout << "\n " << chr[k] << " " << sh[i][j][k];
            }
            cout << endl;
        }
        cout << "------------------";
        cout << endl
             << endl;
    }

    //updation
    int neew[50][50];
    for (i = 0; i < nod; i++)
    {
        for (j = 0; j < nod; j++)
        {
            //copying the values for user inputted distance matrix
            neew[i][j] = dmate[i][j];
            path[i][j] = i;

            //after updation
            //comparing =a - b - c
            for (k = 0; k < nod; k++)
            {

                if ((neew[i][j] > sh[i][k][j]) || (neew[i][j] == -1))
                {
                    if (sh[i][k][j] > -1)
                    {
                        neew[i][j] = sh[i][k][j];
                        path[i][j] = k;
                    }
                }
            }
            // comparing the  three vertex if no new vertex is found then, we take the  4th one as = a- b- c- d

            if (neew[i][j] == -1)
            {
                for (k = 0; k < nod; k++)
                {

                    if ((neew[i][k] != -1) && (neew[k][j] != -1))
                    {
                        if ((neew[i][j] == -1) || ((neew[i][j] != -1) && (neew[i][j] > neew[i][k] + neew[k][j])))
                        {
                            if (neew[i][k] + neew[k][j] > -1)
                            {
                                neew[i][j] = neew[i][k] + neew[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "\n UPDATED :";
    //displaying updated matrix
    for (i = 0; i < nod; i++)
    {
        cout << "\n=================================";
        cout << "\n"
             << chr[i] << " Table";
        cout << "\nNODE\tDISTANCE\tTHROUGH";
        for (j = 0; j < nod; j++)
        {
            cout << "\n"
                 << chr[j] << "\t" << neew[i][j] << "\t\t";
            if (i == path[i][j])
                cout << "-";
            else
                cout << chr[path[i][j]];
            cout << "\n------------------";
        }
    }
    return 0;
}