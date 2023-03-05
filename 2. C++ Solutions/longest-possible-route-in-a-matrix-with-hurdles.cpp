//* https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1
//* https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/
//* https://www.youtube.com/watch?v=X1cWKI83tZo

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int &answer, int temp_ans, vector<vector<int>> &m, int xs, int ys, int xd, int yd)
    {
        if (xs == xd && ys == yd)
        {
            answer = max(answer, temp_ans);
            return;
        }

        // down
        if (xs + 1 < m.size() && m[xs + 1][ys] == 1)
        {
            m[xs][ys] = 0; // marked visited
            dfs(answer, temp_ans + 1, m, xs + 1, ys, xd, yd);
            m[xs][ys] = 1;
        }

        // up
        if (xs - 1 >= 0 && m[xs - 1][ys] == 1)
        {
            m[xs][ys] = 0; // marked visited
            dfs(answer, temp_ans + 1, m, xs - 1, ys, xd, yd);
            m[xs][ys] = 1;
        }

        // right
        if (ys + 1 < m[0].size() && m[xs][ys + 1] == 1)
        {
            m[xs][ys] = 0; // marked visited
            dfs(answer, temp_ans + 1, m, xs, ys + 1, xd, yd);
            m[xs][ys] = 1;
        }

        // left
        if (ys - 1 >= 0 && m[xs][ys - 1] == 1)
        {
            m[xs][ys] = 0; // marked visited
            dfs(answer, temp_ans + 1, m, xs, ys - 1, xd, yd);
            m[xs][ys] = 1;
        }
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here

        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0)
        {
            return -1;
        }

        int answer = 0;
        dfs(answer, 0, matrix, xs, ys, xd, yd);

        return (answer == 0 ? -1 : answer);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends