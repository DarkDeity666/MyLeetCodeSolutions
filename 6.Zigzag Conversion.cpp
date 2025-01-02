#include <string>
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        std::string result;
        result.reserve(s.length()); 

        int cycleLen = 2 * numRows - 2; 

        for (int row = 0; row < numRows; ++row) {
            for (int j = row; j < s.length(); j += cycleLen) {
                result += s[j]; 
                int diagonalIdx = j + cycleLen - 2 * row;
                if (row > 0 && row < numRows - 1 && diagonalIdx < s.length()) {
                    result += s[diagonalIdx];
                }
            }
        }
        return result;
    }
};
