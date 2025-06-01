//Vector
//dynamic array 
//can be resized 


// v.push_back(x)	-- Adds x to the end of the vector.
// v.size()	-- Returns the number of elements in the vector.
// v.capacity()	-- Returns the current allocated storage capacity.
// v[i] or v.at(i)	-- Access element at index i.
// v.insert(pos, val)	-- Inserts val before the position pos.
// v.pop_back()	-- Removes the last element.
// v.erase(pos)	-- Erases the element at the specified position pos.
// v.erase(v.end() - k)	-- Erases the element at the k-th position from the end.
// v.begin()  -- points to the first element.
// v.begin() + i   -- points to the (i+1)th element.
// v.end()  -- points to one past the last element.
// v.end() - k   -- gives the k-th element from the end.

#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(60);
    cout<<"First : "<<v[0]<<endl;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;   //capacity: total number of elements the vector can store without reallocating memory.
//   capacity keeps on incresing as we increase the size  (capacity >= size)
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";    //10 20 30 40 60
    }
    cout<<endl;

    v.insert(v.begin()+2,55);  //position(acc to first element),element   i.e 55 is inserted at 3rd pos

    v.pop_back();  //last element is removed

    v.erase(v.begin()+4);  //erasing element relative to first pos   //5th element is removed

    for(int e: v){
        cout<<e<<" ";    //10 20 55 30
    }
    cout<<endl;

    v.erase(v.end()-3);// remove 3rd element from end

    for(int e: v){
        cout<<e<<" ";    //10 55 30
    }

    return 0; 
}



