//* https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
//* https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://leetcode.com/problems/spiral-matrix/
//* https://www.youtube.com/watch?v=BJnMZNwUk1M

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        
        vector<int> ans;
        int startRow = 0, endRow = r-1;
        int startCol = 0, endCol = c-1;

        while(startRow <= endRow && startCol <= endCol){

            // Top
            for(int col = startCol; col <= endCol; col++){
                ans.push_back(matrix[startRow][col]);
            }

            // Right
            for(int row = startRow+1; row <= endRow; row++){
                ans.push_back(matrix[row][endCol]);
            }

            // Bottom
            for(int col = endCol-1; col >= startCol; col--){
                if(startRow == endRow){
                    break;
                }
                ans.push_back(matrix[endRow][col]);
            }

            // Left
            for(int row = endRow-1; row > startRow; row--){
                if(startCol == endCol){
                    break;
                }
                ans.push_back(matrix[row][startCol]);
            }

            // Updations->
            startRow++, endRow--;
            startCol++, endCol--;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends