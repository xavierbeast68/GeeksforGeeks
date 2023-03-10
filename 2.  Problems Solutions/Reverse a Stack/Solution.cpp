//* https://practice.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void pushAtBottom(stack<int> &s, int data)
    {
        if (s.empty())
        { // s.size() == 0
            s.push(data);
            return;
        }

        int top = s.top();
        s.pop();
        pushAtBottom(s, data);
        s.push(top);
    }
    void Reverse(stack<int> &s)
    {
        if (s.empty())
        { // s.size() == 0
            return;
        }

        int top = s.top();
        s.pop();
        Reverse(s);
        pushAtBottom(s, top);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int> res;
        while (St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }
}
// } Driver Code Ends