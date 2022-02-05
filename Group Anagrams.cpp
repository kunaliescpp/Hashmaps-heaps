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
  
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        map< map<char,int> , vector<string>>bmp;
     
        for( auto i: strs){
            map<char,int>mp;
            for(auto j: i){
                mp[j]++;
            }
           bmp[mp].push_back(i);
        }
    
        vector<vector<string>>v;
        for(auto x: bmp){
            v.push_back(x.second);
        }
    return v;
    }
};


