/*
Problem Link: https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/

Largest subarray with contiguous elements 

Given an array of integers. Find the length of the longest subarray which contains numbers that can be arranged in a continuous sequence.

Examples: 
Input:  arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input:  arr[] = {10, 12, 12, 10, 10, 11, 10};
Output: Length of the longest contiguous subarray is 2 
*/

int findLength(int arr[], int n){
 
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        
        int mini = arr[i];
        int maxi = arr[i];
       
        set<int> s;
        s.insert(arr[i]);
        
        for(int j = i+1; j < n; j++){
            
            if(s.count(arr[j]) == 1) break;
            
            s.insert(arr[j]);
    
            int mini = min(mini, arr[j]);
            int maxi = max(maxi, arr[j]);
            
            if(maxi - mini == j-i){
                int len = j - i + 1;
                ans = max(ans, len);
            }
        }
    }

return ans; 
}


