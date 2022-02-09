/* 
Problem Link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-all-occurrences-of-a-most-frequent-element2258/1

Smallest subarray with all occurrences of a most frequent element 

Given an array A. Let X be an element in the array which has the maximum frequency. The task is to find the smallest
sub segment of the array which also has X as the maximum frequency element.

Note: if two or more elements have the same frequency (i.e., maximum frequency) and the same sub segment size then 
print the sub segment which occurs first in the array.

Example 1:
Input : A[] = {1, 2, 2, 3, 1}
Output : 2 2
Explanation: Note that there are two elements that appear two times, 1 and 2.The smallest window for 1 is whole array and
smallest window for 2 is {2, 2}. Since window for 2 is smaller, this is our output.

Example 2:
Input : A[] = {1, 4, 3, 3, 5, 5} 
Output : 3 3 

Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
*/

vector<int> smallestSubsegment(int arr[], int n){

    unordered_map<int, int> mp1;
    unordered_map<int, pair<int, int>> mp2;
    int max_freq = 0;
    for(int i = 0; i < n; i++){
        if(mp2.count(arr[i]) == 0){
            mp2[arr[i]] = {i, i};
        } else{
            mp2[arr[i]].second = i;
        }
        mp1[arr[i]]++;
        max_freq = max(max_freq, mp1[arr[i]]);
    }

    int min_len = 1e9;
    int cand = -1;
    for(int i = 0; i < n; i++){
        int ele = arr[i], freq = mp1[arr[i]];
        if(freq == max_freq){
            int si = mp2[ele].first;
            int ei = mp2[ele].second;
            int len = (ei-si+1);
            if(len < min_len){
                cand = ele;
                min_len = len;
            }
        }
    }

    int si = mp2[cand].first, ei = mp2[cand].second;
    vector<int> ans;
    for(int i = si; i <= ei; i++){
        ans.push_back(arr[i]);
    }

return ans;
}
        

