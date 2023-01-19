#include <unordered_set>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, i = 0, j = 0;
        unordered_set<char> chars;
        while (i != s.size() && j != s.size()) {
            if (chars.find(s[j]) == chars.end()) {
                chars.insert(s[j]);
                j++; 
            } else {
                chars.erase(s[i]);
                i++;
            }
            max = (j - i > max) ? j - i : max;
        }
        return max;
    }
};