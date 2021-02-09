

int sumOfUnique(int* nums, int numsSize){
    int tmp [101] = {0};
    for(int i = 0; i < numsSize; i++){
        tmp[nums[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        if(tmp[nums[i]] == 1){
            ans += nums[i];
        }
    }
    return ans;
}