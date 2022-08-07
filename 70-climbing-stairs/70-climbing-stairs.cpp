int t[46];

class Solution {
public:
    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    int climbStairs(int n) {
        
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(t[n]!=-1){
            return t[n];
        }
        int ans1 = climbStairs(n-1);
        int ans2 = climbStairs(n-2);
        return t[n] = ans1+ans2;
    }
};