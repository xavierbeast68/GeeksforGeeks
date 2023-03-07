//* https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
//* https://www.geeksforgeeks.org/cpp-__builtin_popcount-function/
//* https://practice.geeksforgeeks.org/problems/set-bits0143/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here

        // int count = 0;
        // while(N > 0){
        //     if(N & 1){
        //         count++;
        //     }
        //     N >>= 1;
        // }
        // return count;
        return __builtin_popcountll(N);
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
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends