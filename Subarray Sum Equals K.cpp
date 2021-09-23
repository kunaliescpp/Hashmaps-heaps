/*
Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2


Constraints:
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int , int>um;                     //sum vs sumfreq
        
        int sum = 0;
        int cnt = 0;
        
        um[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            
            sum+= nums[i];
            
            if(um.find(sum-k) != um.end()) cnt+= um[sum-k];
             
                um[sum]++;
        }
    
    return cnt;
    }
};
