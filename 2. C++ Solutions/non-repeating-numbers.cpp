//* https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
//* https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int temp = 0;
        for (int i : nums)
        {
            temp = temp ^ i;
        }
        int result = temp;
        int p = 1;
        while ((temp & 1) == 0)
        {
            temp >>= 1;
            p++;
        }
        int mask = 1 << (p - 1);
        int a = 0, b = 0;
        for (int i : nums)
        {
            if (i & mask)
            {
                a ^= i;
            }
            // else {
            //     b ^= i;
            // }
        }
        b = a ^ result;
        vector<int> ans{min(a, b), max(a, b)};
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends