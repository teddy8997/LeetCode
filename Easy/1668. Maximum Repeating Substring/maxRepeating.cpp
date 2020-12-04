/*
	Time complexity: O(n^2)
	Space complexity: O(n)
*/
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string s(word);
        int count = 0;
        while(sequence.find(s) != string::npos){
            s += word;
            count++;
        }
        return count;
    }
};