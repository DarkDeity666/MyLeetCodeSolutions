#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex; // Stores the last index of each character
        int maxLength = 0;                  // Maximum length of substring found
        int start = 0;                      // Start index of the current window

        for (int i = 0; i < s.length(); ++i) {
            // If the character is already in the map and its index is within the current window
            if (lastIndex.find(s[i]) != lastIndex.end() && lastIndex[s[i]] >= start) {
                // Move the start of the window
                start = lastIndex[s[i]] + 1;
            }

            // Update the last index of the current character
            lastIndex[s[i]] = i;

            // Update the maximum length
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};
