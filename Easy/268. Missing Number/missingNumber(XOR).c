

int missingNumber(int* nums, int numsSize){
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans ^= nums[i] ^ (i + 1);
    }
    return ans;
}