/*
Problem Link: https://leetcode.com/problems/minimum-window-substring/

Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in 
t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window. Since the largest window of s only has one 'a', return empty string.
 
Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
*/

bool solver(map<char, int>& mp1, map<char, int>& mp2){
    for(auto x: mp2){
        int ch_p = x.first, freq_p = x.second;
        if(freq_p > mp1[ch_p]) return false;
    }
return true;
}

string minWindow(string s, string t) {
    int m = s.size(), n = t.size();

    map<char, int> mp1, mp2;
    for(int i = 0; i < n; i++){
        mp2[t[i]]++;
    }

    int len = 1e9;
    int sp = 0, ep = 0;
    int i = 0, j = 0;
    while(i < m){
        mp1[s[i]]++;
        if(solver(mp1, mp2) == 1){
            while(mp1[s[j]] > mp2[s[j]]){
                mp1[s[j]]--;
                j++;
            }

            int curr_len = i-j+1;
            if(curr_len < len){
                len = curr_len;
                sp = j;
                ep = i;
            }
        } 
        i++;
    }

    if(len == 1e9) return "";

return s.substr(sp, ep-sp+1);
}


