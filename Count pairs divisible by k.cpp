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

int countKdivPairs(int v[], int n, int quo){
    for(int i = 0; i < n; i++){
        int rem = v[i]%quo;
        v[i] = rem;
    }

    map<int, int> mp;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 0 && mp.count(0) == 1) cnt+= mp[0];
        else cnt+= mp[quo-v[i]];

        mp[v[i]]++;
    }

return cnt;
}


