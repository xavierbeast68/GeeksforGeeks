//* https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
//* https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix, int n)
    {
        // code here

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
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> a;
            for (int j = 0; j < n; j++)
            {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends