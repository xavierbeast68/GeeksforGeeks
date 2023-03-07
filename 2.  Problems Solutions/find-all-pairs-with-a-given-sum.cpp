//* https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
//* https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/
//* https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here

        vector<pair<int, int>> answer;

        unordered_map<int, int> ump;
        for (int i = 0; i < N; i++)
        {
            ump[A[i]]++;
        }
        for (int i = 0; i < M; i++)
        {
            if (ump.find(X - B[i]) != ump.end())
            {
                answer.push_back(make_pair(X - B[i], B[i]));
            }
        }
        sort(begin(answer), end(answer));
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        int N, M, X;
        cin >> N >> M >> X;
        int A[N], B[M];

        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        vector<pair<int, int>> vp = ob.allPairs(A, B, N, M, X);
        int sz = vp.size();
        if (sz == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < sz; i++)
            {
                if (i == 0)
                    cout << vp[i].first << " " << vp[i].second;
                else
                    cout << ", " << vp[i].first << " " << vp[i].second;
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends