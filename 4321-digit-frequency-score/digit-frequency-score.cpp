class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int>mp;
        while(n){
            int r=n%10;
            n=n/10;
            mp[r]++;
        }
        int sum=0;
        for(auto &it:mp){
            sum=sum+it.first*it.second;
        }
        return sum;
    }
};