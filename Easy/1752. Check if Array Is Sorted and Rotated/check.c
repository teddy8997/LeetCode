

bool check(int* nums, int numsSize){
    if(numsSize < 3){
        return true;
    }
    int index = 1;
    //找出前半部非降序
    while(index < numsSize && nums[index] >= nums[index-1]){
        index++;
    }
    if(index == numsSize){
        return true;
    }
    index++;
    //後半部非降序
    while(index < numsSize && nums[index] >= nums[index-1]){
        index++;
    }
    //檢查後半部的最大值有沒有大於前半部的最小值
    if(nums[numsSize-1] > nums[0]){
        return false;
    }
    return index == numsSize;
}