//* https://www.geeksforgeeks.org/remove-invalid-parentheses/
//* https://practice.geeksforgeeks.org/problems/remove-invalid-parentheses/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.youtube.com/watch?v=wtoNj0d-OEI


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    unordered_set<string> ans;
    int longest_length = -1;
    void dfs(string s, string temp, int curr_ind, int l_count, int r_count){
        if(curr_ind == s.length()){
            if(l_count == r_count){
                int len = temp.length();
                if( len > longest_length){
                    longest_length = len;
                    ans.clear();
                    ans.insert(temp);
                }
                else if(len == longest_length){
                    ans.insert(temp);
                }
            }
            
            return;
        }

        else{
            if(s[curr_ind] == '('){
                dfs(s, temp + s[curr_ind], curr_ind + 1, l_count + 1, r_count);
                dfs(s, temp, curr_ind + 1, l_count, r_count);
            }
            else if(s[curr_ind] == ')'){
                dfs(s, temp, curr_ind + 1, l_count, r_count);

                if(l_count > r_count){
                    dfs(s, temp + s[curr_ind], curr_ind + 1, l_count, r_count + 1);
                }
            }
            else{
                dfs(s, temp + s[curr_ind], curr_ind + 1, l_count, r_count);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        dfs(s, "", 0, 0, 0);


        vector<string> answer;
        for(auto& i : ans){
            answer.push_back(i);
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends