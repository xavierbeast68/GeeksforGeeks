//* https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
// above article also contains the recursive approach
//* https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        //complete the function here
        
        
        // iterative approach
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return nums[0] < nums[1] ? nums[0] : nums[1];
        }

        int minE = INT_MAX;
        int start = 0, end = n-1;

        while(start <= end){
            if(start == end){
                minE = min(minE, nums[start]);
                break;
            }
            if(start+1 == end){
                minE = min(minE, min(nums[start], nums[end]));
                break;
            }

            int mid = (start + end)/2;
            minE = min(minE, nums[mid]);

            if(nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]){
                break;
            }
            
            if(nums[mid-1] < nums[mid+1]){
                if(nums[mid-1] < nums[end]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            } else{
                start = mid + 1;
            }
        }

        return minE;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends