//* https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-110/problems
//* https://www.youtube.com/watch?v=0Mf6t1QBDwU

class Solution {
public:
    int separateStones(int N, int K, vector<int> &arr) {
        // code here
        
        int cntWhite = 0, cntBlack = 0;
        
        for(int i = 0; i < N; i++){
            if(arr[i] == 0){
                cntWhite++;
            }
            else{
                cntBlack++;
            }
        }
        
        int whiteBoxes = cntWhite/K + (cntWhite%K > 0 ? 1 : 0);
        int blackBoxes = cntBlack/K + (cntBlack%K > 0 ? 1 : 0);
        
        return whiteBoxes + blackBoxes;
    }
};