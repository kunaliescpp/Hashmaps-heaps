/* 
problem Link : https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1

Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:
Input: n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), (4, 5) ,(2, 5), (0, 5), (1, 6)

Example 2:
Input: n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the subarray is (3,4).

Constraints:
1 <= n <= 106
0 <= A[i] <= 1
*/

long long int countSubarrWithEqualZeroAndOne(int arr[], int n){

   unordered_map<int, int> mp;

   int ans = 0;
   mp[0] = 1;
   int cnt1 = 0, cnt0 = 0;       // prefix cnt of 0 & 1
   for(int i = 0; i < n; i++){
       if(arr[i] == 1) cnt1++;
       else cnt0++;

       int diff = cnt1 - cnt0;

       if(mp.count(diff) == 1) ans += mp[diff];
       mp[diff]++;
   }

return ans;
}


