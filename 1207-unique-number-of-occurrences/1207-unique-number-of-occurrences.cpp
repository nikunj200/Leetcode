class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int num = arr[0];
        int count=0;
        vector<int> occ;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==num){
                count++;
            }
            else{
                occ.push_back(count);
                num = arr[i];
                count=1;
            }
        }
        occ.push_back(count);
        sort(occ.begin(),occ.end());
        for(int i=0;i<occ.size()-1;i++){
            if(occ[i]==occ[i+1]){
                return false;
            }
        }
        return true;
    }
};