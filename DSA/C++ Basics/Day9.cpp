
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






//287: Find Duplicate Number
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return -1;
    }
};
*/

//optimal solution
//Floyd's Cycle Detection(Tortoise and Hare)
//used to detect cycles in a sequence (like a linked list or a number-based array where values point to indices).

// ->Start both pointers at the beginning.
// ->Move the slow pointer one step at a time.
// ->Move the fast pointer two steps at a time.
// ->If there is a cycle, they will meet at some point inside the cycle.[Intersection Point]
// ->To find the entry point of the cycle:
//      Move one pointer(let say slow) to the start of the sequence.
//      Keep the other pointer(fast) where the meeting happened.
//      Move both pointers one step at a time — they will meet at the 'start of the cycle'.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];  //start slow from start
        int fast=nums[0];  //start fast from start

        do{                   //do this until slow==fast
            slow=nums[slow];  //move slow by 1 step
            fast=nums[nums[fast]];   //move fast by 2 steps
        }while(slow!=fast);


        slow=nums[0];  // move slow to the start 
        //fast is at the intersection point
        while(slow!=fast){    //move both by one step untill they are equal
            slow=nums[slow];
            fast=nums[fast];
        }    
        return slow;   
    }
};






//2529: Maximum count of Positive Integer and negative integer
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p=0,ne=0;
        for(int n: nums){
            if(n>0) p++;
            if(n<0) ne++;
        }
        return max(p,ne);
    }
};






//1122: Relative Sort Array
// Sort arr1 such that:Elements in arr2 appear first, in the same order as in arr2. and Remaining elements (not in arr2) are placed at the end in ascending order.
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int f[1001]={0}; ///for elements till 1001
        for(int n: arr1) f[n]++;   //if n is in arr1 increase it's frequency (if 3 appear 2 times --> f[3]=2)
        
        vector<int> res;

        for(int n: arr2){ //if num in arr2 
            while(f[n]>0){ //and till the frequency > 0 , add it in result
                res.push_back(n);
                f[n]--;  //decrease it's frequency
            }
        }

        //for elements still left in arr1 (fill in ascending order)
        for(int i=0;i<1001;i++){
            while(f[i]>0){  //till frequency > 0
                res.push_back(i);   //add it in result
                f[i]--;   //decrease frequency 
            }
        }
        return res;
    }
};







//Sliding Window:
// 1. Fixed-size Sliding Window:
// When the size of the window is given (like k)
// Common in maximum/minimum/average sum of subarrays

// Keep a window of exactly k elements, Slide the window by removing the first and adding the next
// add current and remove first from the sum 



// 2. Variable-size (Dynamic) Sliding Window:
// when window size is not fixed, it grows/shrinks based on some condition
// Often used with two pointers: left and right

// Expand the window by moving the right pointer
// Shrink the window by moving the left pointer until the condition is satisfied
// Adjust window size dynamically


// Example of Fixed-size sliding window
// nums = [1, 2, 3, 4, 5], k = 3

// Window 1: [1, 2, 3] → sum = 6  
// Window 2: [2, 3, 4] → sum = 6 - 1 + 4 = 9  
// Window 3: [3, 4, 5] → sum = 9 - 2 + 5 = 12


//643 : Maximum Average Subarray
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s=0;
        for(int i=0;i<k;i++) s+=nums[i];  //finding sum of first k elements

        int maxSum=s;  //making it as the max sum

        for(int i=k;i<nums.size();i++){//now from k to last
            s+=nums[i] - nums[i-k];  //keep adding the current element in sum and remove the first 
            maxSum=max(maxSum,s);  //whichever is maximum make it as max sum
        }
        return (double)maxSum/k;
    }
};







// 2206: Divide array into equal Pairs 
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){  //incrementing by 2
            if(nums[i]!=nums[i+1]) return false;
        }
        return true;
    }
};







//54: Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top=0, bottom = matrix.size()-1;
        int left=0, right = matrix[0].size()-1;

        while(top <= bottom  && left <= right){  //continuing loop till these condition are satisfied
            
            for(int i=left ; i<=right;i++){  //traversing top row left->right
                res.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){    //Traverse the right column,top->bottom
                res.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){      //if rows are left.
                for(int i=right;i>=left;i--){    //traverse bottom row, right->left
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){     //if columns are left.
                for(int i=bottom;i>=top;i--){      //traverse left column,bottom->top
                    res.push_back(matrix[i][left]);
                }
                left++;
            } 
        }
        return res;

    }
};







//2843:  Count Symmetric Integers
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
       int c=0;
       for(int i=low;i<=high;i++){
            string s= to_string(i); //convert in string to find length

            if(s.length()%2==0){  //if length is even

                int x=s.length()/2;  //find half 

                int s1=0,s2=0;

                for(int i=0;i<x;i++) s1+=s[i] -'0';  //calculate sum on first half
                for(int i=x;i<s.length();i++) s2+=s[i]-'0';  //calculate sum on second half
                // we subtracted '0' so to convert it back into integer

                //a number if symmetric would have equal sum on both halves
                if(s1==s2) c++;  //if both sum are equal, increase count
            }
       }
       return c;

    }
};

//optimal
