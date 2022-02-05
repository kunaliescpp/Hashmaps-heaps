/*
problem Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters 
exactly once.

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
    
bool solver(unordered_map<char, int>& mps, unordered_map<char, int>& mpt){
    for(auto &x : mpt){
        if(mps[x.first] != mpt[x.first]) return false;
    }

return true;
}

vector<int> findAnagrams(string s, string t) {

    int m = s.size(), n = t.size();
    unordered_map<char, int> mps, mpt;
    for(int i = 0; i < t.size(); i++){
        mps[s[i]]++;
        mpt[t[i]]++;
    }

    vector<int> v;
    if(solver(mps, mpt) == true) v.push_back(0);

    int i = n, j = 1;
    while(i < m){
        mps[s[i]]++;
        mps[s[j-1]]--;
        if(solver(mps, mpt) == true) v.push_back(j);
        i++; j++;
    }

return v;
}


