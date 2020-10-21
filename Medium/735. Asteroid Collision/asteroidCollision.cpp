class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;

        for(int i = 0; i < asteroids.size(); i++){
            int size = asteroids[i];
            //遇到向右的隕石就直接PUSH進去
            if(size > 0){
                s.push_back(size);
            }else{
                /*
                    如果遇到的是向左的隕石有兩種case
                    1)如果stack是空的或是stack最上面的隕石也是向左就直接push進去
                    2)如果stack最上面的隕石是向右，而且stack最上面的隕石尺寸小於遇到的隕石
                    我們就將迴圈的i減去1, 目的就是為了下一輪還是取到目前這個隕石，然後將stack最上面的隕石爆掉 
                */
                if(s.empty() || s.back() < 0){
                    s.push_back(size);
                }else if(abs(s.back()) <= abs(size)){
                    if(abs(s.back()) < abs(size)){
                        --i;
                    }
                    s.pop_back();
                }
            }
        }
        return s;
    }
};