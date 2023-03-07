//* https://www.geeksforgeeks.org/maximum-length-substring-having-all-same-characters-after-k-changes/
//* https://practice.geeksforgeeks.org/problems/longest-repeating-character-replacement/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public: // O(n)
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        map<char, int> mp;
        int answer = 0;
        int max_freq = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            mp[s[j]]++;
            int window_length = j - i + 1;
            max_freq = max(max_freq, mp[s[j]]);

            if (i <= j && window_length - max_freq > k)
            {
                mp[s[i]]--;
                i++;
                window_length = j - i + 1;
            }
            answer = max(answer, window_length);
            j++;
        }
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
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends