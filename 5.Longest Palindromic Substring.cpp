#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1; // Adjust for over-expansion
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes
            expandAroundCenter(i, i);
            // Even length palindromes
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
