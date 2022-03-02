/* problem Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"

Example 4:
Input: numerator = 4, denominator = 333
Output: "0.(012)"

Example 5:
Input: numerator = 1, denominator = 5
Output: "0.2"
 
Constraints:
-2^31 <= numerator, denominator <= 2^31 - 1
denominator != 0
*/
  
string fractionToDecimal(int num, int den) {

    //step 1: check negative or not
    bool neg = false;
    if(num > 0 && den < 0) neg = true;
    else if(num < 0 && den > 0) neg = true;

    string str = "";
    if(neg == true) str+= "-"; 
    num = abs(num);
    den = abs(den);

    str+= to_string(num/den);
    int rem = num % den;
    if(rem == 0) return str;

    // step2: if fractional part is repeating or not
    str+= ".";
    map<int, int> mp;  // mp[rem] = quo_size
    while(rem != 0){
        if(mp.count(rem) == 1){
            // idx of num = mp[rem]+1     // test case: num = 1, den = 6
            str.insert(mp[rem]+1-1, "(");
            str+= ")";
            return str;
        } else{
            mp[rem] = str.size();
            str+= ((rem*10)/den)+'0';
            rem = (rem*10)%den;
        }
    }
return str;
}


