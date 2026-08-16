class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        vector<long long> ans(nums.size(), 0);
        unordered_map<int, pair<long long, long long>> hmp;

        for(int i = 0; i < nums.size(); i++) {

            ans[i] += (long long)i * hmp[nums[i]].first - hmp[nums[i]].second;

            hmp[nums[i]].first++;
            hmp[nums[i]].second += i;
        }

        hmp.clear();

        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] += hmp[nums[i]].second - (long long)i * hmp[nums[i]].first;

            hmp[nums[i]].first++;
            hmp[nums[i]].second += i;
        }
        return ans;
    }
};