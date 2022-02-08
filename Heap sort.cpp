/* Problem Link: https://www.codingninjas.com/codestudio/problems/heap-sort_1262153

Heap Sort

You are given an array ‘ARR’ consisting of 'N' integers, and your task is to sort the given array in non-decreasing order using the 
Heap sort algorithm.

Constraints:
1 <= T <= 10
1 <= N <= 10^5
-10^9 <= ARR[i] <= 10^9

Sample Input 1:
1
4 
10 7 8 11
Sample Output 1:
7 8 10 11
Explanation Of Sample Input 1: For the first test case, the array [10,7,8,11] will be converted into [7,8,10,11] after 
arranging into non-decreasing order.
  
Sample Input 2:
1
5
5 -2 3 -1 8
Sample Output 2: -2 -1 3 5 8
Explanation Of Sample Input 2: For the first test case, the array [5,-2,3,-1,8] will be converted into [-2,-1,3,5,8] after
arranging into non-decreasing order. 
*/
  
void maxHeapify(vector<int> &arr, int n, int i) {
    
    int largest = i, left = 2*i+1, right = 2*i+2;
    if(left < n && arr[largest] < arr[left]) largest = left;
    if(right < n && arr[largest] < arr[right]) largest = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr, int n){
    for(int i = (n-2)/2; i >= 0; i--){              // parent = (n-1)/2 
        maxHeapify(arr, n, i);      
    }
}

vector<int> heapSort(vector<int>& arr, int n){
    
    buildHeap(arr, n);

    for(int i = n-1; i >= 1; i--){ 
        swap(arr[0], arr[i]);
        // remove arr[i] from max_heap
        maxHeapify(arr, i, 0);
    }
return arr;
}

