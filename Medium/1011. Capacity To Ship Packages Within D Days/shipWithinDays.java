class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int l = getMax(weights);
        int r = getSum(weights);
        while(l <= r){
            int m = l + (r - l) / 2;
            int mDay = calDay(weights, m);
            if(mDay < D){
                r = m - 1;
            }else if(mDay > D){
                l = m + 1;
            }else if(mDay == D){
                r = m - 1;
            }
        }
        return l;
    }
    private int calDay(int[] weights, int cap){
        int count = 1;
        int cursum = 0;
        for(int w : weights){
            if(cursum + w > cap){
                count++;
                cursum = w;
            }else{
                cursum += w;
            }
        }
        return count;
    }
    private int getMax(int[] weights){
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < weights.length; i++){
            max = Math.max(max, weights[i]);
        }
        return max;
    }
     private int getSum(int[] weights){
        int sum = 0;
        for(int i = 0; i < weights.length; i++){
            sum += weights[i];
        }
        return sum;
    }
}