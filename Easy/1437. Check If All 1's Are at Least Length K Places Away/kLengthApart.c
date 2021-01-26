

bool kLengthApart(int* nums, int numsSize, int k){
    int count = k;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            if(count < k){
                return false;
            }
            count = 0;
        }else{
            count++;
        }
    }
    return true;
}