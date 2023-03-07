//* https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
//* https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1
//* https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        
        vector<int> answer(k);
        priority_queue<int,vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }

        while(pq.size() > k){
            pq.pop();
        }
        
        int i = k-1;
        while(pq.size() > 0){
            answer[i] = pq.top();
            i--;
            pq.pop();
        }
        
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends