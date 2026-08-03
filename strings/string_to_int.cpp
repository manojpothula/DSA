class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long ans = 0;

        // Skip spaces
        while(i < s.size() && s[i] == ' ')
            i++;

        // Check sign
        if(i < s.size() && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-')
                sign = -1;

            i++;
        }

        // Convert digits
        while(i < s.size() && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');

            // Overflow
            if(sign * ans > INT_MAX)
                return INT_MAX;

            if(sign * ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};