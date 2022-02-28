/* Problem Link: https://practice.geeksforgeeks.org/problems/check-frequencies4211/1

Check if frequencies can be equal 

Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most 
one character from this string in such a way that frequency of each distinct character becomes same in the string.

Example 1:
Input: s = xyyz
Output: 1 
Explanation: Removing one 'y' will make frequency of each letter 1.

Example 2:
Input: s = xxxxyyzz
Output: 0
Explanation: Frequency can not be made same by removing just 1 character.

Constraints:
1 <= str.length() <= 10^4
*/

bool sameFreq(string s){

    int n = s.size();
    vector<int>freq(26, 0);
    for(char c: s) freq[c-'a']++;

    map<int, int> mp;   // mp[freq] = num_char
    for(int i = 0; i < 26; i++){
        if(freq[i] > 0) mp[freq[i]]++;
    } 

    if(mp.size() == 1) return true;
    else if(mp.size() == 2){
        auto it = mp.begin();
        int x1 = (*it).first, y1 = (*it).second;
        it++;
        int x2 = (*it).first, y2 = (*it).second;
        if(x1 == 1 && y1 == 1) return true;
        else if(y2==1 && (x2==(x1+1))) return true;
        else return false;
    } 

    else return false;
}


