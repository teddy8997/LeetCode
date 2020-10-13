class Solution {
private:
    int h;
    int w;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0){
            return false;
        }
        h = board.size();
        w = board[0].size();
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                if(search(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, const string& word, int x, int y, int d){
        if(x < 0 || x == w || y < 0 || y == h || word[d] != board[y][x]){
            return false;
        }
        if(d == word.length()-1){
            return true;
        }
        char cur = board[y][x]; //小技巧，因為題目說走過一次無法再走，所以先把當前board[y][x]值改成0，讓他在下一步的時候沒辦法跟任何一個字符做匹配，等遞迴完後再把值給回來，換不同方向時就可以再走了
        board[y][x] = 0;
        bool found = search(board, word, x+1, y, d+1)
            || search(board, word, x-1, y, d+1)
            || search(board, word, x, y+1, d+1)
            || search(board, word, x, y-1, d+1);
        board[y][x] = cur;
        return found;
    }
};