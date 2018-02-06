#include "MaxSubarray.h"

Data::Data(int l, int h, int s){
    this->low = l;
    this->high = h;
    this->sum = s;
}

void testMaxSubarray()
{
  int array [] = {5, 7, -1, 9, -15, -50, 19, 23, 4, -5, 16, 7, 23, -15,
                  20, 20};
  int size = 16;
  Data data = findMaxSubarray(array,0,size-1);
  cout << "low = " << data.low << ", high = " << data.high << ", sum = " 
       << data.sum << endl;
  cout << "note that these numbers are of the indexes of the low and high. " 
       << endl;
}

Data findMaxCrossingSubarray(int array[], int low, int mid, int high){
    int leftSum = INTEGER_MIN;//Integer min
    int maxLeft = mid;
    int rightSum = INTEGER_MIN;//Integer min
    int maxRight = mid+1;
    int sum;
    
    sum = 0;
    
    for(int i = mid; i >= low; i--){
        sum = sum + array[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    sum = 0;
    
    for(int i = mid + 1; i <= high; i++){
        sum = sum + array[i];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = i;
        }
    }
    
    return Data(maxLeft, maxRight, leftSum + rightSum);
}

Data findMaxSubarray(int array[], int low, int high){
    if(high == low){//Then the recursion has hit the minimal limit
        return Data(low,high,array[low]);
    } else{
        int mid = (low + high)/2;//set the middle index
        Data left = findMaxSubarray(array,low,mid),//including low to mid
             right= findMaxSubarray(array,mid+1,high),//including mid+1 to high
             crossing = findMaxCrossingSubarray(array,low,mid,high);
        
        //Could use fewer comparisons for the second check
        if(left.sum >= right.sum && left.sum >= crossing.sum){
            //the left data has the highest sum
            return left;
        } else if(right.sum >= left.sum && right.sum >= crossing.sum){
            //the right data has the highest sum
            return right;
        } else if(crossing.sum >= left.sum && crossing.sum >= right.sum){
            //At this point this should be true.
            //the crossing data has the highest sum
            return crossing;
        }else{
            return Data (-1,-1,-1);
        }
    }
}
