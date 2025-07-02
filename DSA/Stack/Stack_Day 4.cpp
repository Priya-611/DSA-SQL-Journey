// 1021. Remove Outermost Parentheses

// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"

//approach
// When we see '(' → increase depth
// When we see ')' → decrease depth
// Only add characters to the result if we're not on the outermost level

class Solution {
public:
    string removeOuterParentheses(string s) {
        string r="";
        int x=0;
        for(char c: s){
            if(c=='('){  //if it's opening bracket and not the outermost add it and increase x
                if(x>0) r+=c;
                x++;
            }
            else{ //if c=='('  [if it's closing bracket decrease x, and check if it's not the outermost add it] 
                x--;
                if(x>0) r+=c;
            }
        }
        return r;
    }
};






// 1598. Crawler Log Folder
// "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
// "./" : Remain in the same folder.
// "x/" : Move to the child folder named x (This folder is guaranteed to always exist).

// Input: logs = ["d1/","d2/","../","d21/","./"]
// Output: 2
// Explanation: Use this change folder operation "../" 2 times and go back to the main folder.

// approach:
// if ../ delete the top element [move to previous folder]
// if ./ kremain in sam efolder
// else push into stack
// return size to see how many floder i need to travel to reach main
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack <string> st;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../" ){
                if(!st.empty()) st.pop();
            }
            else if(logs[i]=="./") continue;
            else st.push(logs[i]);
        }
        return st.size();
    }
};








// 1614. Maximum Nesting Depth of the Parentheses
// Each '(' starts a new inner level
// Each ')' closes the current level
// So we:
//  Increase currentDepth++ on '('
//  After each increase, check maxDepth = max(...)
//  Decrease currentDepth-- on ')' (to go back one level)

class Solution {
public:
    int maxDepth(string s) {
        int x=0;
        int m=0;
        for(char c: s){
            if (c=='('){    //if it's opening bracket, increase x 
                x++;    //current depth
                m=max(m,x);    //max depth    
            }
            else if (c==')'){    //if it's closing bracket decrease x;
                x--;
            }
        }
        return m;
    }
};








// 901. Online Stock Span
// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]

//approach:
// using stack of pair<int, int> ,,holds:
// first → the stock price
// second → the span for that price

class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
    }
    int next(int price) {
        int s=1;     // include today by default[as each element will have span as 1 (including itself)]
        while(!st.empty() && st.top().first<=price){    // Keep popping from the stack as long as the top price is ≤ current price, and keep adding their spans.
            s+=st.top().second;  //add span i.e new s to previous span i.e. s
            st.pop();
        }
        st.push({price,s});    //store price with it's span 
        return s;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */



/*
Pair is a container that can hold two values of possibly different types together.
pair<int, string> p = {5, "apple"};
First slot → 5
Second slot → "apple"

Access:
cout << p.first;  // prints 5
cout << p.second; // prints "apple"
*/







// 150. Evaluate Reverse Polish Notation
//approach:
// if we encounter any of the mathematical operation sign we'll pop top 2 elements from stack , perfrom operation and store the result
// else if it is num we convert string into integer using stoi and push into stack
// at last the top element will be the ans 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens){       
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int z;
                if(s=="*") z=y*x;
                else if(s=="/") z=y/x;
                else if(s=="-") z=y-x;
                else if(s=="+") z=y+x;
                st.push(z);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};


