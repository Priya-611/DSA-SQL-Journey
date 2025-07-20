
// 703. Kth Largest Element in a Stream
/*
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
  
Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output: [null, 4, 5, 5, 8, 8]
*/
// use a minimum priority queue to find k th largest term
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int num:nums){
            add(num);
        }

    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()> K) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */





// 215. Kth Largest Element in an Array
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

//use minHeap [same logic]
class Solution {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int findKthLargest(vector<int>& nums, int k) {
        for(int num: nums){
            minHeap.push(num);
            if(minHeap.size()>k) minHeap.pop();
        }
        return minHeap.top();
    }
};







// 1046. Last Stone Weight
// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation: 
// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
// we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
class Solution {
public:
    priority_queue<int> maxHeap;
    int lastStoneWeight(vector<int>& stones) {
        for(int num:stones){
            maxHeap.push(num);   //8 7 4 2 1 1
        }
        while(maxHeap.size()>1){
            int n=maxHeap.top();
            maxHeap.pop();
            int m=maxHeap.top();
            maxHeap.pop();

            if(n!=m) maxHeap.push(abs(m-n));
        }
        if(maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};




