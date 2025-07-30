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






// 49. Group Anagrams
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string s:strs){
            string x = s;
            sort(x.begin(),x.end());   //sort each string that we get
            mp[x].push_back(s);       //and store all original string value in the sorted key [such that string with same char get together]
        }
        vector<vector<string>>res;
        for(auto &p:mp){
            res.push_back(p.second);   //to get any the values i.e. the grouped anagram
        }
        return res;
    }
};

/*
| Word | Sorted | Group added to map     |
| ---- | ------ | ---------------------- |
| eat  | aet    | \["eat"]               |
| tea  | aet    | \["eat", "tea"]        |
| tan  | ant    | \["tan"]               |
| ate  | aet    | \["eat", "tea", "ate"] |
| nat  | ant    | \["tan", "nat"]        |
| bat  | abt    | \["bat"]               |
*/



