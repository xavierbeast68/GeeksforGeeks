//* https://www.geeksforgeeks.org/next-permutation/
//* https://practice.geeksforgeeks.org/problems/next-permutation5226/1
//* https://www.youtube.com/watch?v=LuLCLgMElus

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        // code here

        if (N == 1)
        {
            return arr;
        }

        int i = N - 2, ind1 = -1;
        while (i >= 0 && ind1 == -1)
        {
            if (arr[i] < arr[i + 1])
            {
                ind1 = i;
            }
            i--;
        }
        if (ind1 == -1)
        {
            reverse(begin(arr), end(arr));
            return arr;
        }

        i = N - 1;
        int ind2 = -1;
        while (i >= 0 && ind2 == -1)
        {
            if (arr[i] > arr[ind1])
            {
                ind2 = i;
            }
            i--;
        }

        // swapping->
        int temp = arr[ind1];
        arr[ind1] = arr[ind2];
        arr[ind2] = temp;

        reverse(arr.begin() + (ind1 + 1), arr.end());

        return arr;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
