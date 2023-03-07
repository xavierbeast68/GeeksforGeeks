//* https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/

// Complexity-> O(m*n*logn)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCommon(vector<vector<int> >& matrix) {
        // Code here
        
        int m = matrix.size();
        int n = matrix[0].size();
        int ans;
        for(int i = 0 ; i < n ; i++){
            int x = matrix[0][i];
            ans = x;
            for(int j = 1 ; j < m ; j++){
                bool found = binary_search(matrix[j].begin(), matrix[j].end(), x);
                if(found == false){
                    ans = -1;
                    break;
                }
            }
            if(ans == x){
                break;
            }
        }
        return ans;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>> matrix(m, vector<int>(n,0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.findCommon(matrix);
		cout << ans <<'\n';
	}
	return 0;
}

// inputs->
/*
1
4 5
1 2 3 4 5
2 4 5 8 10
3 5 7 9 11
1 3 5 7 9
*/
// outputs-> 5