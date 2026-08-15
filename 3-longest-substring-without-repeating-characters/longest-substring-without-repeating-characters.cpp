class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        if (n == 0) return 0;

        unordered_map <char, int> hmp;
        int left = 0;
        for(int right = 0; right < n; right++) {
            hmp[s[right]]++;
            while(hmp[s[right]] > 1) {
                hmp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};