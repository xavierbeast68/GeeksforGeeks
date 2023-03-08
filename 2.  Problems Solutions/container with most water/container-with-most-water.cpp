//* https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
// User function template for C++
typedef long long ll;

long long maxArea(long long A[], int len)
{
    // Your code goes here

    if (len == 1)
    {
        return 0;
    }

    ll maxWater = LONG_MIN;
    int l = 0, r = len - 1;

    while (l < r)
    {
        ll ht = min(A[l], A[r]);
        ll wd = r - l;
        ll water = ht * wd;

        maxWater = max(maxWater, water);

        if (A[l] < A[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return maxWater;
}

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends