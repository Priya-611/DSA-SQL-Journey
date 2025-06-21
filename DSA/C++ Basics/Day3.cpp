//Searching

//linear search -> Check each element one by one until you find the target.
//binary search -> Keep dividing the array in half and check middle elements.(in sorted array)
#include<iostream>
#include<algorithm>
using namespace std;
int linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int k){
    int start=0,end=n-1;
    while(start<=end){
        int mid= start+ (end-start)/n;
        
        if(arr[mid]==k) return mid;
        else if (k < arr[mid]) end=mid-1;
        else start=mid+1;
    }
    return -1; 
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    //linear searching
    int key;
    cout<<"Enter target: ";
    cin>>key;
    int idx=linearSearch(arr,n, key);  
    cout<<key <<" is at index "<<idx<<endl;

    //binary searching
    sort(arr,arr+n);
    cout<<"Enter another key: ";
    int k;
    cin>>k;
    int i=binarySearch(arr,n, k);  
    cout<<k <<" is at index "<<i<<endl;

    return 0;
}




//Sorting

//bubble sort -> Repeatedly swap adjacent elements if they are in the wrong order.
//selection sort -> Select the smallest element and put it at the front.
//insertion sort -> Build sorted part one by one by inserting elements at correct positions.
//merge sort -> Divide the array, sort both halves, then merge.
//quick sort -> Choose a pivot, partition array around pivot, recursively sort parts.


// bubble-sort
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";


    return 0;
}




//selection-sort
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++){
        int small=arr[i]; //considering ith ele to be the smallest
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<small){  //if any smallest ele is found make it as smallest
                small=arr[j];
                idx=j;
            }
        }
        swap(arr[idx],arr[i]);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";


    return 0;
}




//insertion sort
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=1;i<n;i++){
        int temp=arr[i]; //considering i-th ele to be the smallest
        int j=i-1;
        while(temp<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";


    return 0;
}




//merge sort
#include<iostream>
using namespace std;
void conquer(int arr[], int left, int mid, int right){
    int i=left;
    int j=mid+1;
    int size=right-left+1;  //size of subarray
    int k=0;
    int b[size];
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];  //put whichever s the smallest
        }
        else{
            b[k++]=arr[j++];
        }
    }
    if(i<=mid) b[k++]=arr[i++];
    if(j<=right) b[k++]=arr[j++];
    
    for(int a=0;a<size;a++){  //copy merged array in original
        arr[left+a]=b[a];
    }
}
void divide(int arr[],int left,int right, int size){
    if(left<right){
        int mid= left+(right-left)/2;
        divide(arr,left,mid,size);
        divide(arr,mid+1,right,size);
        conquer(arr,left,mid,right);
    }
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    divide(arr,0,n-1,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}







//quick sort
#include<iostream>
#include<algorithm>
using namespace std;
int partition(int arr[], int l,int r){
    int pivot=arr[l]; //choosing left most elemennt as pivot
    int i=l+1;
    int j=r;
    while(i<=j){
        while(arr[i]<pivot) i++;  //keep moving if arr[i] < pivot
        while(arr[j]>pivot) j--;  //keep moving if arr[j] > pivot
        if(i<j) swap(arr[i],arr[j]);  //swap both
    }
    swap(arr[j],arr[l]);  //pivot is swapped with arr[j] which is smallest
    return j;
}
void quickSort(int arr[], int l, int r){
    if(l<r){
        int idx=partition(arr,l,r);
        quickSort(arr,l,idx-1);
        quickSort(arr,idx+1,r);
    }
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}






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
