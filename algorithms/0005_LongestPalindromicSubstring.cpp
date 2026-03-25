// 5. LONGEST PALINDROMIC SUBSTRING

// Given a string s, return the longest palindromic substring in s.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();
        //cout << t << endl;
        
        vector<int> palindromeMaxRadio(n, 0);
        int center = 0;
        int radios = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radios) palindromeMaxRadio[i] = min(radios - i, palindromeMaxRadio[mirror]);

            int left = i - (palindromeMaxRadio[i] + 1);
            int right = i + (palindromeMaxRadio[i] + 1);

            while (left >= 0 && right < n && t[left] == t[right]) {
                palindromeMaxRadio[i]++;
                left--;
                right++;
            }

            if (i + palindromeMaxRadio[i] > radios) {
                center = i;
                radios = i + palindromeMaxRadio[i];
            }

            // cout << "t[" << center << ", " << radios << "]: " << t[center] << " - ";
            // for(int i = 0; i < n; i ++)
            //     cout << palindromeMaxRadio[i];
            // cout << endl;
        }


        int maxLen = 0;
        int centerIndex = 0;

        for (int i = 0; i < n; i++) {
            if (palindromeMaxRadio[i] > maxLen) {
                maxLen = palindromeMaxRadio[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl;
}