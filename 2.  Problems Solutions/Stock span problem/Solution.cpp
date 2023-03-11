//* https://leetcode.com/problems/online-stock-span/
//* https://www.geeksforgeeks.org/the-stock-span-problem/
//* https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
//* https://www.interviewbit.com/blog/stock-span-problem/
//* https://www.youtube.com/watch?v=p9T-fE1g1pU&ab_channel=AdityaVerma

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void stockSpan(int stocks[], vector<int> &span, int n)
    {
        stack<int> s;
        span[0] = 1;
        s.push(0);

        for (int i = 0; i < n; ++i)
        {
            int currPrice = stocks[i];
            while (!(s.empty()) && currPrice >= stocks[s.top()])
            {
                s.pop();
            }
            if (s.empty())
            {
                span[i] = i + 1;
            }
            else
            {
                int prevHigh = s.top();
                span[i] = i - prevHigh;
            }
            s.push(i);
        }
    }

    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here

        vector<int> span(n);

        stockSpan(price, span, n);

        return span;
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends