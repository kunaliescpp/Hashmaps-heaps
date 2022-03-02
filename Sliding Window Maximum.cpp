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

vector<int> solver(vector<int> v){
    int n = v.size();

    vector<int> ng;
    stack<int> stk;
    stk.push(n-1);
    ng.push_back(n);
    for(int i = n-2; i >= 0; i--){
        while(!stk.empty() && v[i] >= v[stk.top()]){
            stk.pop();
        }

        if(stk.empty()) ng.push_back(n);
        else ng.push_back(stk.top());
        stk.push(i);
    }

    reverse(ng.begin(), ng.end());
return ng;
}

vector<int> maxSlidingWindow(vector<int>& v, int k) {
    int n = v.size();

    vector<int> ng = solver(v);
    vector<int> ans;
    int i = k-1, j = 0;
    int ptr = 0;
    while(i < n){
        if(ptr == j-1) ptr = j;
        while(ptr < i){
            int curr = ptr, next = ng[ptr];
            if(next <= i && v[curr] < v[next]) ptr = next;
            else break;
        }
        ans.push_back(v[ptr]);
        i++; j++;
    }

return ans;
}


