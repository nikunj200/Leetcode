int t[2502][2502];

class Solution {
public:
    // Solution(){
    //     memset(t,-1,sizeof(t));
    // }    
    
    // int LCS(vector<int> nums1, vector<int> nums2, int m, int n){
    //     if(n==0 || m==0){
    //         return 0;
    //     }
    //     if(t[m][n]!=-1){
    //         return t[m][n];
    //     }
    //     if(nums1[n-1] == nums2[m-1]){
    //         return t[m][n] = 1 + LCS(nums1,nums2,m-1,n-1);
    //     }
    //     else{
    //         return t[m][n] = max(LCS(nums1,nums2,m,n-1),LCS(nums1,nums2,m-1,n));
    //     }
    // }
    
    int LCS(vector<int> nums1, vector<int> nums2, int m, int n){
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(nums1[i-1] == nums2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        
        return t[m][n];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> numsT = nums;
        sort(numsT.begin(),numsT.end());
        int m = nums.size();
        vector<int> nums2;
        
        
        nums2.push_back(numsT[0]);
        for(int i=1;i<numsT.size();i++){
            if(numsT[i]!=numsT[i-1]){
                nums2.push_back(numsT[i]);
            }
        }
        
        int n = nums2.size();
        
        return LCS(nums,nums2,m,n);
    }
};