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

    //step 1 
    bool neg = false;
    if(num > 0 && den < 0) neg = true;
    else if(num < 0 && den > 0) neg = true;

    string ans = "";
    if(neg == true) ans += "-"; 

    num = abs(num);
    den = abs(den);

    // step 2
    ans += to_string(num/den);
    int rem = num % den;
    if(rem == 0) return ans;

    ans += ".";
    unordered_map<int, int> mp;
    while(rem != 0){
        if(mp.count(rem) == 1){
            ans += ")";
            ans.insert(mp[rem], "(");
            break;
        } else{
            mp[rem] = ans.size();

            // if(num < den) rem = num 
            rem = rem*10;                         // rem = num = 40*10
            ans+= to_string(rem / den);           // ans+= (400/333)
            rem = rem % den;                      // rem = num = 67
        }
    }

return ans;  
}


