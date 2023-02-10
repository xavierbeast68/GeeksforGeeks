//* https://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/#
//* https://practice.geeksforgeeks.org/problems/print-diagonally4331/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> A)
    {
        // Your code goes here

        vector<int> ans;
        int maxSum = 2 * (N - 1);
        for (int sum = 0; sum <= maxSum; sum++)
        {
            if (sum <= N - 1)
            {
                int i = 0;
                int j = sum;

                while (i <= N - 1 && j >= 0)
                {
                    ans.push_back(A[i][j]);
                    i++;
                    j--;
                }
            }
            else
            {
                int j = N - 1;
                int i = sum - j;

                while (i <= N - 1 && j >= 0)
                {
                    ans.push_back(A[i][j]);
                    i++;
                    j--;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends