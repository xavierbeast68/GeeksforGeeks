//* https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/
//* https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string ans;
    void dfs(string temp, int ind, int k, int n)
    {
        if (ind == n || k == 0)
        {
            if (k >= 0 && temp.compare(ans) > 0)
            {
                ans = temp;
            }
            return;
        }

        bool swaped = false;
        for (int i = ind + 1; i < n; ++i)
        {
            if (temp[i] > temp[ind])
            {
                swap(temp[ind], temp[i]);
                dfs(temp, ind + 1, k - 1, n);
                swap(temp[ind], temp[i]);
                swaped = true;
            }
        }
        if (!swaped)
        {
            dfs(temp, ind + 1, k, n);
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        // code here.
        ans = str;
        dfs(str, 0, k, str.length());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends