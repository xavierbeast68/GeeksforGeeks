//* https://www.geeksforgeeks.org/combinational-sum/
//* https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//! https://www.youtube.com/watch?v=OyZFFqQtu98&ab_channel=takeUforward
//! https://takeuforward.org/data-structure/combination-sum-1/
//! https://leetcode.com/problems/combination-sum/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    vector<vector<int>> ans;
    void dfs(vector<int>& temp, vector<int>& candidates, int target, int ind){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidates[ind] <= target){
            temp.push_back(candidates[ind]);
            dfs(temp, candidates, target - candidates[ind], ind);
            temp.pop_back(); 
        }
        dfs(temp, candidates, target, ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        vector<int> temp;
        sort(A.begin(), A.end());
        
        // remove duplicates
        A.erase(unique(A.begin(), A.end()), A.end());
        
        dfs(temp, A, B, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends