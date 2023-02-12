//* https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string longestCommonPrefix(string arr[], int N)
    {
        // your code here

        if (N == 0)
        {
            return "-1";
        }
        string prefix = arr[0];

        for (int i = 1; i < N; i++)
        {
            string s = arr[i];
            while (s.find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.length() == 0)
                {
                    return "-1";
                }
            }
        }

        return prefix;
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
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
