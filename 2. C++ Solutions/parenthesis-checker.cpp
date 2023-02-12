//* https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
//* https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here

        stack<char> st;
        for (auto &ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else if (st.size() > 0)
            {
                char c = st.top();
                if ((c == '(' && ch == ')') || (c == '[' && ch == ']') || (c == '{' && ch == '}'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        if (st.size() > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}
// } Driver Code Ends