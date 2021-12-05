/* 
Problem Link: https://practice.geeksforgeeks.org/problems/check-if-two-strings-are-k-anagrams-or-not/1

Check if two strings are k-anagrams or not 

Given two strings of lowercase alphabets and a value K, your task is to complete the given function which tells if  
two strings are K-anagrams of each other or not.

Two strings are called K-anagrams if both of the below conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most K characters in a string.

Example:
Input: str1 = "fodr", str2="gork" , k = 2
Output: 1
Explanation: Can change fd to gk

Constraints:
1 ≤ length of String ≤ 10^5
1 ≤ K ≤ length of String
*/

bool areKAnagrams(string s, string p, int k) {

    if(s.size() != p.size()) return false;

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for( int i = 0; i < s.size(); i++){
        mp1[s[i]]++; 
        mp2[p[i]]++;
    }

    int cnt = 0;  
    for(auto x : mp2){
        if(mp1.count(x.first) == 1){
            if(mp2[x.first]-mp1[x.first] > 0) cnt+= (mp2[x.first] - mp1[x.first]);
        } else{
            cnt+= x.second;
        }
    }

    if(cnt <= k) return true;

return false; 
}


