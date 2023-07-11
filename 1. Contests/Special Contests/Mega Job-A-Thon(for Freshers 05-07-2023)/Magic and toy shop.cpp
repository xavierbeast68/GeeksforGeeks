//* https://practice.geeksforgeeks.org/contest/megajob-a-thon-hiring-challenge-freshers/problems
//* https://www.youtube.com/watch?v=m6Nr1blCYh4

class Solution{   
public:
    int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price){
        
        long long sum = 0;
        multiset<int> dis;
        for(int i = 0; i < n; i++){
            sum += price[i];
            
            dis.insert(price[i]-magical_price[i]);
        }
        
        if(sum <= m){
            return 0;
        }
        
        vector<int> vec(n);
        int i = n-1;
        for(auto it : dis){
            vec[i] = it;
            i--;
        }
        
        int times = 0;
        for(auto it : vec){
            if(sum <= m){
                break;
            }
            
            times++;
            sum -= it;
        }
        
        if(sum > m) return -1;
        
        return times;
    }
};