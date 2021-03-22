class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        for(char i : s){
            if(i >= '0' && i <= '9'){
                st.insert(i - '0');
            }
        }
        priority_queue <int> pq; 
        for(int i : st){
            pq.push(i);
        }
        if(pq.size() < 2){
            return -1;
        }
        pq.pop();
        int ans = pq.top();
        return ans;
    }
};