/*
    這題就是貪心法。
    最重的可能可以一個人坐一艘船，如果重的人上去後可能還夠塞一個輕的，所以我們只要將數組由小到大排序
    並且使用兩個指針i,j分別指向最瘦的跟最胖的人，因為胖子是一定要先上船 所以j--是一定有的
    如果能夠在上去一個瘦的i才必須+1，然後最後結果+1。
    time complexity: O(nlogn)
    space complexity: O(1)
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int n = people.size();
        int i = 0;
        int j = n-1;
        sort(people.begin(), people.end());
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
            }
            j--;
            ans++;
        }
        return ans;
    }
};