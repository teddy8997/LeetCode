/*
 qsort 函數說明 ->>需要 #include<stdlib.h>
*/
int cmp(void const *a, void const *b){
    return *(int*)a - *(int*)b;
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    int j = numsSize -1;
    int ans = 0;
    while(i < j){
        int sum = nums[i] + nums[j];
        if(sum == k){
            ans++;
            i++;
            j--;
        }else if(sum < k){
            i++;
        }else{
            j--;
        }
    }
    return ans;
}