//* https://practice.geeksforgeeks.org/problems/combination-sum-ii/1?page=1&sortBy=newest&query=page1sortBynewest
//* https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=9&ab_channel=takeUforward
//* https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> answer;
    void dfs(vector<int> &temp, vector<int> &candidates, int target, int ind)
    {
        if (target == 0)
        {
            answer.push_back(temp);
            return;
        }

        for (int i = ind; i < candidates.size(); i++)
        {
            if (i > ind && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] > target)
            {
                break;
            }

            temp.push_back(candidates[i]);
            dfs(temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp;
        sort(begin(candidates), end(candidates));
        dfs(temp, candidates, target, 0);
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++)
            {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends