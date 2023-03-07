//* https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array/
//* https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}

// } Driver Code Ends

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // Your code here
    priority_queue<int> pq;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            pq.push(mat[row][col]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}
