/*
Problen Link: https://leetcode.com/problems/trapping-rain-water/

Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap
after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/


class Solution {
public:
 // Time complexity : Θ(n)  space complexity : Θ(n)
    int trap(vector<int>& height) {
    
        int n = height.size();
        if(n == 0) return 0;
        
        int left_max[n], right_max[n];
      
        left_max[0] = height[0];
        for(int i = 1; i < n; i++){
            left_max[i] = max(height[i], left_max[i-1]);
        }
    
        
        right_max[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            right_max[i] = max(height[i], right_max[i+1]);
        }
    
        int cnt = 0;
        for(int i = 1; i < n-1; i++){
            cnt += (min(left_max[i], right_max[i]) - height[i]);
        }
    return cnt;
    }
};


