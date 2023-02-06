//* https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
//* https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // Your Code Here

        if (n < 3)
        {
            return false;
        }
        if (n == 3)
        {
            return (A[0] + A[1] + A[2]) == X;
        }

        sort(A, A + n);
        int i = 0;
        while (i <= n - 3)
        {
            if (i > 0 && A[i] == A[i - 1])
            {
                i++;
            }

            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = A[i] + A[j] + A[k];
                if (sum > X)
                {
                    k--;
                }
                else if (sum < X)
                {
                    j++;
                }
                else
                { // (sum == X)
                    return true;
                }
            }
            i++;
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends