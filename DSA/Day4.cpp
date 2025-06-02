//String

// length() or size() – Get string length
// substr() – Get a substring
// find() – Find characters or substrings
// append() / '+' – Combine strings
//getline(input_stream, variable, delimiter) ->delimiter is the char after which the reading will stop


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
