/*https://practice.geeksforgeeks.org/problems/anagram-palindrome4720/1

Anagram Palindrome 

Given a string S, Check if characters of the given string can be rearranged to form a palindrome. 

Example 1:
Input: S = "geeksogeeks"
Output: Yes
Explanation: The string can be converted into a palindrome: geeksoskeeg

Example 2:
Input: S = "geeksforgeeks"
Output: No
Explanation: The given string cannot be converted into a palindrome.

Constraints:
1 <= |S| <= 10^6
*/

int isPossible (string s){
    
    unordered_map< char, int> mp;
    for(char c : s){
        mp[c]++;
    }
    
    int cnt = 0;
    for(auto x : mp){
        if(x.second % 2 == 1) cnt++; 
    }
    
    if(cnt > 1) return 0;
    
return 1;
}
