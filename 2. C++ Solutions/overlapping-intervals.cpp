//* https://www.geeksforgeeks.org/merging-intervals/
//* https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(vector<vector<int>> &intervals, vector<vector<int>> &ans, int left, int right, int i, int n)
    {
        // base conditions->
        if (i == n - 1)
        {
            ans.push_back({left, right});
            return n; // means (n-1)th element of intervals is also included
        }
        // b1 < a2, no overlap
        if (right < intervals[i + 1][0])
        {
            ans.push_back({left, right});
            return i + 1;
        }

        // b1 == a2
        if (right == intervals[i + 1][0])
        {
            // no change in left
            right = intervals[i + 1][1];
            return solve(intervals, ans, left, right, i + 1, n);
        }
        // b1 > a2, a1 <= a2 already known
        else
        {
            // b1 <= b2
            if (right <= intervals[i + 1][1])
            {
                // left remain same
                right = intervals[i + 1][1];
                return solve(intervals, ans, left, right, i + 1, n);
            }
            // b1 > b2
            else
            {
                // left remain same
                // right remain same
                return solve(intervals, ans, left, right, i + 1, n);
            }
        }
    }

    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        // Code here
        int n = intervals.size();
        if (n == 1)
        {
            return intervals;
        }

        vector<vector<int>> answer;
        sort(begin(intervals), end(intervals));
        // a1 <= a2 always

        int i = 0;
        while (i < n - 1)
        {
            int left = intervals[i][0], right = intervals[i][1];
            i = solve(intervals, answer, left, right, i, n);
        }

        if (i == n - 1) // means (n-1)th not included
        {
            answer.push_back(intervals[n - 1]);
        }

        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> Intervals(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            Intervals[i].push_back(x);
            Intervals[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.overlappedInterval(Intervals);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends