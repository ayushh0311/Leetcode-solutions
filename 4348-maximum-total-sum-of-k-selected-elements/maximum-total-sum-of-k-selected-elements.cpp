class Solution {
    public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<long long> p(nums.size() + 1);
        int i = 0;
        do {
            if (i >= (int)nums.size()) break;
            p[i + 1] = p[i] + nums[i];
            i++;
        } while (1);

        long long a = p[k], c = 0, r = a;
        int t = min(k, mul);

        i = 0;
        while (i < t) {
            c += 1LL * nums[i] * (mul - i - 1);
            if (a + c > r) r = a + c;
            i++;
        }
        return r;
    }
};



