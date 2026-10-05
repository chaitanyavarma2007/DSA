class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> freq;
        int base = 0;
        for(int i = 1; i< nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                base++;
            }
            else {
                int x = min(nums[i], nums[i - 1]);
                int y = max(nums[i], nums[i - 1]);

                freq[{x, y}]++;
            }
        }
        int best = 0;
        for(auto &[p, count] : freq) {
            best = max(best, count);
        }
        return base + best;
    }
};