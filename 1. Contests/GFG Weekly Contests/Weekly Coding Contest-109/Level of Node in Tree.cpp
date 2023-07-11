//* https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-109/problems
//* https://www.youtube.com/watch?v=_M9IOrbQG04&ab_channel=GeeksforGeeksPractice

class Solution {
public:
    long long findLevel(long long N) {
        // code here
        
        long long currLevel = 0;
        long long currLevelNodes = 1;
        long long totalNodes = 0;
        long long p = 1;
        while(totalNodes < N){
            currLevel++;
            currLevelNodes = (currLevelNodes * currLevel);
            totalNodes += currLevelNodes;
        }
        
        return currLevel;
    }
};