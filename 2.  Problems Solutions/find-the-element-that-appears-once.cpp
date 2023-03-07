//* https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/
//* https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int rec(int nums[], int low, int high)
    {
        if (low == high)
        {
            return nums[low];
        }

        int mid = (low + high) / 2;
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
                return rec(nums, mid + 2, high);
            else
                return rec(nums, low, mid);
        }

        else
        {
            if (nums[mid] == nums[mid - 1])
                return rec(nums, mid + 1, high);
            else
                return rec(nums, low, mid - 1);
        }
    }

    int search(int A[], int N)
    {
        // code
        return rec(A, 0, N - 1);
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t, len;
    cin >> t;
    while (t--)
    {
        cin >> len;
        int arr[len];
        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.search(arr, len) << '\n';
    }
    return 0;
}

// } Driver Code Ends