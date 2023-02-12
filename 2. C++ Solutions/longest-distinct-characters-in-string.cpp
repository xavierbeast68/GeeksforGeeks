//* https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
//* https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars(string S);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        cout << longestSubstrDistinctChars(S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

int longestSubstrDistinctChars(string s)
{
    // your code here

    map<char, int> mp;
    int n = s.length();
    int i = 0, j = 0;
    int answer = 0;
    while (j < n)
    {
        mp[s[j]]++;

        while (i <= j && mp[s[j]] > 1)
        {
            mp[s[i]]--;
            i++;
        }
        answer = max(answer, j - i + 1);
        j++;
    }
    return answer;
}