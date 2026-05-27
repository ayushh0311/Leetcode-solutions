class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto &it:mp){
         for(int i=0;i<min(k,it.second);i++){
            ans.push_back(it.first);
         }
        }
        return ans;
    }
};