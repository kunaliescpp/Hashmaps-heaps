/*
Problem Link: https://leetcode.com/problems/sliding-window-maximum/

Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the 
very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
  
Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,-1], k = 1
Output: [1,-1]

Example 4:
Input: nums = [9,11], k = 2
Output: [11]

Example 5:
Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        int n = arr.size(); 
        // step 1 : Next greater of every element
        vector<int>v;
        stack<int>stk;

        stk.push(n-1);
        v.push_back(n);
        for(int i = n-2; i >= 0; i--){
            while(!stk.empty() && arr[i] >= arr[stk.top()]) stk.pop();

            int nextGreater = (stk.empty()) ? (n) : (stk.top());
            v.push_back(nextGreater);
            stk.push(i);
        }
        
        reverse(v.begin(), v.end());
        
        // step 2: Slide window
        vector<int> ans;
        int j = 0, i = k-1;
        int curr = 0;
        while(i < n){
            if(curr == j-1) curr = j;
            while(v[curr] <= i){
                curr = v[curr];
            } 
            
            ans.push_back(arr[curr]); 
            i++; j++;
        }
        
    return ans; 
    }
};


