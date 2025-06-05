//Memory Allocation [providing space to a variable]
// Static: [providing space beforehand] [the size and data type of the variable remain constant throughout the program]

// Dynamic: [memory os allocated dynamically] [exact size is not known ] [Pointers are used]

//Stack: all the variable inside a function take memory from the stack
//Heap: unused memory in the program that is generally used for dynamic allocation

//dynamic allocation using new operator 
//pointer_var = new data_type
//int *m = new int
//float *f= new float(21.01)

//delete : delete pointer_name   [imp to free the memory]
//delete m
// delete [] arr









// An abstract class is a class that cannot be instantiated
//  (you can't create objects from it)
//  It usually serves as a blueprint for other classes.
// It has at least one pure virtual function:

// A concrete class is a regular class that can be instantiated 
// (you can create objects from it). 
// It implements all the functions, including any inherited pure virtual functions.












//resolving ambiquity using scope resolution operator (::)
// ambiquity: when both base classes have the same variable or function name , it causes ambiquity
//BaseClass :: member
#include<iostream>
using namespace std;

class Account{
    public:
    double b=5000;
    void getBal(){
        cout<<"Balance is: "<<b<<endl;
    }

};
class NewAcc{
    public:
    double b=10000;
    void getBal(){
        cout<<"Balance is: "<<b<<endl;
    }

};
class Cust: public Account, public NewAcc{
    public:
    void show(){

        //for function
        Account::getBal();
        NewAcc::getBal();

        //for variable
        cout<<"Current balance: "<< Account::b<<endl;
        cout<<"New account balance: "<< NewAcc::b<<endl;
        
    }
};
int main(){
    Cust c;
    c.show();

    return 0;
}













//Conversion:
//Decimal to Binary
#include<iostream>
using namespace std;
void decimalToBin(int n){
    int bin[32]; 
    int i=0;
    while(n>0){
        bin[i++]=n%2;  //store remainder
        n/=2; //dividing by 2
    }
    //printing bin array[each remainder] in reverse order
    for(int j=i-1;j>=0;j--){
        cout<<bin[j];
    }
}
int main(){
    int num;
    cout<<"Enter the decimal number: ";
    cin>>num;
    cout<<"Decimal to Binary: ";
    decimalToBin(num);
    
    return 0;
}





//Binary to Decimal 
#include<iostream>
using namespace std;
void BinaryToDeci(int n){
    int decimal=0;
    int base=1;
    while(n>0){
        int last=n%10;  //getting last digit
        decimal+=last*base;  //multiply last digit with base (power of 2) and add it to decimal
        base*=2; //increase the base with power of 2
        n/=10; // removing last digit 
    }
    cout<<decimal;
}
int main(){
    int num;
    cout<<"Enter the binary number: ";
    cin>>num;
    cout<<"Binary to decimal: ";
    BinaryToDeci(num);
    
    return 0;
}






//Decimal to Octal
#include<iostream>
using namespace std;
void decimalToOct(int n){
    int oct[32]; 
    int i=0;
    while(n>0){
        oct[i++]=n%8;  //store remainder
        n/=8; //dividing by 8
    }
    //printing oct array[each remainder] in reverse order
    for(int j=i-1;j>=0;j--){
        cout<<oct[j];
    }
}
int main(){
    int num;
    cout<<"Enter the decimal number: ";
    cin>>num;
    cout<<"Decimal to Octal: ";
    decimalToOct(num);
    
    return 0;
}








//Decimal to Hexadecimal
#include<iostream>
using namespace std;
void decimalToHex(int n){
    int hex[32]; 
    int i=0;
    while(n>0){
        int r=n%16;  //store remainder
        
        //if r < 10   -> in number format
        //else in Alphabet format ('A' to 'F')
        if(r<10) hex[i++]= r+'0';   // For 0 to 9 → '0' to '9'
        else hex[i++]=r-10 + 'A'; // For 10 to 15 → 'A' to 'F'

        n/=16; //dividing by 16
    }
    //printing hex array[each remainder] in reverse order
    for(int j=i-1;j>=0;j--){
        cout<<hex[j];
    }
}
int main(){
    int num;
    cout<<"Enter the decimal number: ";
    cin>>num;
    cout<<"Decimal to Hexadecimal: ";
    decimalToHex(num);
    
    return 0;
}




 
//or 
// using built-in function
//decimal to octal and hexadecimal
#include<iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter decimal: ";
    cin >> num;

    cout << "Octal: " << oct << num << endl;
    cout << "Hex: " << hex << num << endl;
    return 0;
}



// Decimal → Binary	bitset<16>(num)

// binary to decimal: 
// int decimal = stoi(binary, 0, 2); 

// hexadecimal to binary: 
// int decimal = stoi(hex, 0, 16); 

// octal to decimal:
// int decimal = stoi(octal, 0, 8);








//Patterns: 

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// *
// * *
// * * *
// * * * *
// * * * * *






#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}



// 1
// 1 2
// 1 2 3
// 1 2 3 4 
// 1 2 3 4 5
// 1 2 3 4 5 6





//Reverse Pattern:

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// 6 5 4 3 2 1
// 6 5 4 3 2
// 6 5 4 3 
// 6 5 4
// 6 5
// 6





#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// 1 2 3 4 5 6
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1





//Pyramid :

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){ //n rows
        for(int s=1;s<=n-i;s++) cout<<" ";   //n-i spaces
        for(int j=1;j<2*i;j++) cout<<"*";    // 2*i-1 stars
        cout<<endl;
    }
    return 0;
}

//    *
//   ***
//  *****
// *******







// Floyd's triangle
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int num=1;
    for(int i=1;i<=n;i++){ //n rows
        for(int j=1;j<=i;j++) cout<<num++<<" ";   
        cout<<endl;
    }
    return 0;
}

// 1
// 2 3
// 4 5 6
// 7 8 9 10






#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    char ch='A';
    for(int i=1;i<=n;i++){ //n rows
        for(int j=1;j<=i;j++) cout<<ch++<<" ";   
        cout<<endl;
    }
    return 0;
}

// A
// B C
// D E F
// G H I J







#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){ //n rows
        char ch='A';
        for(int j=1;j<=i;j++) cout<<ch++<<" ";   
        cout<<endl;
    }
    return 0;
}

// A
// A B
// A B C
// A B C D





#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){ //n rows
        char ch='A'+i-1;  //in each next line alpha will be incremented
        for(int j=1;j<=i;j++) cout<<ch<<" ";   
        cout<<endl;
    }
    return 0;
}

// A
// B B
// C C C
// D D D D





#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){ //n rows
        char ch='A'+i-1;  //in each next line it will print next alpha
        for(int j=1;j<=i;j++) cout<<ch++<<" ";   
        cout<<endl;
    }
    return 0;
}

// A
// B C
// C D E
// D E F G




//Reverse alpha: 
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=n;i>=1;i--){ //n rows
        char ch='A'+i-1;  //in each next line it will print next alpha
        for(int j=1;j<=i;j++) cout<<ch++<<" ";   
        cout<<endl;
    }
    return 0;
}

// E F G H I 
// D E F G 
// C D E
// B C 
// A





#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++){ //n rows
        char ch='A'+i-1;  //in each next line it will print next alpha
        for(int j=n;j>=i;j--) cout<<ch++<<" ";   
        cout<<endl;
    }
    return 0;
}

// A B C D E
// B C D E
// C D E 
// D E
// E






#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=n;i>=1;i--){ //n rows
        char ch='A'+i-1;  //in each next line it will print next alpha
        for(int j=i;j<=n;j++) cout<<ch++<<" ";   
        cout<<endl;
    }
    return 0;
}

// E            //5 to 5
// D E          //4 to 5
// C D E        //3 to 5
// B C D E      //2 to 5
// A B C D E    //1 to 5



