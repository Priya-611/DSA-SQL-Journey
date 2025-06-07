
//414 : Third Maximum Number
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //sort( in ascending order)
        reverse(nums.begin(),nums.end()); //reverse(now array is in descending order)
        int idx=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){  //if distinct element are found increase idx
                idx++;  
            }
            if(idx==2) return nums[i+1];  //idx==2 means we've found two changes in value so far, so the 3rd distinct number is at i+1.
        }
        return nums[0];  //if third max is not found  return the max (which is at 0th index) 

    }
};
