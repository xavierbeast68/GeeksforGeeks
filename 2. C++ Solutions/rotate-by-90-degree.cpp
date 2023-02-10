//* https://www.geeksforgeeks.org/rotate-matrix-90-degree-without-using-extra-space-set-2/?ref=lbp
//* https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix);

// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int>> &matrix)
{
    // Your code goes here
    int n = matrix.size();
    int startRow = 0, endRow = n - 1;
    int startCol = 0, endCol = n - 1;

    for (int level = 1; level <= n / 2; level++)
    {

        int counter = 0;
        while (counter < (endRow - startRow))
        {
            int temp = matrix[startRow][startCol + counter];
            matrix[startRow][startCol + counter] = matrix[startRow + counter][endCol];
            matrix[startRow + counter][endCol] = matrix[endRow][endCol - counter];
            matrix[endRow][endCol - counter] = matrix[endRow - counter][startCol];
            matrix[endRow - counter][startCol] = temp;
            counter++;
        }

        startRow++, endRow--;
        startCol++, endCol--;
    }
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends