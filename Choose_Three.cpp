// Problem Statement:
// You will be given an array A and the size of that array N. Additionally, you will be given a sum S.
//  Your task is to determine whether it is possible to select three distinct indexed values from the array such that their summation equals S.

// Input Format:
// First line will contain T, the number of test cases.
// First line of each test case will contain N and S.
// Second line of each test case will contain the array A.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 100
// 1 <= S <= 1000
// 1 <= A[i] <= 1000 Where 0 <= i < N

// Output Format:
// Output "YES" if it is possible, otherwise output "NO".

#include <bits/stdc++.h> // Including all standard libraries

using namespace std; // Using the standard namespace

int main() // Main function
{
    int T; // Declaring variable for number of test cases
    cin >> T;

    while (T--) // Looping through test cases
    {
        int N, S; // Declaring variables for array size and target sum
        cin >> N >> S;

        int A[N];                   // Declaring an array of size N
        for (int i = 0; i < N; i++) // Loop to read array elements
        {
            cin >> A[i];
        }

        bool found = false;         // Flag to check if a valid triplet is found
        for (int i = 0; i < N; i++) // Iterating through the array
        {
            for (int j = i + 1; j < N; j++) // Nested loop for the second element
            {
                for (int k = j + 1; k < N; k++) // Nested loop for the third element
                {
                    if (A[i] + A[j] + A[k] == S) // Checking if the sum matches S
                    {
                        found = true; // Setting the flag to true if a valid triplet is found
                        break;        // Breaking out of the innermost loop
                    }
                }
                if (found) // Checking if a valid triplet is found to break the second loop
                {
                    break; // Breaking out of the second loop if a valid triplet is found
                }
            }
            if (found) // Checking if a valid triplet is found to break the outermost loop
            {
                break; // Breaking out of the outermost loop if a valid triplet is found
            }
        }
        if (found) // Outputting the result based on whether a valid triplet was found
        {
            cout << "YES" << endl; // Printing "YES" if a valid triplet is found
        }
        else
        {
            cout << "NO" << endl; // Printing "NO" if no valid triplet is found
        }
    }

    return 0;
}
