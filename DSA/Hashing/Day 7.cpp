// 205. Isomorphic Strings
// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i=0;i<s.length();i++){
          //go char wise 
            char c1=s[i];
            char c2=t[i];

          //map c1 to c2 in map 1 
          //i.e. if c1 doesn't exist in map1,, map it to c2 [in the else part]
          //otherwise if c1 exist in map1 and by any chance if it isn't mapping with c1 ,, then it's not isomorphic [in the if part]
            if(mp1.count(c1)){
                if(mp1[c1]!=c2) return false;
            }
            else{
                mp1[c1]=c2;
            }

          //similarly check mapping for c2 to c1 in map 2
            if(mp2.count(c2)){
                if(mp2[c2]!=c1) return false;
            }
            else{
                mp2[c2]=c1;
            }
        }
        return true;
    }
};







// 290. Word Pattern
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Explanation:
// The bijection can be established as:
// 'a' maps to "dog".
// 'b' maps to "cat".

class Solution {
public:
    bool wordPattern(string pattern, string s) {
      //firstly store all words from string s into a vector of words
        vector<string> words;
        string w="";
        for (char ch: s){
            if(ch==' '){  //if ch is ' ' and w has something, push w in words vector and make w empty
                if(!w.empty()){
                    words.push_back(w);
                    w="";
                }
            }
            else {  //add the character in w
                w+=ch;
            }
        }
      //to add the last word
        if(!w.empty()){
            words.push_back(w);
        }

      //check for mapping 
        if(pattern.size()!=words.size()) return false;

        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;

        for(int i=0;i<words.size();i++){
            char c=pattern[i];
            string str=words[i];

            if(mp1.count(c)){
                if(mp1[c]!=str) return false;
            }
            else{
                mp1[c]=str;
            }

            if(mp2.count(str)){
                if(mp2[str]!=c) return false;
            }
            else{
                mp2[str]=c;
            }
        }
        return true;        
    }
};  





// 389. Find the Difference
// Input: s = "abcd", t = "abcde"
// Output: "e"
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> freq;
      //count frequency in s and then in t 
      //if any char freq gies less than 0 then it the the extra char
        for(char c:s){
            freq[c]++;
        } 
        for(char c:t){
            freq[c]--;
            if(freq[c]<0) return c;
        }
        return ' ';
    }
};


