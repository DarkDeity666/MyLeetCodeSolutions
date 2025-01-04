//This solution achieved 0ms in leetCode


class Solution {
public:
    int romanToInt(string s) {
        // Array to store Roman numeral values indexed by their ASCII value
        int roman[128] = {};
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int result = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; ++i) {
            // Compare current value with the next value
            if (roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                result += roman[s[i]];
            }
        }

        // Add the last character value
        result += roman[s[n - 1]];

        return result;
    }
};
