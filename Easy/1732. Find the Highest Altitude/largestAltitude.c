

int largestAltitude(int* gain, int gainSize){
      int ans[gainSize+1];
      ans[0] = 0;
      int i = 1;
      for(int j = 0; j < gainSize; j++){
          ans[i] = ans[i - 1] + gain[j];
          i++;
      }
      int max = ans[0];
      for(int j = 0; j < gainSize+1; j++){
          if(max < ans[j]){
              max = ans[j];
          }
      }
      return max;
}