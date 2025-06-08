//350: Intersection of two array II
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int count[1001]={0};
        for(int n:nums1){       //for every element in nums1 increase it's frequency(number of times it appear)
            count[n]++; 
        }
        for(int n: nums2){   //for element in nums2
            if(count[n]>0){    //if frequency of that element is greter than 0, add it in array
                arr.push_back(n);  
                count[n]--;   //and decrease its frequency
            }
        }
        return arr;
    }
};








//75 Sort color (without using inbuilt sort function)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-1-i;j++){
                if(nums[j]>nums[j+1]){
                    int t=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=t;
                }
            }
        }
    }
};






//189 : Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // while(k>0){
        //     int t=nums[nums.size()-1];
        //     for(int i=nums.size()-1;i>0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=t;
        //     k--;
        // }
    }
};

//optimal
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // After every n rotations, the array returns to its original position.
        // So rotating n, 2n, 3n… times has no net effect.

        //for k > nums.size() , we will only focus on remainder
        k=k % nums.size();
        reverse(nums.begin(),nums.end());   //reverse the whole array (n)
        reverse(nums.begin(),nums.begin()+k);    //reverse first k elements
        reverse(nums.begin()+k ,nums.end());  //reverse the remaining (n-k) elements
    }
};









//128: Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        // int c=nums.size();
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i+1]-nums[i]!=1) c--;
        // }

        int maxL=1;
        int curr=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) continue;  //skip dupliactes
            else if(nums[i] == nums[i+1]-1) curr++;  //if gap is of 1 increse count 
            else{   //when sequence is broken
                maxL=max(curr,maxL);  //save then current to find max
                curr=1;   //reset current as nums[i] starts neqw sequence
            }
        }   


        return max(maxL,curr);
    }
};








//283: Move Zeros to the end
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[idx]==0){
                nums.erase(nums.begin()+idx);   //remove zero from idx
                nums.push_back(0);   //add zero at end
            }
            else idx++;

        }
    }
};






//26:  Remove duplicates from sorted array
//idx will only move when there's a unique element 
//which means that there exist only duplicate elements betwen idx and i
//if unique is found by ith index -> increase idx to next pos and replace duplictate by a unique element

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[idx]){  //if unique
                idx++;    //increase idx
                nums[idx]=nums[i];  //increase idx position and repplace the duplicate with unique element found by i
            }
        }
        return idx+1;
    }
};









//53: Maximum Subarray
// storing first ele as max and curr
//current Sum -> either the (current value) or (current + new element)

// storing whichever is maximum among both
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS=nums[0];
        int currS=nums[0];
        for(int i=1;i<nums.size();i++){
           
            currS= max(nums[i], currS+nums[i]);
            maxS=max(maxS, currS);
        }
        return maxS;
    }
};
