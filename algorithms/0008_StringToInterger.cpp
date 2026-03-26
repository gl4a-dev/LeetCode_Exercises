// 8. String to Integer

// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
// Return the integer as the final result.

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s){
        int i = 0, n = s.size();

        while(i < n && s[i] == ' ') i++;

        int signal = 1;
        if(s[i] == '+' || s[i] == '-'){
            signal = (s[i] == '-') ? -1 : 1;
            i++;
        }

        int value = 0;
        int digit;
        while(i < n){
            digit = s[i] - '0';

            if(digit < 0 || digit > 9) break;
            if(value > (INT_MAX - digit)/10) return (signal == 1) ? INT_MAX : INT_MIN;

            value = 10*value + digit;
            i++;
        }

        return signal*value;
    }
};

int main(){
    Solution s;
    cout << s.myAtoi("-42") << endl;
    cout << s.myAtoi("  -42") << endl;
    cout << s.myAtoi("-42c") << endl;
    cout << s.myAtoi("  42c") << endl;
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("425c56") << endl;
    cout << s.myAtoi("9999999999999999999999999999") << endl;
    cout << s.myAtoi("-9999999999999999999999999999") << endl;
}