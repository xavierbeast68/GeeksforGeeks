//* https://www.geeksforgeeks.org/print-palindromic-partitions-string/
//* https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.youtube.com/watch?v=WBgsABoClE0


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void partition(vector<vector<string>> &ans, string s, vector<string> &temp)
    {
        if (s.length() == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = 1; i <= s.length(); ++i)
        {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i);

            if (isPalindrome(part1))
            {
                temp.push_back(part1);
                partition(ans, part2, temp);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> allPalindromicPerms(string s)
    {
        // code here

        vector<vector<string>> ans;
        vector<string> temp;
        partition(ans, s, temp);
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
        string S;

        cin >> S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends