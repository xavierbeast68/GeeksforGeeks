//* https://practice.geeksforgeeks.org/problems/combination-sum-iii/1?page=1&difficulty[]=1&category[]=Recursion&sortBy=accuracy
//* https://www.youtube.com/watch?v=77KQifr--ek

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> answer;

    void dfs(vector<int> &temp, int moves, int target, int ind)
    {
        if (moves == 0)
        {
            if (target == 0)
            {
                answer.push_back(temp);
            }
            return;
        }

        for (int i = ind; i <= 9; ++i)
        {
            if (i > target)
            {
                break;
            }

            temp.push_back(i);
            dfs(temp, moves - 1, target - i, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int k, int n)
    {
        // code here

        if (n < k || n > 46)
        {
            return answer;
        }

        vector<int> temp;
        dfs(temp, k, n, 1);

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
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans)
        {
            for (auto it : arr)
                cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends