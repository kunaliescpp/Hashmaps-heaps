/*
Problem Link: https://leetcode.com/problems/array-of-doubled-pairs/

Array of Doubled Pairs

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false 
otherwise.

Example 1:
Input: arr = [3,1,3,6]
Output: false

Example 2:
Input: arr = [2,1,2,6]
Output: false

Example 3:
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

Example 4:
Input: arr = [1,2,4,16,8,4]
Output: false
 

Constraints:

2 <= arr.length <= 3 * 10^4
arr.length is even.
-10^5 <= arr[i] <= 10^5
*/

class Solution {
public:
    
    static bool cmpAbs(int a, int b){
        
        if(abs(a) < abs(b)) return true;                          //Run test case     4  -2  2  -4
    
    return false;      // a = -4, b = -2  -> return false      
    }
     
    bool canReorderDoubled(vector<int>& arr) {
        
         map<int ,int> mp;
        for(int i: arr) mp[i]++;
        
        sort(arr.begin(), arr.end(), cmpAbs);               //Run test case     2  4  1  8 
    
        for(int i: arr){
            if(mp[i] == 0) continue;
        
            if(mp.count(2*i) == 0 || mp[2*i] == 0) return false;
        
            mp[i]--;
            mp[2*i]--;
        }
        
    return true;
    }
};
