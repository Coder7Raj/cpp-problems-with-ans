#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // number of test cases
    cin >> t;

    while (t--)
    {
        long long n, k; // number of cookie jars and the required cookies per jar
        cin >> n >> k;

        long long a[n]; // array to store the number of cookies in each jar
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long minWaste = LLONG_MAX; // variable to track minimum waste
        bool possible = false;          // flag to check if at least one jar can meet the requirement

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= k) // only consider jars with at least k cookies
            {
                long long waste = a[i] % k;      // calculate waste for this jar
                minWaste = min(minWaste, waste); // update minimum waste if current waste is less
                possible = true;                 // mark that at least one jar can meet the requirement
            }
        }

        if (!possible) // if no jar can meet the requirement
        {
            cout << -1 << endl; // output -1
        }
        else
        {
            cout << minWaste << endl; // output the minimum waste found
        }
    }

    return 0;
}
