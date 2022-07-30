int t[14][10002];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N=coins.size();
        
        //initialization
        for(int i=0;i<N+1;i++){
            for(int j=0;j<amount+1;j++){
                
                if(j==0){
                    t[i][j]=0;
                }
                
                if(i==0){
                    t[i][j]=INT_MAX-1;
                }
                if(i==1 && j>0){
                    // 2nd row
                    if(j%coins[0]==0){
                        t[i][j]=j/coins[0];
                    }
                    else{
                        t[i][j]=INT_MAX-1;
                    }
                }
            }
        }
        
        for(int i=2;i<N+1;i++){
            for(int j=1;j<amount+1;j++){
                
                if(coins[i-1]<=j){
                    t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);    
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        if(t[N][amount]==INT_MAX-1){
            return -1;
        }
        else
            return t[N][amount];
    }
};