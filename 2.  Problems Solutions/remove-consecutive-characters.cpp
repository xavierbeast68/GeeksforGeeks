//* https://www.geeksforgeeks.org/remove-consecutive-duplicates-string/
//* https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.

        string answer = "";
        answer += s[0];
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i - 1])
            {
                answer += s[i];
            }
        }

        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends