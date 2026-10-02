class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hmp;
        hmp.insert({'I', 1});
        hmp.insert({'V', 5});
        hmp.insert({'X', 10});
        hmp.insert({'L', 50});
        hmp.insert({'C', 100});
        hmp.insert({'D', 500});
        hmp.insert({'M', 1000});

        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i == s.size() - 1) {
                ans += hmp[s[i]];
            }
            else if (hmp[s[i]] >= hmp[s[i+1]]) {
                ans += hmp[s[i]];
            }
            else {
                ans -= hmp[s[i]];
            }
        }
        return ans;
    }
};