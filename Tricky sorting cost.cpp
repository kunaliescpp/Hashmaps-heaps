/* Problem Link: https://practice.geeksforgeeks.org/problems/morning-assembly3038/0/

Tricky Sorting Cost 

Given an array arr[] of N elements containing first N positive integers. You have to sort the integers in 
ascending order by the following operation. Operation is to pick an integer and place it at end or at start. 
Every such operation increases cost by one. The task is to sort the array in the minimum cost

Example 1:
Input: N = 3
arr = {2, 1, 3}
Output: 1
Explaination: Place 1 at start.

Example 2:
Input: N = 4
arr = {4, 3, 1, 2}
Output: 2
Explaination: First place 3 at end then 4 at end.

Constraints:
1 ≤ N ≤ 105
1 ≤ arr[i] ≤ 105
*/

//Similar Question = Arrange students in morning assembly in increasing order of their height

//Approach : numOperations = n - ok     where ok = length of LIS

int sortingCost(int n, int arr[]){

  unordered_map<int, int> mp;

  int maxi = 0;
  for(int i = 0; i < n; i++){

      if(mp.count(arr[i]-1) == 1){
          mp[arr[i]] = mp[arr[i]-1] + 1;
      } else {
          mp[arr[i]] = 1;
      }

      maxi = max(maxi, mp[arr[i]]);
  }

  int cnt = n - maxi;

return cnt;
}
