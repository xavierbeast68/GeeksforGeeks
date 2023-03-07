//* https://www.geeksforgeeks.org/sentence-palindrome-palindrome-removing-spaces-dots-etc/
//* https://practice.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool sentencePalindrome(string s)
    {
        // code here

        int i = 0, j = s.length() - 1;
        if (s.length() == 1)
        {
            return true;
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (i <= j)
        {
            while (i <= j && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            {
                i++;
            }
            while (i <= j && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')))
            {
                j--;
            }
            if (i <= j && s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        Solution ob;
        cout << ob.sentencePalindrome(str) << endl;
    }
    return 0;
}

// } Driver Code Ends