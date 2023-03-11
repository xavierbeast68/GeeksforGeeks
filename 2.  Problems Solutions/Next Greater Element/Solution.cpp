//* https://www.geeksforgeeks.org/next-greater-element/
//* https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://takeuforward.org/data-structure/next-greater-element-using-stack/
//* https://www.youtube.com/watch?v=Du881K7Jtk8&ab_channel=takeUforward

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here

        stack<int> s;
        vector<long long> nextGreater(n);

        for (int i = n - 1; i >= 0; --i)
        {

            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                nextGreater[i] = -1;
            }
            else
            {
                nextGreater[i] = arr[s.top()];
            }

            s.push(i);
        }

        return nextGreater;
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
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends