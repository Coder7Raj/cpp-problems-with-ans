#include <bits/stdc++.h> // Including all standard libraries
using namespace std;     // Using the standard namespace for convenience

int main()
{
    int N, M, Q;        // N: number of rows, M: number of columns, Q: number of queries
    cin >> N >> M >> Q; // Reading the dimensions of the grid and number of queries

    vector<vector<int>> grid(N, vector<int>(M)); // Initializing the grid
    for (int i = 0; i < N; i++)                  // Reading the grid values
    {

        for (int j = 0; j < M; j++) // Reading the grid values
        {

            cin >> grid[i][j];
        }
    }

    vector<vector<long long>> pref(N, vector<long long>(M)); // Initializing the prefix sum array
    for (int i = 0; i < N; i++)                              // Building the prefix sum array
    {
        for (int j = 0; j < M; j++) // Building the prefix sum array
        {
            pref[i][j] = grid[i][j]; // Start with the current cell value
            if (i > 0)               // Add the value from the cell above
            {

                pref[i][j] += pref[i - 1][j]; // Add the value from the cell above
            }
            if (j > 0) // Add the value from the cell to the left
            {

                pref[i][j] += pref[i][j - 1]; // Add the value from the cell to the left
            }
            if (i > 0 && j > 0) // Subtract the overlapping area
            {

                pref[i][j] -= pref[i - 1][j - 1]; // Subtract the overlapping area
            }
        }
    }

    while (Q--) // Processing each query
    {
        int x1, y1, x2, y2; // Coordinates of the sub-rectangle
        cin >> x1 >> y1 >> x2 >> y2;

        long long totals = pref[x2][y2]; // Start with the total sum up to (x2, y2)
        if (y1 > 0)                      // Subtract the area to the left
        {

            totals -= pref[x2][y1 - 1]; // Subtract the area to the left
        }
        if (x1 > 0) // Subtract the area above
        {

            totals -= pref[x1 - 1][y2]; // Subtract the area above
        }
        if (x1 > 0 && y1 > 0) // Add back the overlapping area
        {

            totals += pref[x1 - 1][y1 - 1]; // Add back the overlapping area
        }

        cout << totals << "\n"; // Output the result for the current query
    }
}
