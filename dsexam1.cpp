// C++ program to find circular tour for a truck
#include <iostream>
using namespace std;

// A petrol pump has petrol and dist to next petrol pump
class pump
{
public:
    int petrol;
    int dist;
};

// The function returns starting point if there is a possible solution,
// otherwise returns -1
int tour(pump arr[], int n)
{
    // Consider first petrol pump as a starting point
    int strt = 0;
    int end = 1;

    int cur_pet = arr[strt].petrol - arr[strt].dist;

    /* Run a loop while all petrol pumps are not visited.
    And we have reached first petrol pump again with 0 or more petrol */
    while (end != strt || cur_pet < 0)
    {
        // If curremt amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (cur_pet < 0 && strt != end)
        {
            // Remove starting petrol pump. Change strt
            cur_pet -= arr[strt].petrol - arr[strt].dist;
            strt = (strt + 1) % n;

            // If 0 is being considered as strt again, then there is no
            // possible solution
            if (strt == 0)
                return -1;
        }

        // Add a petrol pump to current tour
        cur_pet += arr[end].petrol - arr[end].dist;

        end = (end + 1) % n;
    }

    // Return starting point
    return strt;
}

// Driver code
int main()
{
    pump arr[] = {{3, 5}, {6, 7}, {4, 1}, {2, 6}, {8, 3}, {4, 5}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int strt = tour(arr, n);

    (strt == -1) ? cout << "No solution" : cout << "Start = " << strt;

    return 0;
}