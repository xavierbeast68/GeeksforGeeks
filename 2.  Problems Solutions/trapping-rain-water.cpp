//* https://www.geeksforgeeks.org/trapping-rain-water/
//* https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    void leftmax_boundary(int left[], int arr[], int n){
        left[0] = 0;

        for(int i = 1; i < n; ++i){
            left[i] = max(left[i-1], arr[i-1]);
        }
    }
    void rightmax_boundary(int right[], int arr[], int n){
        right[n-1] = 0;

        for(int i = n-2; i >= 0; --i){
            right[i] = max(right[i+1], arr[i+1]);
        }
    }
    
    public:
    long long trappingWater(int arr[], int n){
        // code here

        // creating auxillary arrays
        int left_boundary[n]; leftmax_boundary(left_boundary, arr, n);
        int right_boundary[n]; rightmax_boundary(right_boundary, arr, n);

        long long trapped_water = 0;
        for(int i = 1; i < n-1; ++i){
            int water_level = min(left_boundary[i], right_boundary[i]);
            int water_quantity = water_level - arr[i];

            if(water_quantity > 0){
                trapped_water += water_quantity;
            }
        }

        return trapped_water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends