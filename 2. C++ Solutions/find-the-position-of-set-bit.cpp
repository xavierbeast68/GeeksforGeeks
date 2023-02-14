//* https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int N)
    {
        // code here
        int p = 1, ans = 0, count = 0;
        while (N > 0)
        {
            if (N & 1)
            {
                count++;
                ans = p;
            }
            p++;
            N >>= 1;
        }
        return (count == 1 ? ans : -1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends