class Solution {
public:
    string decToBinary(int N){
        string s = "";
        while(N){
            int m = N % 2;
            s += to_string(m);
            N = N / 2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool queryString(string S, int N) {
        if(S.empty()){
            return false;
        }
        for(int i = 1; i <= N; i++){
            if(S.find(decToBinary(i)) == -1){ //利用find來找在S中有沒有存在1~N的子字串
                return false;
            }
        }
        return true;
    }
};