#include <string>
#include <cctype>
#include <climits>

class Solution {
public:
    int myAtoi(std::string str) {
        // Check if the string is empty
        if (str.empty()) {
            return 0; // Assuming invalid input returns 0, not -1 (follow platform conventions)
        }

        int result = 0;  // Stores the integer converted value for str
        int i = 0;       // Current character pointer for the string
        int sign = 1;    // Determines if the string is positive or negative

        // Skip leading whitespaces
        while (i < str.size() && isspace(str[i])) {
            i++;
        }

        // Check the sign of the string
        if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        // Traverse the entire string and convert it into an integer
        while (i < str.size() && isdigit(str[i])) {
            int digit = str[i] - '0';

            // Check for overflow/underflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN; // Return limits on overflow/underflow
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
