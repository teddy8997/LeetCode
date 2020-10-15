/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int i;
    int j = 0;
    int *final = (int *)malloc(ASize * sizeof(int));
    *returnSize = ASize;
    int k = ASize - 1;
    for(i = 0 ; i < ASize ; i++){
        if(A[i] % 2 == 0){
            final[j] = A[i];
            j++;
        }else{
            final[k] = A[i];
            k--;
        }
    }
    return final;
}
