/* 
Problem Link: https://practice.geeksforgeeks.org/problems/check-arithmetic-progression1842/1

Check Arithmetic Progression 

Given an array of N integers. Write a program to check whether an arithmetic progression can be formed using all the given elements. 
 
Example 1:
Input: N=4
arr[] = { 0,12,4,8 }
Output: YES
Explanation: Rearrange given array as {0, 4, 8, 12}  which forms an arithmetic progression.

Example 2:
Input: N=4
arr[] = {12, 40, 11, 20}
Output: NO


Constraints:
2 ≤ N ≤ 10^5
*/
  
bool checkIsAP(int arr[], int n){

    set<int> s;
    if(n <= 1) return true;

    int mini = 1e9, sec_mini = 1e9;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);

        if(arr[i] < mini){
           sec_mini = mini;
           mini = arr[i];
        }

        else if(arr[i] > mini && arr[i] < sec_mini) sec_mini = arr[i];
    }

    int d = sec_mini - mini;
    for(int i = 1; i < n; i++){
        int curr = mini+(i*d);
        if(s.count(curr) == 0) return false;
    }

return true;
}


