

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isArithmetic(int*, int*, int*, int);

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize){
    bool *ans = (bool*)malloc(sizeof(bool) * lSize);
    for(int i = 0; i < lSize; i++){
       bool check = isArithmetic(nums, l, r, i);
       ans[i] = check;
    }
    *returnSize = lSize;
    return ans;
}
int cmp(const void* a, const void* b){
    return *(int *)a - *(int *)b;
}
bool isArithmetic(int* nums, int* s, int* e, int l){
    int tmp[e[l]-s[l]+1];
    int j = 0;
    for(int i = s[l]; i <= e[l]; i++){
        tmp[j] = nums[i];
        j++;
    }
    qsort((void*) tmp, e[l]-s[l]+1, sizeof(int), cmp);
    int d = tmp[1] - tmp[0];
    for(int i = 2; i < e[l]-s[l]+1; i++){
        if(tmp[i] - tmp[i-1] != d){
            return false;
        }
    }
    return true;
}