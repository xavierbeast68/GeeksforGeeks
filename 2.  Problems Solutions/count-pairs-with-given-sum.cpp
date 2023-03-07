//* https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/count-pairs-with-given-sum/
//* https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here

        if (n == 1)
        {
            return 0;
        }

        int count = 0;
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            ump[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            ump[arr[i]]--;
            if (ump.find(k - arr[i]) != ump.end())
            {
                count += ump[k - arr[i]];
                if (ump[arr[i]] == 0)
                {
                    ump.erase(arr[i]);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}
// } Driver Code Ends