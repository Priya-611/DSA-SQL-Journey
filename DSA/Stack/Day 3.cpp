
// 739. Daily Temperatures
//next higher temp
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        for(int i=0;i<temperatures.size();i++){
            for(int j=i+1;j<temperatures.size();j++){   //checking all the values after i
                if(temperatures[j]> temperatures[i]){ if the next term is greater
                    ans[i]=j-i;   //ans array will have the difference till next large value
                    break;
                }
            }
        }
        return ans;
    }
};
*/
//optimal
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Initialize a ans vector with the same size as temperatures, filled with 0
        // Each index will hold the number of days until a warmer temperature
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;   // Stack to store indices of the temperatures array// We use it to keep track of the temperatures we haven't resolved yet
       
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int top=st.top();   // Get the index from the top of the stack
                st.pop();     // Remove that index since we found a warmer temperature
                ans[top]=i-top;    // The difference between current index and stored index gives the wait time
            }
            st.push(i);   // Push the current index onto the stack
        }
        return ans;
    }
};








// 503. Next Greater Element II
// array is said to be circular
// nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);   //ans array of nums.size() with each element as -1
        stack<int> st;   //stack to store index 
        for(int i=0;i<2*nums.size();i++){ // go through the array twice (0 .. 2n‑1) to simulate circularity
            int idx = i%nums.size();   //for greater index wrap acc to the size of array
            while(!st.empty() && nums[st.top()]<nums[idx]){   //if stack has element and the top element of stack (previous) is less than the current element[ means current is the greater element ]
                ans[st.top()]=nums[idx];  //store current element in ans array 
                st.pop();      //and pop the previous element from stack as we've found greter element for the same
            }
            
            st.push(idx);   //push the current index into stack so that we can find the next greater element for it in next turn
        }
        return ans;
    }
};







// 1475. Final Prices With a Special Discount in a Shop
// Input: prices = [8,4,6,2,3]
// Output: [4,2,4,2,3]
// Explanation: e same element

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans=prices;   // copy prices array into ans array
        stack<int>st;     //stack for storing indexes 
        for(int i=0;i<prices.size();i++){
            while(!st.empty() && prices[st.top()]>=prices[i]){   //if stack has element and the top element of stack[previous] >= current element
                ans[st.top()]=prices[st.top()]-prices[i];      //store the difference of top element and current element
                st.pop();      //delete theindex from stack
            }
            st.push(i);      // push the current index into stcak for further evaluation
        }
        return ans;
    }
};

// For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
// For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
// For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
// For items 3 and 4 you will not receive any discount at all.

//if no smaller elemnet found for discount copy th







// 1544. Make The String Great
// A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
// 0 <= i <= s.length - 2
// s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa
/*
class Solution {
public:
    string makeGood(string s) {
        string r="";
        for(char c: s){   //if (result has char) and (the new char is in uppercase) and (last char of result [previous] is in lower case) and (both char are same) or vice-versa,, then pop it
            if(!r.empty() && (isupper(c) && islower(r.back()) && tolower(c)==r.back() || islower(c) && isupper(r.back())&& toupper(c)==r.back())){
                r.pop_back();
            }
            else r.push_back(c);   //otherwise push into result string
        }
        return r;
    }
};
*/

//optimal
class Solution {
public:
    string makeGood(string s) {
        string r="";
        for(char c: s){    //use absolute function [if the difference of new char c and r.back()(previous char) is 32 ]  (which mean both are same char and one of them is in uppercase and other is in lowercase)
            if(!r.empty() && abs(r.back()-c)==32){
                r.pop_back();
            }
            else r.push_back(c);
        }
        return r;
    }
};







// 2011. Final Value of Variable After Performing Operations
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0;i<operations.size();i++){
            string o=operations[i];
            if(o=="--X") x=x-1;

            else if(o=="X--") x=x-1;

            else if(o=="X++") x=x+1;

            else if (o=="++X") x=1+x;
        }
        return x;
    }
};







// 1003. Check If Word Is Valid After Substitutions
// Input: s = "aabcbc"
// Output: true
// Explanation:
// "" -> "abc" -> "aabcbc"
// Thus, "aabcbc" is valid.
    
// Example 2:
// Input: s = "abccba"
// Output: false
// Explanation: It is impossible to get "abccba" using the operation.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){  //push char in stack 
            st.push(c);
            if(st.size()>=3){  //if there are 3 or more elements in stack check top 3 element,, if they are not in this sequence 'abc' push them back, else pop them
                char c1=st.top();
                st.pop();
                char c2=st.top();
                st.pop();
                char c3=st.top();
                st.pop();
                if(c1!='c' || c2!='b' ||c3!='a'){
                    st.push(c3);
                    st.push(c2);
                    st.push(c1);
                }
            }
        }
        return st.empty();
    }
};





