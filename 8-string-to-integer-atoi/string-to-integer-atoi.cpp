class Solution {
public:
    int myAtoi(std::string s) {
        int result = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();

        // Skip leading whitespace
        while (i < n && std::isspace(s[i])) {
            i++;
        }

        // Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // Process digits
        while (i < n && std::isdigit(s[i])) {
            int digit = s[i] - '0';
            // Check for overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }

};