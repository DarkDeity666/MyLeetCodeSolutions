//This solution Achieved 7ms in leetCode


class Solution {
public:
    int romanToInt(string s) {
        // Direct mapping of Roman numerals to their integer values
        auto getValue = [](char ch) -> int {
            switch (ch) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        };

        int result = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current value is less than the next value, subtract it
            if (i < n - 1 && getValue(s[i]) < getValue(s[i + 1])) {
                result -= getValue(s[i]);
            } else {
                result += getValue(s[i]);
            }
        }
        
        return result;
    }
};
