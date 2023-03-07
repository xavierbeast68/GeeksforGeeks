//* https://www.geeksforgeeks.org/word-break-problem-using-backtracking/
//* https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<string> ans;
    void dfs(string temp, string s, vector<string> &dict, int ind)
    {
        if (ind == s.length())
        {
            ans.push_back(temp);
            return;
        }

        string t = "";
        for (int i = ind; i <= s.length(); ++i)
        {
            t += s[i];
            if (isValid(dict, t))
            {
                dfs(temp + t + (((i + 1) == s.length()) ? "" : " "), s, dict, i + 1);
            }
        }
    }
    bool isValid(vector<string> &dict, string t)
    {
        for (int i = 0; i < dict.size(); ++i)
        {
            if (dict[i].compare(t) == 0)
            {
                return true;
            }
        }
        return false;
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        // code here

        dfs("", s, dict, 0);
        return ans;
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
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends