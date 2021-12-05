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

class Solution {
public:
    
    bool isPossible(map<char, int>& mpt, map<char, int>& mps){
        
        for(auto [ch, freq] : mpt){
            if(freq > mps[ch]) return false;
        }
    return true;
    }
    
    string minWindow(string s, string t) {
        
        map<char, int> mpt, mps;
        for(int i = 0; i < t.size(); i++){
            mpt[t[i]]++;
        }
    
        int i = 0, j = 0, start;
        int len = INT_MAX;
        while(j < s.size()){
            
            mps[s[j]]++;
            if(isPossible(mpt, mps) == true){
               // ok and smallest string
               while(mps[s[i]] > mpt[s[i]]){
                   mps[s[i]]--;
                   i++;
               } 
                
               int curr_len = j - i + 1;
                if(curr_len < len){
                    len = curr_len;
                    start = i;
                }
            }    
            j++;
        } // while loop ends here
    return len == INT_MAX ? "" : s.substr(start, len);
    }
};


