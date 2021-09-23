/*
problem Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

class Solution {
public:
    
     bool areSame(map<char, int>& mps, map<char, int>& mpt){
        
        for(auto [ch, freq] : mpt){
            if(freq != mps[ch]) return false;
        }
    return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        map<char, int>mps;             //txt map
        map<char, int>mpt;             //pattern  map
        for( int i = 0; i < p.size(); i++){
            mps[s[i]]++; 
            mpt[p[i]]++;
        }
            
        vector<int>v;
        if(areSame(mps, mpt) == true) v.push_back(0);
        
        int i = 1, j = p.size();
        while (j < s.size()){
            
            mps[s[j]]++;
            mps[s[j - p.size()]]--;
            if(areSame(mps, mpt) == true) v.push_back(i);
            i++; j++;
        }
            
    return v;
    }
};
