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
#include<cmath>
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
//Pass by value: a copy of variable is passed( only value is passed ,, it doesn't affect the original)

//Pass by reference: Original variable is passed ( address with the value is passed)


//swapping two numbers using call by value

// #include<iostream>
using namespace std;
void swapByValue(int a, int b){  //using & i.e. address operator so to make changes in the actual values
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    swapByValue(a,b);
    //here no change will be done in main as the values are only swapped in swapByValue function
    cout<<"The value of a is "<<a<<endl;
    cout<<"The value of b is "<<b<<endl;

    return 0;
}




//swapping two numbers using call by reference

// #include<iostream>
using namespace std;
void swapByReference(int &a, int &b){  //using & i.e. address operator so to make changes in the actual values
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    swapByReference(a,b);
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





//Array


// largest and smallest no. in an array

#include<iostream>
using namespace std;
int main(){
    int arr[]={12,87,45,23,44,77};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0],min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    cout<<"Max: "<<max <<" and Min: "<<min<<endl;

    return 0;
}




//2D array


#include<iostream>
using namespace std;
int main(){
    int arr[2][3]={{12,34,56},{98,76,54}};  
    int arr2[][3]={{12,34,56},{98,76,54}};   //not necessarily imp to mention no. of rows
    int r=sizeof(arr)/sizeof(arr[0]);   //  = total size / size of one row
    int c=sizeof(arr[0])/sizeof(arr[0][0]);   //  = size of one row / size of one element
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
    }

    return 0;
}



//Example
#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the size of m and n: ";
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    int sum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=arr[i][j];
        }
    }
    cout<<"Sum: "<<sum<<endl;

    return 0;
}


//Pointer (basics)
// a variable that stores the 'address' of another variable not the actual value


#include<iostream>
using namespace std;

int main(){
    int a=10;
    cout<<"Value of a: "<< a <<endl;
    cout<<"Address of a: "<< &a <<endl;  // & = address-of operator (to store the address)

    // * = dereference operator (to get the value at a pointer's address)
    int *p;    // p is a pointer variable that can store address an int (it doesn't store an int value) 
    p = &a;
    cout<<"Pointer p stores: "<< p <<endl;
    cout<<"Value at address "<< &a <<" is "<< *p <<endl;
    return 0;
}



//call by reference using pointers

#include<iostream>
using namespace std;
void addGraceMarks(int *m){
    if(*m < 40) *m += 5;     // Dereference to access and modify the value
}
int main(){
    int marks;
    cout<<"Enter marks: ";
    cin>>marks;
    //or
    // int *p = &marks;
    // addGraceMarks(p);   //passing pointers
    addGraceMarks(&marks); //passing address-of marks which is of type pointer
    cout<<"Marks after updation: "<<marks<<endl;


    return 0;
}




// array with pointer


#include<iostream>
using namespace std;
int main(){
    int arr[]={7,5,2};
    int *p = &arr[0]; //points to 7
    cout<< ++*p <<endl; // add 1 to *p (7)  i.e 1+7 = 8

    int *p1= p+1;  //next location to p i.e. '5'
    cout<<*p1<<endl;

    cout<< *++p <<endl;   //points to 5   i.e. ++p -> next address after 7 ,,* ->value at that address

        
    return 0;
}



//wild pointer -> pointer only declared but not initialised   int *p;


//null pointer ->   pointer assigned NULL value   int *p=NULL;


//dangling pointer -> pointer that points to an invalid memory location,, earlier points to a variable but now that variable doesn't exist
                                                       
                        // int* get(){
                        //     int x=100;  //local variable
                        //     return &x; //returning address of local variable //DANGLING
                        // }

                        // int main(){
                        //     int *p=get();
                        //     cout<<*p<<endl;  //undefined behaviour 

                        //     return 0;
                        // } 
                        
//void(generic) pointer -> special pointer that can point to any datatype value, cannot be dereferenced  ,,  so we typecast
                        // int main(){
                        //     int x=10;
                        //     float f=8.7;

                        //     void *p;

                        //     p=&x;  //p points to x
                        //     cout<<*(int *)p<<endl;  //dereferencing way 1

                        //     p=&f;  //p points to f
                        //     float *fp=(float *)p;  //dereferencing way 2
                        //     cout<<*fp<<endl;  

                        //     return 0;
                        // }





//String

#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter a sentence: ";
    getline(cin,s);
    cout<<s<<endl;
    cout<<s[1]<<endl;
    return 0;
}

