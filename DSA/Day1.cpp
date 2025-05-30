#include<iostream>
using namespace std;
int main(){
    cout<<"HELLO WORLD!!"<<endl;
    cout<<"We are practising dsa using cpp";
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
}



// Typecasting
 
#include<iostream>
#include<iomanip> //for setprecision
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

}


