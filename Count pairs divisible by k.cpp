/* 
Problem Link: https://practice.geeksforgeeks.org/problems/count-pairs-in-array-divisible-by-k/1

Count pairs in array divisible by K 

Given an array A[] and positive integer K, the task is to count total number of pairs in the array whose sum is divisible by K.

Example 1:
Input : A[] = {2, 2, 1, 7, 5, 3}, K = 4
Output : 5
Explanation : There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3)

Example 2:
Input : A[] = {5, 9, 36, 74, 52, 31, 42}, K = 3
Output : 7 
Explanation : There are seven pairs whose sum is divisible by 3, i.e, (5, 9), (9, 36), (74, 52), (36, 42), (74, 31), 
(31, 5) and (5, 52).

Constraints :
1 <= N <=10^6
1 <= A[i] <= 10^6
1 <= K <= 100
*/

int countKdivPairs(int A[], int n, int k){

    unordered_map<int, int> mp;
    int cnt = 0;
    for(int i = 0; i < n; i++){ 
        int r1 = A[i]%k;
        int r2 = (k - r1)%k;
        if(mp.count(r2) == 1) cnt += mp[r2];

        mp[r1]++;
    }
return cnt;
}


