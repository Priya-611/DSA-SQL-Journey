//memeory initialiser list (part after the colon (:) in a constructor, used to initialize data members directly before the constructor body runs.)
#include<iostream>
using namespace std;
class Emp{
    string name;
    float salary;
    public: 
    Emp(string n, float s): name(n), salary(s){}
    void calSalary(){
        cout<<name<<"has salary: "<<salary<<endl;
    }
};
int main(){
    Emp e("Steve",80000);  //using parent class reference to point to child class
    e.calSalary();
    return 0;
}


//Polymorphism  (many froms)  [the same function name or operator behaves differently in different situations.]

//Compile-time polymorphism -> Early binding / static binding / directly associated an addresss to function call
//1. Method overloading (same function name, different parameters) 
#include<iostream>
using namespace std;
class Poly{
    public: 
    int sum(int a ,int b){
        return a+b;
    }
    int sum(int a, int b, int c, int d){  //by changing the no. of parameters
        return a+b+c+d;
    }
    double sum(double a,double b){   //by changing the datatype of parameters
        return a+b;
    }
    void show (string s, int age){
        cout<<s<<" has age: "<<age<<endl;
    }
    void show (int age,string s){
        cout<<"Age of "<<s<<" is "<<age<<endl;
    }
};


int main(){
    Poly p;
    cout<<p.sum(12,11)<<endl;
    cout<<p.sum(1,4,6,2)<<endl;
    cout<<p.sum(12.7,23.6)<<endl;
    
    p.show("Ansh",12);
    p.show(28,"Steve");
    return 0;
}

// Note: Changing only the return type does not constitute overloading





//2. Operator Overloading -> (Overloading + operator for custom addition of two complex numbers) [allows you to redefine the behavior of standard operators (like +, -, ==, etc.) for user-defined types (classes).]
//returnType operator symbol(arguments){   }

#include<iostream>
using namespace std;
class Complex{
    float real,img;
    public: 
    Complex(float real,float img){
        this->real=real;  //this is a pointer to the current object.(used when class member and passed parameters have same name)
        this->img=img;
    }
    Complex operator +(Complex &c){
        return Complex(real + c.real, img + c.img);
    }
    //or
    // Complex add(Complex c) {
    //     return Complex(real + c.real, imag + c.imag);
    // }
    void display(){
        cout<<real<<" + "<<img<<"i"<<endl;
    }
};


int main(){
    Complex c1(2.5,3.5), c2(1.5,6.5);
    Complex c3= c1 + c2;  //internally c1.operator+(c2);  //here objects are added (so we need to overload operator)
    //or 
    //Complex c3= c1.add(c2);
    c3.display();
    return 0;
}






//Run-time polymorphism -> Late binding / dynamic binding / occur when we make implicit or indirect function calls
//1. Virtual function -> declared 'virtual' in base class 
//with virtual function call depends on object type / Calls derived class function
#include<iostream>
#include<cmath>   //for M_PI
using namespace std;
class Shape{
    public: 
    virtual float area(){  //without virtual both the objects would have called base class function
        return 0;
    }
};
class Circle : public Shape{
    float radius;
    public: 
    Circle(float rad){
        radius=rad;
    }
//without 'override' if any spelling error occur it would call parent class function 
//(but with 'override' if any  spelling error ocuur it will throw error)
    
    float area() override{
        return M_PI*radius*radius;
    }
};
class Rectangle : public Shape{
    float len,wd;
    public: 
    Rectangle(float l,float w){
        len=l;
        wd=w;
    }
    float area() override{
        return len*wd;
    }
};


int main(){
    Shape *s1 = new Circle(5.4);  //s1 oject points to Circle  i.e. pointer type is parent type and it calls child class version
    Shape *s2= new Rectangle(4.5,6.1);  //s2 object points to Rectangle
    cout<<"Area of circle : "<<s1->area()<<endl;
    cout<<"Area of rectangle : "<<s2->area()<<endl;
    return 0;
}





//2.Function Overriding -> when derived class provide a specific implememtation for a function already defined in its base class
//when a child class (derived class) has a function with the same name, same parameters, and same return type as in the parent class (base class).
// Child class replaces the behavior of a function from the base class.

#include<iostream>
using namespace std;
class Employee{
    public: 
    string name;
    Employee(string n):name(n){}
    virtual void calSalary(){
        cout<<name<<" has some salary "<<endl;
    }
};
class FullTimeEmp : public Employee{
    float salary;
    public: 
    FullTimeEmp(string n, float s): Employee(n), salary(s){}
    void calSalary(){
        cout<<name<<"has salary: "<<salary<<endl;
    }
};
class PartTimeEmp : public Employee{
    int hours;
    float Rate;
    public: 
    PartTimeEmp(string n, int h, float r): Employee(n), hours(h), Rate(r){}
    void calSalary(){
        float t=hours*Rate;
        cout<<name<<"has salary: "<<t<<endl;
    }
};


int main(){
    Employee *e;
    e= new FullTimeEmp("Steve",80000);  //using parent class reference to point to child class
    e->calSalary();
    delete e; //free the memory 

    e= new PartTimeEmp("Will",10, 500);
    e->calSalary();
    delete e;

    //or
    /*
    Employee *e;
    FullTimeEmp f("Steve",80000);          //here f and p are just short name 
    PartTimeEmp p("Will",10, 500);

    e=&f
    e->calSalary();

    e=&p
    e->calSalary(); 

    */

    return 0;
}








//Abstraction  (hiding internal implementation details and showing only essential features to the user.)
//1.using Abstract class  [with pure virtual function]
//a class with atleast one pure virtual function is an abstract class
#include<iostream>
using namespace std;
class ATM{
    public: 
    virtual void withdraw(double a) = 0;   //pure virtual function
};
class SBI: public ATM{
    double bal=10000;
    public:
    void withdraw(double a) override{
        if(a>bal) cout<<"insufficient balance"<<endl;
        else {
            bal-=a;
            cout<<a<<" withdrawn from bank"<<endl;
            cout<<"Balace left: "<<bal<<endl;
        }
    }
};

int main(){
    ATM *obj=new SBI(); 
    obj->withdraw(3000);
    delete obj;

    return 0;
}







// Encapsulation is the binding of data and functions that operate on that data into a single unit (class) and restricting direct access to some of the object's components.
// Achieved using access specifiers: private, public, and protected.

// Data (variables) are usually made private, and access is given via public getter/setter methods.

// Helps in data hiding and protection from unauthorized access.














