#include<iostream>   //Preprocessor directive for input/output    
using namespace std;   // to tell the complier that i'll be using standard namespace (container to group related things)
//standard (std) namespace contains common tools that are mostly used 
int main(){
    cout<<"HELLO WORLD!!"<<endl;
    cout<<"We are practising dsa using cpp";

    return 0;
}


//Variables

#include<iostream>
using namespace std;
int main(){
    int x=5,y=6;
    cout<<"x+y: "<<x<<" + " <<y<<" = "<<x+y<<endl;
    cout<<"x-y: "<<x++<<" - " <<y<<" = "<<x-y<<endl;
    cout<<"x*y: "<<x<<" * " <<++y<<" = "<<x*y<<endl;
    cout<<"x/y: "<<x<<" / " <<y<<" = "<<x/y<<endl;
    cout<<"x%y: "<<--x<<" % " <<y<<" = "<<x%y<<endl;

    return 0;
}



// Typecasting
 
#include<iostream>
#include<iomanip> ////"input-output manipulators", header file needed for formatting  eg: for setprecision
using namespace std;
int main(){
    int x;
    cout<<"Enter the value of x: ";
    cin>>x;
    float y=(float)x;
    cout<<"Floating value of x: "<<fixed << setprecision(1) <<y<<endl;   //will print upto 1 decimal point
    cout<<"Half of x: "<<y/2<<endl;   

    char ch;
    cout<<"Enter a character value: ";
    cin>>ch;
    cout<<"Ascii value of "<<ch<<" is "<<(int)ch<<endl;

    int z;
    cout<<"Enter a integer value: ";
    cin>>z;
    cout<<"Character value of "<<z<<" is "<<(char)z<<endl;

    return 0;

}



//if-else

#include<iostream>
using namespace std;
int main(){
    int amount;
    int balance=10000;
    cout<<"Enter the amount you want to withdraw: ";
    cin>>amount;
    if(amount <=0) cout<<"Enter a valid amount "<<endl;
    else if(amount%100==0) cout<<"Amount must be multiple of 100"<<endl;
    else if(amount>balance) cout<<"Insufficeint balance"<<endl;
    else{
        balance-=amount;
        cout<<"Withdrawal successfull"<<endl;
        cout<<"Current balance: "<<balance<<endl;
    }
    return 0;
}



//switch 

#include<iostream>
using namespace std;
int main(){
    int x,y;
    cout<<"Enter x and y with a space: ";
    cin>>x>>y;
    cout<<"Enter the symbol(+, -, /, *, %): ";
    char ch;
    cin>>ch;
    switch (ch){
        case '+':
            cout<<x+y<<endl;
            break;
        case '-':
            cout<<x-y<<endl;
            break;
        case '*':
            cout<<x*y<<endl;
            break;
        case '/':
            cout<<x/y<<endl;
            break;
        case '%':
            cout<<x%y<<endl;
            break;
        default:
            cout<<"invalid operator";
    }
    return 0;
}



//Ternary operator 

#include<iostream>
using namespace std;
int main(){
    int marks;
    cout<<"Enter the marks scored: ";
    cin>>marks;
    marks>=40?cout<<"Pass":cout<<"Fail"<<endl;
}


//for loop


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}




//while loop

#include<iostream>
using namespace std;
int main(){
    int num=60;
    int x;
    cout<<"Guess the number: ";
    cin>>x;
    while(num!=x){
        
        if(x<num){
            cout<<"Too low!! "<<endl<<"Try again: ";
        }
        else if(x>num){
            cout<<"Too high!!"<<endl<<"Try again: ";    
        }       
        
        cin>>x;
    }
    cout<<"You guesssed it right!!"<<endl<<"The number is "<<x<<endl;
            
    return 0;
}



//do-while

#include<iostream>
using namespace std;
int main(){
   string username="admin" ;
   string pass="1234";
   string u,p;
   do{
    cout<<"Enter username: ";
    cin>>u;

    cout<<endl<<"Enter password: ";
    cin>>p;

    if(username!=u || pass!=p){
        cout<<"Invalid credentials. Try again!!";
    }
   }
   while(username!=u || pass!=p);
   cout<<"Login successfull!!"<<endl;

   return 0;
}



//for-each loop


#include<iostream>
#include<iomanip>  
using namespace std;
int main(){
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter marks: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    double sum=0;
    for(int n: arr){
        sum+=n;
    }
    double avg=sum/n;
    cout<<"Average marks: "<<fixed<<setprecision(2)<<avg<<endl;

    return 0;
}



