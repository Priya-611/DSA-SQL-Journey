//operators
//bitwise
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    int x=a&b;
    cout<<a<< " & " <<b<<" = "<< x <<endl;  //bitwise AND
    int y=a|b;
    cout<<a<< " | " <<b<<" = "<< y <<endl;  //bitwise OR
    int z=a<<b;
    cout<<a<< " << "<<b<<" = "<< z <<endl;  //left shift
    int w=a>>b;
    cout<<a<< " >> "<<b<<" = "<< w <<endl; //right shift
    int s= a^b;
    cout<<a<< " ^ "<<b<<" = "<< s <<endl;  //XOR
    cout<<"~"<<a<<" = "<<~a<<endl;
    

    return 0;
}



//some built-in functions

#include<iostream>
#include<math.h>
using namespace std;
int main(){

    int a,b ;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    cout<<"Square root of a: "<<sqrt(a)<<endl;
    cout<<"Cube root of a: "<<cbrt(a)<<endl;
    cout<<"Minimum of a and b: "<<min(a,b)<<endl;
    cout<<"Maximum of a and b: "<<max(a,b)<<endl;
    cout<<"a raised to the power b: "<<pow(a,b)<<endl;
    return 0;
}






//Functions
//swapping two numbers using call by reference

// #include<iostream>
using namespace std;
void swapValues(int &a, int &b){  //using & i.e. address operator so to make changes in the actual values
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    swapValues(a,b);
    cout<<"The value of a is "<<a<<endl;
    cout<<"The value of b is "<<b<<endl;

    return 0;
}





//calculating factorial of a number using recursion
#include<iostream>
using namespace std;
int factorial(int n){
    if (n==1) return 1;
    return n* factorial(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Factorial of "<<n<< " is "<<factorial(n)<<endl;

    return 0;
}




// fibonacci series using recursion

#include<iostream>
using namespace std;
int fibo(int n){
    if(n==0 || n==1) return 1;
    return fibo(n-1)+ fibo(n-2);
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<fibo(i)<<" ";
    }
    return 0;
}



