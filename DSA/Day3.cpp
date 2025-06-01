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




//removing duplicate elements

#include<iostream>
#include<vector>
#include<algorithm>  //includes standard algorithms like sorting & searching
//sort(begin, end) – Sorts the container.


using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    vector<int> v;
    int ele;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size()-1;){
        
        if(v[i]==v[i+1]) v.erase(v.begin()+i);   // don't increment i
        else i++;    // move to next only if no erase

    }

    cout<<"after removal: "<<endl;
    for(int ele: v)
    {
        cout<<ele<<" ";
    }
    return 0;
}



//algorithm header contains

// Sorting & Searching:
// sort(begin, end) – Sorts the container.

// binary_search(begin, end, key) – Checks if an element exists in a sorted container.

// find(begin, end, key) – Finds the first occurrence of a value.

// Modification:
// reverse(begin, end) – Reverses elements.

// remove(begin, end, val) – Removes all instances of a value (used with erase).

// unique(begin, end) – Removes consecutive duplicates.

// transform() – Applies a function to each element.

// Utility:
// min() and max() – Get min or max values.

// count(begin, end, val) – Counts how many times a value occurs.




//2D vector

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter the no.of rows and columns: ";
    cin>>r>>c;
    // vector<vector<int>> matrix(rows, vector<int>(cols));
    /*vector<vector<int>> v (r , vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    cout<<"Elements are: ";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<v[i][j]<<" ";
        }
    }*/

    vector<vector<int>> v;
    for(int i=0;i<r;i++){
        vector<int> row;    //create a new row
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            row.push_back(x);  //add element to the row
        }
        v.push_back(row); //push the row into the vector
    }

    cout<<"Elements are: ";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<v[i][j]<<" ";
        }
    }

    
    return 0;
}
