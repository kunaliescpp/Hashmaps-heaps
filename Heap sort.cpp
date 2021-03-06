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
  
void max_heapify(vector<int>& v, int heap_size, int idx){
    int pri = idx;
    int lci = 2*idx+1;
    int rci = 2*idx+2;
    if(lci < heap_size && v[pri] < v[lci]) pri = lci;
    if(rci < heap_size && v[pri] < v[rci]) pri = rci;
    
    if(pri != idx){
        swap(v[idx], v[pri]);
        max_heapify(v, heap_size, pri);
    }
}

vector<int> solver(vector<int>& v){
    int n = v.size();
    
    // step-1: build_heap
    for(int i = (n-1-1)/2; i >= 0; i--){
        max_heapify(v, n, i);
    }
    
    // step-2: first_ele of max_heap = last_ele of sorted array
    for(int i = n-1; i >= 1; i--){
        swap(v[0], v[i]);
        max_heapify(v, i, 0);
    }

return v;
}


