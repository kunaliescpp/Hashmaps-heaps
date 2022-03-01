/*
Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
  
Example 2:
Input: s = "abba"
Output: 2


Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/

int lengthOfLongestSubstring(string str) {
    int n = str.size();

    map<char, int> mp;
    int len = 0;
    int i = 0, j = 0;
    while(i < n){
        if(mp.count(str[i]) == 1){
            int prv_idx = mp[str[i]];
            if(prv_idx >= j) j = prv_idx+1;
        }

        len = max(len, i-j+1);
        mp[str[i]] = i;
        i++;
    }

return len;
}


