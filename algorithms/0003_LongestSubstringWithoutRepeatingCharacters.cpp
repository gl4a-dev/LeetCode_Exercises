// 3. LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS

// Given a string s, find the length of the longest substring without duplicate characters.

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int longest_size = 0, start_index = 0;

        for(int end_index = 0; end_index < s.size(); end_index++){
            char current_character = s[end_index];

            if(map.find(current_character) != map.end() && map[current_character] >= start_index)
                start_index = map[current_character] + 1;
            
            map[current_character] = end_index;
            longest_size = max(longest_size, end_index - start_index + 1);
        }

        return longest_size;
    }
};

int main(){
    Solution sol;

    string s = "abcabcbb";
    int size = sol.lengthOfLongestSubstring(s);

    cout << size << endl;
}