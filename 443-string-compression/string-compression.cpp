class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int write = 0;

        while(i < chars.size()) {
            char ch = chars[i];
            int count = 0;

            while(i < chars.size() && chars[i] == ch) {
                count++;
                i++;
            }

            chars[write++] = ch;
            if(count > 1) {
                string num = to_string(count);

                for(char c : num) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};