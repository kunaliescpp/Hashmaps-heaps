/*
Problem Link: https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/

Length of largest subarray with contiguous elements 

Given an array of distinct integers, find length of the longest subarray which contains numbers that can be arranged in a continuous sequence.

Examples: 
Input:  arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input:  arr[] = {14, 12, 11, 20};
Output: Length of the longest contiguous subarray is 2

Input:  arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
Output: Length of the longest contiguous subarray is 5
*/

public static void main(String[] args) {
    Scanner s=new Scanner(System.in);
     //int n=s.nextInt();
     int a[]={10, 12, 11};
     //for(int i=0;i<n;i++) a[i]=s.nextInt();
    int n=a.length;
     int ans=0;
    for(int i=0;i<n;i++) {
        int max=a[i];
        int min=a[i];
        HashSet<Integer> set =new HashSet<>();
        for(int j=i;j<n;j++) {
           max=Math.max(max,a[j]);
           min=Math.min(min,a[j]);
           if(set.contains(a[j])) break;
           else {
               set.add(a[j]);
               if((max-min+1)==(j-i+1)) ans=Math.max(ans,j-i+1);
           }
        }
    }
    System.out.println(ans);
}


