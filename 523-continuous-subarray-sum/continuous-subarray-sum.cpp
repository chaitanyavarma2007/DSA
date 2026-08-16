class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hmp;

        int preSum = 0;
        hmp[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            int remainder = preSum % k;

            if(hmp.find(remainder) != hmp.end()) {

                if((i - hmp[remainder]) >= 2) {
                    return true;
                }
            }
            else{
                hmp[remainder] = i;
            }  
        }
        return false;
    }
};