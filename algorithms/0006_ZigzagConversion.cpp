// 6. ZIGZAG CONVERSION

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    string convert(string s, int numRows){
        if(numRows == 1) return s;

        int n = s.size();
        string zz_string;

        int index0 = 0;
        while(index0 < n){
            //cout << s[index0];
            zz_string.push_back(s[index0]);
            index0 += 2*(numRows - 1);
        }
        //cout << endl;

        int line, index;
        bool d;
        for(int i = 1; i < numRows; i++){
            int line = i;
            int index = i;
            d = true;
            while(index < n){
                //cout << s[index];
                zz_string.push_back(s[index]);
                if(d == true){
                    d = false;
                    if(2*(numRows - line - 1) <= 0) index += 2*line;
                    else index += 2*(numRows - line - 1);
                } else {
                    d = true;
                    index += 2*line;
                }
            }
            //cout << endl;
        }
        return zz_string;
    }
};

int main(){
    Solution s;
    cout << s.convert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3) << endl;
    cout << s.convert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 4) << endl;
    cout << s.convert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 5) << endl;
}