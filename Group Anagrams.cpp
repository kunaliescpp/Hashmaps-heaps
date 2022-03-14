/*
Problem Link: https://leetcode.com/problems/group-anagrams/

Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original 
letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
   int n = strs.size();

    map<vector<int>, vector<string>> mp;
    for(int i =  0; i < n; i++){
        // checking the freq of curr string
        string str = strs[i];
        vector<int>freq(26, 0);
        for(char c: str) freq[c-'a']++;

        mp[freq].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto x: mp){
        ans.push_back(x.second);
    }
return ans;
}


