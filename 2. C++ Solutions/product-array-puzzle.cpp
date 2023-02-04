//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void left_product(vector<long long int> &left, vector<long long int> nums, int n)
    {
        left[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            left[i] = left[i - 1] * nums[i];
        }
    }
    void right_product(vector<long long int> &right, vector<long long int> nums, int n)
    {
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            right[i] = right[i + 1] * nums[i];
        }
    }

    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        // code here
        vector<long long int> P(n);
        if (n == 1)
        {
            P[0] = 1;
            return P;
        }

        // creating auxillary arrays
        vector<long long int> left(n);
        left_product(left, nums, n);
        vector<long long int> right(n);
        right_product(right, nums, n);

        P[0] = right[1];
        P[n - 1] = left[n - 2];
        for (int i = 1; i < n - 1; i++)
        {
            P[i] = left[i - 1] * right[i + 1];
        }
        return P;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends