//reverse a string
#include<iostream>
#include<vector>
using namespace std;
string reverseString(string s){
    vector<char> v;
    for(char c:s){
        v.push_back(c);
    }
    string r="";
    while(!v.empty()){
        r+=v.back();
        v.pop_back();
    }
    return r;
}
int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);

    string result=reverseString(s);
    cout<<"Reversed string: "<<result<<endl;

    return 0;
}





// 20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c: s){
            if(c=='(' || c=='[' || c=='{'){   //if it's opening bracket
                stack.push(c);   //push it into the stack
            }
            else{    //if it's closing bracket
                if(stack.empty()) return false;   //i stcak is emoty i.e. not opening braces into the stack return false
                char top=stack.top();    //find the top char of the stack
                if((c==')' && top!='(') || (c==']' && top!='[') || (c=='}' && top!='{')) return false;      //if the new char and top of stack aren't a pair return false

                stack.pop(); // Only pop after a successful match
            }
        }
        return stack.empty();   //if all open brackets are matched , stack will be empty
    }
};






// 1047. Remove All Adjacent Duplicates In String
//using stack
/*
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c: s){
            if(st.empty()==false  && st.top()==c) st.pop();   //if top of stack is c delete it
            else st.push(c);   /otherwise add into stack
        }
        string r="";
        while(st.empty()==false){
            r=st.top()+r;  //add top and then r so that result doesn't get reversed
            st.pop();
        }
        return r;
    }
};
*/
//optimal
//using string in C++ is a class based on std::basic_string, which supports many of the same methods as vector
class Solution {
public:
    string removeDuplicates(string s) {
        string r="";
        for(char c: s){
            if(r.empty()==false  && r.back()==c) r.pop_back();  //if back of string is c delete it
            else r.push_back(c);   //else add into result
        }
        return r;
    }
};






// 682. Baseball Game
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string s:operations){
            if(s=="C") st.pop();  // if input is C delete the top element
            else if (s=="D") {    //if input is D multiply the top element with 2 and push 
                int x=2*st.top();
                st.push(x);
            }
            else if(s=="+"){    //if the input is + add the top 2 elements and push
                int t1=st.top();
                st.pop();
                int y=t1+st.top();
                st.push(t1);   //push t1 back
                st.push(y);   //push the addition
            }
            else st.push(stoi(s));    //else the input is integer convert stoi and then push
        }
        int s=0;
        while(!st.empty()){  //find total sum
            s+=st.top();
            st.pop();
        }
        return s;
    }
};







// 844. Backspace String Compare
// compare two string ,tehy must be same
// '#' means to pop element otherwise push
class Solution {
public:
    string stackValue(string str){
        stack<char>st;
        for(char c:str){
            if(c=='#'){  //if '#' pop (but stack must bhave elements to pop)
                if(!st.empty()) st.pop();    
            }
            else st.push(c);    //else push
        }
        string res="";  //store result
        while(!st.empty()){
            res=st.top()+res;  //to store in original order
            st.pop();
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        if(stackValue(s)==stackValue(t)) return true;
        return false;
    }
};







// 155. Min Stack
// approach: 
// push in st , push in minSt only if val to pushed < top of minSt
// pop from st, pop from minSt only if the top value of st and minSt are same  (otherwise do not pop from minSt as it stores the correct minimum value rn)
class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);   //push in st
        if(minSt.empty() || val<=minSt.top()) minSt.push(val);    //push in minSt if the new val < top of minSt OR minSt in empty
    }
    
    void pop() {
        if(st.top()==minSt.top()) minSt.pop();   //pop from minSt only if top of St and minSt are same (otherwise minSt still have current smallest value, do not pop)
        st.pop();  //pop from st
    }
    
    int top() {
       return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



