//String

// length() or size() –-> Get string length
// substr() –-> Get a substring
// find() –-> Find characters or substrings
// append() / '+' –-> Combine strings (Add to end of string)
//getline(input_stream, variable, delimiter) -->delimiter is the char after which the reading will stop
// empty()	--> Check if string is empty	
// at(i)	--> Get char at index i
// insert(pos, str) --> insert at position
// erase(pos, len) --> Delete part of string
// replace(pos, len, str) --> Replace part with str
// substr(pos, len) --> get substring
// compare(str) -->	Compare two strings



// s.begin() -->	Iterator to start of string
// s.end()	--> Iterator to end (after last char)
// isalpha(c) -->	Checks if c is an alphabet letter
// isdigit(c) -->	Checks if c is a digit
// tolower(c) -->	Converts c to lowercase (converts only character)
// toupper(c) -->	Converts c to uppercase  (converts only character)
// reverse(start, end) -->	Reverses a string/part of it
// sort(start, end) -->	Sorts characters
// count(start, end, ch) --> Count occurrences of char



#include <iostream>
#include <string>   // string data type is not part of the core C++ language—it’s part of the C++ Standard Library.
using namespace std;
int main() {
    string data;
    cout << "Enter data: ";
    getline(cin, data, ',');  // stops at comma
    cout << "You entered: " << data << endl;
    return 0;
}




//concatenation
#include<iostream>
using namespace std;
int main(){
    string str="Hello";
    string str2="Hey";
    str2 +=" World!!";
    str = str + " there";
    cout<<str2<<endl;  //Hey World!!
    cout<<str<<endl;   //Hello there
    str.append(" people");
    cout<<str;
    
    return 0;
}




//reverse string 
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int n=str.length();
    for(int i=0;i<n/2;i++){
        char temp=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=temp;
    }
    cout<<"Reversed string is: "<<str<<endl;
    return 0;
}

//or 
#include<iostream>
#include<string>
#include<algorithm>                          
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    reverse(str.begin(),str.end());
    cout<<"Reversed string is: "<<str<<endl;
}





//replace(pos, len, str)
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);
    
    s1.replace(4,2,"Priya");  //go to 4th position, replace 'two' char with the new 'string'
    cout<<s1;

    return 0;
}




// insert(pos, str)
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);
    
    s1.insert(4,"Priya");  //go to 4th position, insert new 'string'
    cout<<s1;

    return 0;
}



//substr(pos, len) 
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);
    string sub=s1.substr(4,7);  //go to 4th position and get next 7 letters
    cout<<sub<<endl;

    return 0;
}




//compare(str)
// 0 → equal
// < 0 → this string is smaller
// > 0 → this string is greater
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);

    string s2;
    cout<<"Enter the string: ";
    getline(cin,s2);

    int res=(s1.compare(s2));
    
    if(res==0) cout<<"Strings are equal"<<endl;
    else if(res<0) cout<<s1<<" is smaller than "<<s2<<endl;
    else cout<<s1<<" is smaller than "<<s2<<endl;

    return 0;
}




//check string is palindrome
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int n=str.length();
    bool ispal=true;
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-1-i]) {
            ispal = false;
            break;
        }
    }

    if(ispal) cout<<"Palindrome";
    else cout<<"not Palindrome";

    return 0;
}





// count vowels and consonents
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int v=0;
    int c=0;

    for(int i=0;str[i]!='\0';i++){
        char ch=str[i];
        if(ch>='A' && ch<='Z') ch+=32;

        if(ch>='a' && ch<='z') {
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') v++;
            else c++;
        }
    }
    
    cout<<"No. of vowels: "<<v<<"and consonent: "<<c<<endl;

    return 0;
}

//or
#include<iostream>
#include<string>
#include<algorithm>                          
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int v=0,c=0;
    for(char ch :str){
        ch=tolower(ch);
        if(isalpha(ch)){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') v++;
            else c++;
        }
    }
    cout<<"Count of vowel : "<<v<<" and consonent: "<<c<<endl;
}





//remove duplicate
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    string res="";
    
    for(int i=0;str[i]!='\0';i++){
        bool flag= false;
        for(int j=0;j<res.length();j++){
            if(str[i]==res[j]){ // if str[i] is  already there is result  make flag true 
                flag=true;
                break;
            }

        }
        if(!flag) res+=str[i];  //only add char that do no repeat
    }

    cout<<"After removal of duplicates: "<<res<<endl;
    return 0;
}






//anagrams ( have the same frequency of each character.)
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool areAnagrams(string s1,string s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if (s1==s2) return true;
    return false;

}
int main(){
    string s1="listen", s2="silent";
    if(areAnagrams(s1,s2)) cout<<"are anagrams"<<endl;
    else cout<<"not anagrams"<<endl;

    return 0;
}





//find character in the string
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);
    char c;
    cout<<"Enter the character: ";
    cin>>c;
    int idx=-1;
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]==c){
            idx=i;
            break;
        }
    }
    if(idx!=-1) cout<<c<<" is present at index "<<idx<<endl;
    else cout<<c<<" is not found"<<endl;

    return 0;
}

//or
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);
    char c;
    cout<<"Enter the character: ";
    cin>>c;
    int idx=s1.find(c);
    int lidx=s1.rfind(c);  //last occurrence of c

    if(lidx!=-1) cout<<"Last index of "<<c<<" "<<lidx<<endl;
    if(idx!=-1) cout<<c<<" is present at index "<<idx<<endl;
    else cout<<c<<" is not found"<<endl;

    return 0;
}






//remove vowel 

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);
    string vow= "AEIOUaeiou";
    for(int i=0;s1[i]!='\0';i++){
        //if(! notfound) -> means it is found so erase it
        if(vow.find(s1[i])!= string::npos){  //string::npos means “not found”
            s1.erase(i,1); //(Pos,length)
            i--;   //since the char is erased from that pos, so now a new char is present there,, so we'll check that char too
        }
        
    }
    cout<<"without vowels: "<<s1<<endl;

    return 0;
}




