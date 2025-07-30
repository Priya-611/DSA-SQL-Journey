// 349. Intersection of Two Arrays
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        vector<int> res;
        for(int n:nums2){
            if(set1.count(n)){
                res.push_back(n);
                set1.erase(n);  //to prevent duplicate
            }
        }

        return res;
    }
};

/*This checks whether num exists in set1.
If num is present, count(num) returns 1.
If num is not present, it returns 0.*/





// 771. Jewels and Stones
// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       unordered_set<int> set1(jewels.begin(),jewels.end());
        int c=0;
        for(char ch: stones){
            if(set1.count(ch)) c++;
        }
        return c;
    }
};





