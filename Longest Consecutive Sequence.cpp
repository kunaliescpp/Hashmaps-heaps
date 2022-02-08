/*
Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/

Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        
        int n = arr.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++) s.insert(arr[i]);
        
        int len = 0;
        for(int i = 0; i < n; i++){
            int val = arr[i];
            if(s.count(val-1) == 0){
                while(s.count(val+1) == 1) val++;
            
                len = max(len, val-arr[i]+1);
            }
        }
    
    return len;
    }
};


