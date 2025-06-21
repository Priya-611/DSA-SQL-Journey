//OOPs
//Object-Oriented Programming
//Class-> blue-print for object that defines the variable and methods (user-defined datatype)
//Object-> instance of class(i.e. variable of type class )
//memory is allocated when object of the class is created
//object have all the properties, that are defined in the class


#include<iostream>
using namespace std;
class Fruit{
    public:  //so that we can access the properties if this class
    string name;
    string color;
    int quantity;
    void display(){
        cout<<quantity<<"- "<<name<<" has "<<color <<" color "<<endl;
    }
};
int main(){
    Fruit apple; // Datatype(class) variable name(object)    object created

    //1st way -> values assigned using dot operator
    apple.name="Apple";
    apple.color="Red";
    apple.quantity=2;
    apple.display();

    //2nd way -> values assigned using arrow operator
    Fruit *mango=new Fruit(); //pointer to a Fruit object
    mango->name="Mango";
    mango->color="Yellow";
    mango->quantity=4;
    mango->display();

    delete mango; //free memory

    return 0;
}








//setting values using functions and performing updation
#include<iostream>
using namespace std;
class Student{
    public:  
    string name;
    float marks;
    int roll;
    void set(string s, float m, int r){  //accepting values and setting as the varibles of particular object
        name=s;
        marks=m;
        roll=r;
    }
    float grace(){
        return marks+5;
    }
    void display(){
        cout<<name<<"with roll no: "<<roll<<" has marks: "<<marks<<endl;
    }


    
};
int main(){
    Student s1;
    s1.set("Mike",78.5,12);  //setting value as these

    Student s2;
    s2.set("Will",38.6,22);

    //if marks < 40 add grace marks 
    if(s1.marks<40) s1.marks= s1.grace();
    if(s2.marks<40) s2.marks= s2.grace();
    
    //display
    s1.display();
    s2.display();    

    return 0;
}






// constructor --> methods having same name as that of class and used to intialise the instance of an object
// automativally called when object is created
//default constructor -> A constructor with no parameters. Automatically called when an object is created without any arguments.
#include<iostream>
using namespace std;
class Students{
    public:  
    string name;
    float marks;
    int roll;
    Students(){
        name="Ansh";
        marks=60.1;
        roll=7;
    }
    
    void display(){
        cout<<name<<" with roll no: "<<roll<<" has marks: "<<marks<<endl;
    }


    
};
int main(){
    Students s;

    s.display();    

    return 0;
}





//Parametrized constructor -> A constructor that takes arguments to initialize the object.
#include<iostream>
using namespace std;
class Students{
    public:  
    string name;
    float marks;
    int roll;
   Students(string s, float m, int r){
        name=s;
        marks=m;
        roll=r;
    }
    
    void display(){
        cout<<name<<" with roll no: "<<roll<<" has marks: "<<marks<<endl;
    }


    
};
int main(){
    Students s1("Mike",78.5,12);
    Students s2("Will",38.6,22);
    

    s1.display();
    s2.display();    

    return 0;
}




//Copy constructor -> A constructor that creates a new object by copying another
#include<iostream>
using namespace std;
class Students{
    public:  
    string name;
    float marks;
    int roll;

    //parameterized constructor
    Students(string s, float m, int r){
        name=s;
        marks=m;
        roll=r;
    }


    //copy constructor
    Students(Students &s ){   // Pass by Reference
        name=s.name;
        marks=s.marks;
        roll=s.roll;
    }
    
    void display(){
        cout<<name<<" with roll no: "<<roll<<" has marks: "<<marks<<endl;
    }
    
};
int main(){
    Students s1("Mike",78.5,12);
    Students s2=s1;
    
    s2.display();    

    return 0;
}








// Access Specifier:
// public ->	Public stays public, Protected stays protected
// protected ->	Public becomes protected
// private ->	All inherited members become private


//Inheritance -> Inheritance allows a class (called the child or derived class) to inherit properties and behaviors (data members and methods) from another class (called the parent or base class).


//Single-Level Inheritance -> One base class → One derived class
//class <child_class> : <access_specifier>m <base_class>

#include<iostream>
using namespace std;
class Animal{
    public: 
    void eat(){
        cout<<"Animal eats xyz"<<endl;
    }
};
class Dog: public Animal{
    public:
    void bark(){
        cout<<"Dog barks"<<endl;
    }
};
int main(){
   Dog d;
   d.eat();  //able to access Animal(Parent class) property
   d.bark();

    return 0;
}




//Multi-Level Inheritance ->  A class is derived from a derived class(more than one base class and single derived class)


#include<iostream>
using namespace std;
class Person{
    public: 
    string name;
    void setName(string n){
        name=n;
    }
};
class Student: public Person{
    public:
    int roll;
    void setRoll(int r){
        roll=r;
    }
};
class EngineeringStudent: public Student{
    public:
    int cgpa;
    void setcgpa(float c){
        cgpa=c;
    }
    void display(){
        cout << name << " (Roll: " << roll << ") has cgpa:  " << cgpa << endl;
    }

};

int main(){
   EngineeringStudent es;
   es.setName("Steve"); //can access it parent's or grand-parent's property
   es.setRoll(45);
   es.setcgpa(8);
    es.display();
    return 0;
}





//Multiple Inheritance ->  One class inherits from more than one base class.

#include<iostream>
using namespace std;
class Teacher{
    public: 
    string uni;
    void setUni(string n){
        uni=n;
    }
};
class Worker{
    public:
    int duration;
    void setDur(int d){
        duration=d;
    }
};
class Researcher: public Teacher, public Worker{
    public:

    void display(){
        cout << "Research Assistant from " << uni<< " works " << duration << " hours/week." << endl;
    }


};

int main(){
   Researcher r;
   r.setUni("IIT"); //can access it both of its parent
   r.setDur(12);
   r.display();
    return 0;
}


//ambiquity in multiple inheritance:  when multiple base classes have same data member of function,, child class gets confused about which base class ton call
//this is resolve using scope resolution operator(::)
//obj.class_name::func()         //now object call func of mentioned class 







//Hierarchical Inheritance  -> Multiple derived classes inherit from single base class
#include<iostream>
using namespace std;
class Staff{
    public: 
    string uni;
    void setUni(string n){
        uni=n;
    }
};
class Teacher: public Staff{
    public:
    int id;
    void setId(int d){
        id=d;
    }

    void display(){
        cout << "Teacher from " << uni<< " has Id: " << id<< endl;
    }
};
class Researcher: public Staff{
    public:
    int dur;
    void setDur(int d){
        dur=d;
    }
    void display(){
        cout << "Research Assistant from " << uni<< " works " << dur << " hours/week." << endl;
    }


};

int main(){
   Teacher t;
   t.setUni("IIT"); 
   t.setId(1287);
   t.display();

   Researcher r;
   r.setUni("IIT"); 
   r.setDur(12);
   r.display();
    return 0;
}






// Hybrid Inheritance: combination of two or more types of inheritance (like single, multiple, multilevel, or hierarchical) in one program.
