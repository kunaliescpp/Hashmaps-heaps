/* Problem Link: https://practice.geeksforgeeks.org/problems/digit-multiplier3000/1

Digit multiplier 

Given a positive integer N, find the smallest number 'num' such that the product of all the digits of 'num' is equal to the number N. 
If there's no such number, Print "-1".

Example 1:
Input: N = 100
Output: 455
Explanation: 4*5*5 = 100. There are no numbers less than 455 with the product of it's digit as 100.

Example 2:
Input: N = 26
Output: -1
Explanation: There are no numbers which can form a product of 26 with its digits.

Constraints:
1 <= N <= 109
*/
   
// limitation : every digit should be single (i.e. 0 <= divisor >= 9)
string getSmallest(long long n) {
    if(n == 1) return "1";
    string str = "";
    
    int div = 9;             // smallest combination
    while(n > 1 && div > 1){
        if(n % div == 0){
            str += (char)(div+'0');
            n = n/div;
        } else{
            div--;
        }
    }

    reverse(str.begin(), str.end());
    if(n == 1) return str;

return "-1";
}


