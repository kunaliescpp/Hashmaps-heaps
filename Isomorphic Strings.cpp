/*
https://leetcode.com/problems/isomorphic-strings/

Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters 
may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
  
Example 2:
Input: s = "foo", t = "bar"
Output: false
  
Example 3:
Input: s = "paper", t = "title"
Output: true
 

Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char>m1;                      // key= s[i], value= t[i]
        set<char>se;                                      // key = t[i]=value= t[i]
       
        for(int i =0; i < s.size(); i++){
            
            if(m1.find(s[i]) != m1.end()){                //if it is already present in map
                if(m1[s[i]] != t[i]){                      // ex: g always contains a which is key and value resp.
                    return false; 
                } 
            }                          
        
            else{                                            
               if(se.count(t[i]) == 1){                      // char of t is should not present already as present
                  return false;                              // char of s is not attached to it till now, so it 
               }                                             // means it is attached to other char.
              
               else{                                             // fresh char should be inserted
                  se.insert(t[i]);
                  m1[s[i]] = t[i];     
               }
           }
        }
    return true;
    }
};


