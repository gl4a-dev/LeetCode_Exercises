// 7. REVERSE INTEGER

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed_x = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (reversed_x > INT_MAX / 10 || reversed_x < INT_MIN / 10) return 0;
            if (reversed_x == INT_MAX / 10 && digit > 7) return 0;
            if (reversed_x == INT_MIN / 10 && digit < -8) return 0;

            reversed_x = reversed_x * 10 + digit;
        }

        return reversed_x;
    }
};

int main(){
    Solution s;
    cout << s.reverse(987654321) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(0);
}