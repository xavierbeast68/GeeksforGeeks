//* https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
//* https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool present(vector<vector<char>> &board, string &word, int counter_row, int counter_col, int r, int c, int i)
    {

        if (i == word.length())
        {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() // r,c gets out of bounds
            || word[i] != board[r][c])
        { // current letter is not the corresponding letter of the word
            return false;
        }

        // else->
        return (present(board, word, counter_row, counter_col, r + counter_row, c + counter_col, i + 1));
    }

    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        // Code here

        vector<vector<int>> answer;

        int rows = grid.size(), cols = grid[0].size();
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (present(grid, word, -1, 0, r, c, 0))
                { // moving up
                    answer.push_back({r, c});
                }
                else if (present(grid, word, 1, 0, r, c, 0))
                { // moving down
                    answer.push_back({r, c});
                }
                else if (present(grid, word, 0, -1, r, c, 0))
                { // moving left
                    answer.push_back({r, c});
                }
                else if (present(grid, word, 0, 1, r, c, 0))
                { // moving right
                    answer.push_back({r, c});
                }
                else if (present(grid, word, -1, -1, r, c, 0))
                { // moving upper-left
                    answer.push_back({r, c});
                }
                else if (present(grid, word, -1, 1, r, c, 0))
                { // moving upper-right
                    answer.push_back({r, c});
                }
                else if (present(grid, word, 1, -1, r, c, 0))
                { // moving lower-left
                    answer.push_back({r, c});
                }
                else if (present(grid, word, 1, 1, r, c, 0))
                { // moving lower-right
                    answer.push_back({r, c});
                }
            }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
    }
    return 0;
}
// } Driver Code Ends