/*
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> counts;
        for(int c : deck){
            counts[c]++;
        }
        int n = deck.size();
        for(int i = 2; i <= n; i++){
            bool canSpilt = true;
            for(auto &pair : counts){
                if(pair.second % i){
                    canSpilt = false;
                    break;
                }
            }
            if(canSpilt){
                return true;
            }
        }
        return false;
    }
};