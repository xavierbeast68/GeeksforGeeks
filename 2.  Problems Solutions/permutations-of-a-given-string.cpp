//* https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
//* https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/
//* https://www.geeksforgeeks.org/permutations-of-a-given-string-using-stl/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        // Code here there

        vector<string> answer;
        sort(S.begin(), S.end());
        do
        {
            answer.push_back(S);
        } while (next_permutation(S.begin(), S.end()));

        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends