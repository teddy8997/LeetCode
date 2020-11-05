class Solution {
public:
    int fib(int N) {
    	/*
			此題為最基本的費布納西數列
			time complexity: O(2^N)
			sapce complexity: O(N) 
    	*/
        if(N <= 1){
            return N;
        }
        return fib(N - 1) + fib(N - 2);
    }
};