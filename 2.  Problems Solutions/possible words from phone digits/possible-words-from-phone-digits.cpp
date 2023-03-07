//* https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<string> ans;
    void dfs(string temp, int digits[], map<int, string> &mp, int ind, int N)
    {
        if (ind == N)
        {
            ans.push_back(temp);
            return;
        }

        int d = digits[ind];
        for (int i = 0; i < mp[d].length(); ++i)
        {
            dfs(temp + mp[d][i], digits, mp, ind + 1, N);
        }
    }

    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Your code here

        map<int, string> mp{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}};
        dfs("", a, mp, 0, N);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends