class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]%2!=nums[j]%2){
                    c++;
                }
            }
            ans[i]=c;
        }
        return ans;


    }
};