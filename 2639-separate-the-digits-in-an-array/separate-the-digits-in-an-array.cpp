class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            vector<int>l;
            while(n){
                int r=n%10;
                l.push_back(r);
                n=n/10;
            }
         for(int i=l.size()-1;i>=0;i--){
            ans.push_back(l[i]);
         }
         l.clear();
        }
        return ans;
    }
};