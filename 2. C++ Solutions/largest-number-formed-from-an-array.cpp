//* https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
//* https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    static bool comp(string x, string y)
    {
        string xy = x + y;
        string yx = y + x;

        //! xy.compare(yx) > 0 won't work here
        return xy > yx;
    }

    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    string printLargest(vector<string> &arr)
    {
        // code here

        //! comp should be a static function
        sort(arr.begin(), arr.end(), comp);
        string ans = "";
        for (auto i : arr)
        {
            ans += i;
        }

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
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends