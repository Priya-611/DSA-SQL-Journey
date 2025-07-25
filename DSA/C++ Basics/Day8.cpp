
// 58: length of last word
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int l=0,i=n-1;
        while(i>=0 && s[i]==' ') i--;// if first space is found move to next till word is found
        while(i>=0 && s[i]!=' '){ //count till next space is not found
            l++;
            i--;
        }
        return l;
    }
};




//27: 
//  remove all occurrence if val from nums (in-place)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0;
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) {
                nums[idx++]=nums[i];
                c++;
            }
            
        }
        return c;
        
    }
    
};






//1832 Pangram: 
// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int pan[26]={0}; //creating array, initailising with 0
        for(int i=0;i<sentence.length();i++){
            char ch= sentence[i];
            if(ch>='a' && ch<='z') pan[ch-'a']=1;  //converting ch into index from 0 to 25
        } 
        for(int i=0;i<26;i++){
            if(pan[i]!=1) return false;
        }
        return true;
        
    }
};





//258: add digits unitl sum is single digit
class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int s=0;
            while(num>0){
                int r= num%10;
                s+=r;
                num/=10;
            }
            num=s;
        }

        return num;
    }
};








//242 Anagram :a word or phrase formed by rearranging the letters of another word or phrase, using all the original letters exactly once.
//either sort both str8ung and then compare

//optimal solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            arr[ch-'a']++;  //increse the value at that index
        }
        for(int i=0;i<t.size();i++){
            arr[t[i]-'a']--;   //decrese the value at that index( so it basically nullify the value)
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        return true;
    }
};







//14 Longest common prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string p="";
        for(int i=0;i<strs[0].size();i++){  //loop till each char of first word[only the first element]
            char ch=strs[0][i];  //storing each alphabet of first word
            for(int j=1;j<strs.size();j++){ //loop from second element to last 
                if(ch!=strs[j][i]) return p; //if ch != aplhabet of other word
            } 
            p+=ch;
        }
        return p;
    }
};






//231: Power of 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0 ) return false;
        while(n%2==0){ 
            n/=2;
        }
        if(n==1) return true;  //if at last quotient is 1
        return false;
    }
};






//125 valid palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z') s[i]=tolower(s[i]);
        }
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])) s1+=s[i]; //need to store alphanumeric values
        }
        int l=0;
        int r=s1.size()-1;
        while(l<r){
            if(s1[l]!=s1[r]) return false;
            l++;
            r--;
        }
        return true;

    }
};






// 169: Majority Element

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
//             int c=0;
//             for(int j=0;j<nums.size();j++){
//                 if(nums[i]==nums[j]) c++;
//             }
//             if(c>nums.size()/2) return nums[i];
//         }
//         return -1;
//     }
// };

//optimal solution
//Boyer-Moore Algorithm (assume there is one element that occurs more than half the time. try to cancel out other elements against this majority. If it truly is the majority, it will survive till the end.)
class Solution {
public:
int majorityElement(vector<int>& nums) {
        int c=0;
        int ele=0;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                ele=nums[i];
            }
            if(nums[i]==ele) c++;
            else c--;
        }
        return ele;
    }
};







//905: Sort Array by parity: move all even number at the beginning followed by odd
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]%2==0) i++;  //if there is even in beginnning move the index
            else if(nums[j]%2!=0) j--;    //if there is odd at the ending move the index
            else{                   //if odd at beginning and even at end  -> swap
                swap(nums[i],nums[j]);     //(nums[i]%2!=0 && nums[j]%2==0)
                i++;
                j--;
            }
        }
        return nums;
    }
};

//optimal 
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2==0){  //if you find even element swap it with ith element 
                swap(nums[j],nums[i]); 
                i++;  //increase i only if you find even at j
            }
        }
        return nums;
    }
};




//88: 
//merging sorted array in array 1 itself
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i= m-1,j=n-1;
        int k=m+n-1;
        //fill in reverse order (biggest element first)        
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
            else nums1[k--]= nums2[j--];
        }
        while(i>=0) nums1[k--]=nums1[i--];
        while(j>=0) nums1[k--]=nums2[j--];
    }
};






//1299 : replacing element with greatest element on the right side
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max=-1;  //initially max is -1
        for(int i=arr.size()-1;i>=0;i--){
            int x=arr[i];  //current element
            arr[i]=max;//replacing max every time
            if(x>max) max=x; // comparing each ele with max  and replacing only if x (current ele) is greater
        }
        return arr;
    }
};







//724: Find pivot index
// um of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int k=0;
        while(k<nums.size()){
        int rs=0,ls=0;
        
        for(int i=0;i<k;i++){
            rs+=nums[i];
        }
        for(int i=k+1;i<nums.size();i++){
            ls+=nums[i];
        }
        if(rs==ls) return k;
        k++;
        }
        return -1;
    }
};



//optimal Solution
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t=0,ls=0;
        for(int num:nums) t+=num;//find total Sum
        
        for(int i=0;i<nums.size();i++){
            if(ls == t-ls-nums[i]) return i; //leftSum == rightSum(total - leftSum - current element)
            ls+=nums[i];
        }
        return -1;
    }
};










//88: 
//merging sorted array in array 1 itself
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i= m-1,j=n-1;
        int k=m+n-1;
        //fill in reverse order (biggest element first)        
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
            else nums1[k--]= nums2[j--];
        }
        while(i>=0) nums1[k--]=nums1[i--];
        while(j>=0) nums1[k--]=nums2[j--];
    }
};






//1299 : replacing element with greatest element on the right side
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max=-1;  //initially max is -1
        for(int i=arr.size()-1;i>=0;i--){
            int x=arr[i];  //current element
            arr[i]=max;//replacing max every time
            if(x>max) max=x; // comparing each ele with max  and replacing only if x (current ele) is greater
        }
        return arr;
    }
};







//724: Find pivot index
// um of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int k=0;
        while(k<nums.size()){
        int rs=0,ls=0;
        
        for(int i=0;i<k;i++){
            rs+=nums[i];
        }
        for(int i=k+1;i<nums.size();i++){
            ls+=nums[i];
        }
        if(rs==ls) return k;
        k++;
        }
        return -1;
    }
};

//optimal Solution
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t=0,ls=0;
        for(int num:nums) t+=num;//find total Sum
        
        for(int i=0;i<nums.size();i++){
            if(ls == t-ls-nums[i]) return i; //leftSum == rightSum(total - leftSum - current element)
            ls+=nums[i];
        }
        return -1;
    }
};





