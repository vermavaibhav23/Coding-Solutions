//443. String Compression
//Compiler - C++
//https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int idx = 0;
        int ans = 0;
        while(i < chars.size()) {
            int count = 0;
            char curr_char = chars[i];
            while(i < chars.size() && (curr_char == chars[i])) {
                count++;
                i++;
            }
            chars[idx] = curr_char;
            idx++;
            ans++;
            if(count > 1) {
                string temp = to_string(count);
                for(int a = 0; a < temp.size(); a++) {
                    ans++;
                    chars[idx] = temp[a];
                    idx++;
                }
            }
        }
        return ans;
    }
};