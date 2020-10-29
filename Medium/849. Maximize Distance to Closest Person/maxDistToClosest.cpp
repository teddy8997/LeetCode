class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        /*
            這題有3種情況:
            1) 1,0,0,0,1 => 中間的位子是最遠，所以 (j-i) / 2
            2) 1,0,0,0 => i = 0 最右邊的是最遠， 這時j = length = 4 所以 j - i - 1 
            3) 0,0,0,1 => 剛開始 i = -1，第一個人在j = 3 所以 j - i - 1
        */
        int i = -1;
        int maxV = 0;
        for(int j = 0; j < seats.size(); j++){
            if(seats[j] == 1){
                if(i == -1){
                    maxV = max(maxV, j-i-1);
                }else{
                    maxV = max(maxV, (j - i) / 2);
                }
                i = j;
            }
        }
        return max(maxV, (int)seats.size() - i - 1);
    }
};