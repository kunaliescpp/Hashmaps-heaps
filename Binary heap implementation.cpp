/*
Problem Link: https://practice.geeksforgeeks.org/problems/operations-on-binary-min-heap/1#

Binary Heap Operations 

A binary heap is a Binary Tree with the following properties:
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left 
as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present 
in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey, deleteKey, and 
extractMin on the Binary Min Heap and call them as per the query given below:
1) insertKey(x): A query of this type means to insert an element in the min-heap with value x.
2) deleteKey(x): A query of this type means to remove an element at position x from the min-heap.
3) extractMin(): A query like this removes the min element from the min-heap and prints it .

Example 1:
Input: 
Q = 7
Queries: insertKey(4), insertKey(2), extractMin(), insertKey(6), deleteKey(0), extractMin(), extractMin()
Output: 2 6 - 1
Explanation: In the first test case for query 
insertKey(4) the heap will have {4}  
insertKey(2) the heap will be {2 4}
extractMin() removes min element from heap ie 2 and prints it now heap is {4} 
insertKey(6) inserts 6 to heap now heap is {4 6}
deleteKey(0) delete element at position 0 of the heap,now heap is {6}
extractMin() remove min element from heap ie 6 and prints it now the heap is empty
extractMin() since the heap is empty thus no min element exist so -1 is printed.

Example 2:
Input: 
Q = 5
Queries: insertKey(8), insertKey(9), deleteKey(1), extractMin(), extractMin(), buildheap()
Output: 8 -1

Constraints:
1 <= Q <= 10^4
1 <= x <= 10^4
*/

Struct MinHeap{

    int arr[];
    int size;
    int capacity;
    
    MinHeap(int c){
        arr = new int[c];
        size = 0; 
        capacity = c; 
    }
    
    int left(int i){
        return 2*i + 1;
    }
    
    int right(int i){
        return 2*i + 2;
    }
    
    int parent(int i){
        return (i-1)/2;
    }

//=> functions : extractMin(), deletekey(x), insertkey(x), minHeapify() 
    // Time Complexity : ϴ(1) + O(log h)
    int extractMin() {

        if(heap_size == 0) return -1;

        if(heap_size == 1){
            heap_size--;
            return harr[0];
        }

        int ans = harr[0];
        swap(harr[0], harr[heap_size-1]);
        heap_size--;
        MinHeapify(0);

    return ans;    
    }

    // Time Complexity: O(log n) + O(log n)
    void deleteKey(int i){

        if(i >= heap_size) return;

        decreaseKey(i, INT_MIN);

        extractMin();
    }

    // Time Complexity: O(log h) = O(log n)
    void insertKey(int x){

        if(heap_size == capacity) return;

        heap_size++;
        harr[heap_size-1] = x;

        int i = heap_size-1;
        while(i != 0 && harr[parent(i)] > harr[i]){
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    //Time Complexity : O(log n)
    void decreaseKey(int i, int new_val){  

        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    // Time complexity : O(h) = O(log n)
    // Space complexity : O(h)
    void MinHeapify(int i){

        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l] < harr[smallest]) smallest = l;
        if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    void BuildHeap(int i){

        for(int i = (size-2)/2; i >= 0; i--){     //size-1-1 / 2
            minHeapify(i);
        }
    }
};
