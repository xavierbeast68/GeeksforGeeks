//* https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
//* https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14&ab_channel=takeUforward

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board){
        vector<int> temp;
        for(int col = 0; col < board[0].size(); col++){
            for(int row = 0; row < board.size(); row++){
                if(board[row][col] == 1){
                    temp.push_back(row+1);
                }
            }
        }
        ans.push_back(temp);
    }
    bool isSafe(vector<vector<int>>& board, int col, int row, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal){

        if(leftRow[row] == 1){
            return false;
        }
        if(lowerDiagonal[row+col] == 1){
            return false;
        }
        if(upperDiagonal[(n-1) + (col-row)] == 1){
            return false;
        }

        return true;
    }
    void solve(vector<vector<int>>& ans, vector<vector<int>>& board, int n , int col, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal){
        if(col == n){
            addSolution(ans, board);
            return;
        }
        
        for(int row = 0; row < n ; ++row){
            if(isSafe(board, col , row, n, leftRow, lowerDiagonal, upperDiagonal)){
                board[row][col] = 1;
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[(n-1) + (col-row)] = 1;
                solve(ans, board, n, col + 1, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = 0;
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[(n-1) + (col-row)] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        vector<int> leftRow(n,0), lowerDiagonal(2 * n -1, 0), upperDiagonal(2 * n -1, 0);
        solve(ans, board, n, 0, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends