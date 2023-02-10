//* https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
//* https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        // code here

        int rows = n;
        int cols = m;

        //* starting from upper right corner */
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0)
        {
            if (x == matrix[i][j])
            {
                return true;
            }
            else if (x < matrix[i][j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return false;
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
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

// } Driver Code Ends