//* https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-110/problems
//* https://www.youtube.com/watch?v=0Mf6t1QBDwU

class Solution {
public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        // code here
        
        stack<pair<int,int>> st;
        
        for(int i = 0; i < N; i++){
            pair<int,int> p = {color[i], radius[i]};
            if(!st.empty() && st.top() == p){
                st.pop();
            }
            else{
                st.push(p);
            }
        }
        
        return st.size();
    }
};