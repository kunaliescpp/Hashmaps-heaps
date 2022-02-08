/*
Problem Link: https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/

Largest subarray with contiguous elements 

Given an array of integers. Find the length of the longest subarray which contains numbers that can be arranged in a continuous sequence.
No duplicates allowed.

Examples: 
Input:  arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input:  arr[] = {10, 12, 12, 10, 10, 11, 10};
Output: Length of the longest contiguous subarray is 2 
*/

int solver(vector<int>& v){
 
    int n = v.size();
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        
        int mini = v[i];
        int maxi = v[i];
        set<int> s;
        s.insert(v[i]);
        for(int j = i+1; j < n; j++){
            if(s.count(v[j]) == 1) break;

            mini = min(mini, v[j]);
            maxi = max(maxi, v[j]);
            if(maxi-mini+1 == j-i+1){
                int len = j-i+1;
                ans = max(ans, len);
            }

            s.insert(v[j]);
        }
    }

return ans; 
}


