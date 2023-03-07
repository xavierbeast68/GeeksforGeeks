//* https://practice.geeksforgeeks.org/problems/word-break1352/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    vector<string> ans;
    void dfs(string temp, string s, vector<string>& dict, int ind, bool& check){
        if(ind == s.length()){
            check = true;
            return;
        }
        
        string t = "";
        for(int i = ind; i <= s.length(); ++i){
            t += s[i];
            if(isValid(dict, t)){
                dfs(temp+t+(((i+1) == s.length())?"":" "), s, dict, i+1, check);
                if(check == true){
                    break;
                }
            }
        }
    }
    bool isValid(vector<string>& dict, string t){
        for(int i = 0 ; i < dict.size() ; ++i){
            if(dict[i].compare(t) == 0){
                return true;
            }
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        bool check = false;
        dfs("", A, B, 0, check);
        return check;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends