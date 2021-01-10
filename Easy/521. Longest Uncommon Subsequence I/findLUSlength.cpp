/*
	這題只要看懂題目的意思就能解了
	當兩個字串a,b求他們非共同的子字串
	如果a,b相等，代表他們沒有非共同的子字串 => 直接返回-1
	如果a,b不相等，就返回a和b長度較長的(因為a不等於b 所以兩者就是相異的子序列)
*/

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};