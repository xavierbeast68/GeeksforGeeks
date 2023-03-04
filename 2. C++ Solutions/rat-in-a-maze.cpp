//! https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=18
//! https://takeuforward.org/data-structure/rat-in-a-maze/
//! https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(string s, vector<string>& ans, vector<vector<int>>& m, int n, int row, int col){
        if(row == (n-1) && col == (n-1)){
            ans.push_back(s);
            return;
        }
        
        // down
        if(row+1 < n && m[row+1][col] == 1){
            m[row][col] = 0; // marked visited
            solve(s + 'D', ans, m, n, row+1, col);
            m[row][col] = 1;
        }
        
        // up
        if(row-1 >= 0 && m[row-1][col] == 1){
            m[row][col] = 0; // marked visited
            solve(s + 'U', ans, m, n, row-1, col);
            m[row][col] = 1;
        }
        
        // right
        if(col+1 < n && m[row][col+1] == 1){
            m[row][col] = 0; // marked visited
            solve(s + 'R', ans, m, n, row, col+1);
            m[row][col] = 1;
        }
        
        // left
        if(col-1 >= 0 && m[row][col-1] == 1){
            m[row][col] = 0; // marked visited
            solve(s + 'L', ans, m, n, row, col-1);
            m[row][col] = 1;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        if(m[0][0] != 0){
            solve("", ans, m, n, 0, 0);
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends