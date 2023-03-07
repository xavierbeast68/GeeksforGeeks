//* Subset Sum
//! https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10&ab_channel=takeUforward
//! https://practice.geeksforgeeks.org/problems/subset-sums2234/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void dfs(vector<int>& answer, vector<int>& arr, int n, int sum, int i){
        if(i == n){
            answer.push_back(sum);
            return;
        }
        
        dfs(answer, arr, n, sum + arr[i], i+1);
        dfs(answer, arr, n, sum, i+1);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int> answer;
        dfs(answer, arr, N, 0, 0);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends