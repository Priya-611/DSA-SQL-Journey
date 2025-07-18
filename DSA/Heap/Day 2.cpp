//Inserting a new element in Heap:
//in MAX HEAP
#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){  //heap is build
    int larIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;
    if(l<n && a[l] > a[larIdx]) larIdx=l;
    if(r<n && a[r] > a[larIdx]) larIdx=r;

    if(larIdx!=idx){
        swap(a[larIdx],a[idx]);
        heapify(a,n,larIdx);
    }
}

void build_heap(int a[], int n){
    for(int k=(n/2)-1;k>=0;k--){
        heapify(a,n,k);
    }
}


void insertHeap(int a[], int &n, int num){  //insertion of new element is done
    n++;   //as new element is added increse value of n by 1 [it's like saying i want to use one more space from fixed space i.e. 100]
    int i=n-1; //inserting num at last  position
    a[i]=num;
    while(i>0 && a[(i-1)/2]< a[i]){  //checking if parent of inserted element is smaller , if it is , swap
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;  //and keep checking all parent [if they are smaller]
    }

}

int main(){
    int a[100];  //fixing array size as in array resizing is not possible [so initially keeping a safe size]

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);  //heap is build using current elements

    int num;
    cout<<"Enter new number to be inserted: ";
    cin>>num;

    cout<<"Elements in Max Heap before insertion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    insertHeap(a,n,num);  //heap is modified after inserting new element

    cout<<"Elements in Max Heap after insertion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

}




//Insertion in MIN HEAP  [just change condition in if and while loop]
#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){  //heap is build
    int smallIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;
    if(l<n && a[l] < a[smallIdx]) smallIdx=l;
    if(r<n && a[r] < a[smallIdx]) smallIdx=r;

    if(smallIdx!=idx){
        swap(a[smallIdx],a[idx]);
        heapify(a,n,smallIdx);
    }
}

void build_heap(int a[], int n){
    for(int k=(n/2)-1;k>=0;k--){
        heapify(a,n,k);
    }
}


void insertHeap(int a[], int &n, int num){  //insertion of new element is done
    n++;   //as new element is added increse value of n by 1 [it's like saying i want to use one more space from fixed space i.e. 100]
    int i=n-1; //inserting num at last  position
    a[i]=num;
    while(i>0 && a[(i-1)/2] > a[i]){  //checking if parent of inserted element is large , if it is , swap
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;  //and keep checking all parent [if they are large]
    }
}

int main(){
    int a[100];  //fixing array size as in array resizing is not possible [so initially keeping a safe size]

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);  //heap is build using current elements

    int num;
    cout<<"Enter new number to be inserted: ";
    cin>>num;

    cout<<"Elements in Min Heap before insertion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    insertHeap(a,n,num);  //heap is modified after inserting new element

    cout<<"Elements in Min Heap after insertion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

}


/*insertHeap() -> take new new  , increase size of array and add the new num at last of heap
make it satisfy the heap property by checking if it is greater(smaller) than it's parent, and swap accordingly and keep checking all parents*/






//Deletion:
//in MAX HEAP
#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){  //heap is build
    int larIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;
    if(l<n && a[l] > a[larIdx]) larIdx=l;
    if(r<n && a[r] > a[larIdx]) larIdx=r;

    if(larIdx!=idx){
        swap(a[larIdx],a[idx]);
        heapify(a,n,larIdx);
    }
}

void build_heap(int a[], int n){
    for(int k=(n/2)-1;k>=0;k--){
        heapify(a,n,k);
    }
}


void deleteHeap(int a[], int &n, int num){  //deletion
    int idx=-1;
    for(int i=0;i<n;i++){
        if(a[i]==num){  //search for the element to be deleted
            idx=i;
            break;
        }
    }
    if(idx==-1) {
        cout<<"Element is not found in the heap.\n";
        return;
    }
    //if element is found swap the element with the last element 
    swap(a[idx],a[n-1]);
    n--;  //and reduce the size of array by 1[i.e do not use or look for the last position as it contain element that was to be deleted]
    heapify(a,n,idx);  //now heapify the whole heap with new size and new element at idx
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int a[n]; 
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);  //heap is build using current elements

    int num;
    cout<<"Enter a number to be deleted: ";
    cin>>num;

    cout<<"Elements in Max Heap before deletion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    deleteHeap(a,n,num);  //heap is modified after deleting the element

    cout<<"Elements in Max Heap after deletion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

}




//Deletion in MIN HEAP  [just change condition in if ]
#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){  //heap is build
    int smallIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;
    if(l<n && a[l] < a[smallIdx]) smallIdx=l;
    if(r<n && a[r] < a[smallIdx]) smallIdx=r;

    if(smallIdx!=idx){
        swap(a[smallIdx],a[idx]);
        heapify(a,n,smallIdx);
    }
}

void build_heap(int a[], int n){
    for(int k=(n/2)-1;k>=0;k--){
        heapify(a,n,k);
    }
}

void deleteHeap(int a[], int &n, int num){  //deletion 
    int idx=-1;
    for(int i=0;i<n;i++){
        if(a[i]==num){  //search for the element to be deleted
            idx=i;
            break;
        }
    }
    if(idx==-1) {
        cout<<"Element is not found in the heap.\n";
        return;
    }
    //if element is found swap the element with the last element 
    swap(a[idx],a[n-1]);
    n--;  //and reduce the size of array by 1[i.e do not use or look for the last position as it contain element that was to be deleted]
    heapify(a,n,idx);  //now heapify the whole heap with new size and new element at idx
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int a[n]; 
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);  //heap is build using current elements

    int num;
    cout<<"Enter a number to be deleted: ";
    cin>>num;

    cout<<"Elements in Min Heap before deletion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    deleteHeap(a,n,num);  //heap is modified after deleting the element

    cout<<"Elements in Min Heap after deletion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

}


/*deleteHeap() -> search for element to be deleted and swap it with the last element in heap, 
reduce size of array by 1 and heapify the new eleemnt at that index*/





//Normally in heaps we delete root (max element), not arbitrary elements.  So let's WAP to delete the root element
//in MAX HEAP
#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){  //heap is build
    int larIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;
    if(l<n && a[l] > a[larIdx]) larIdx=l;
    if(r<n && a[r] > a[larIdx]) larIdx=r;

    if(larIdx!=idx){
        swap(a[larIdx],a[idx]);
        heapify(a,n,larIdx);
    }
}

void build_heap(int a[], int n){
    for(int k=(n/2)-1;k>=0;k--){
        heapify(a,n,k);
    }
}

void deleteRoot(int a[], int &n){  //deletion
    if(n<=0){
        cout<<"Array is empty";
        return;
    }
    a[0]=a[n-1];  //swap root element with last element
    n--;     //reduce size by 1
    heapify(a,n,0);  //heapify the whole tree by passing the root index
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int a[n]; 
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);  //heap is build using current elements

    cout<<"Elements in Heap before deletion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    deleteRoot(a,n);  //heap is modified after deleting the root

    cout<<"Elements in Max Heap after deletion: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

}








// Q) Program to create a Max Heap where second largest is at root and largest at n‑1
#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){  //heap is build
    int larIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;
    if(l<n && a[l] > a[larIdx]) larIdx=l;
    if(r<n && a[r] > a[larIdx]) larIdx=r;

    if(larIdx!=idx){
        swap(a[larIdx],a[idx]);
        heapify(a,n,larIdx);
    }
}

void build_heap(int a[], int n){
    for(int k=(n/2)-1;k>=0;k--){
        heapify(a,n,k);
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int a[n]; 
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);  //heap is build using current elements

    cout<<"Elements in Max Heap before modification: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    swap(a[0],a[n-1]);  //swap root element with last element

    heapify(a,n-1,0);  //heapify the whole tree by passing the root index except the new last index(the largest)

    cout<<"Elements in Max Heap after modification: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

}






// Q) Max‑Heap insertion with prime number check
#include<iostream>
using namespace std;

int idx=0;   //idx will keep record of the n. of values inserted

void insertHeap(int a[],int num){
    a[idx]=num;
    int po=idx;
    while(po>0 && a[po]> a[(po-1)/2]){
        swap( a[po] , a[(po-1)/2]);
        po=(po-1)/2;
    }
    idx++;
}

bool isPrime(int val){
    int count=0;
    for(int i=1;i<=val;i++){
        if(val%i==0) count++;
    }
    //1 is not prime by definition, so we handle that too.
    if(val==1 || count>2) return false;   //if count>2 that means there are extra divisors, so not prime. 
    return true;    //if count is exactly 2 [A prime number has exactly 2 divisors → 1 and itself.]
}

int main(){
    int n,val;
    cout<<"Enter the size of array: ";
    cin>>n;

    int a[n]; 
    cout<<"Enter elements: ";
    
    //inserting
    for(int i=0;i<n;i++){
        cin>>val;
        if(!isPrime(val)){
            cout<< val<<" is not prime number"<<endl;
        }
        else insertHeap(a,val);  //if val is prime insert it
    }

    //while printing use idx as the size of array  
    cout<<"Elements in Max Heap after modification: ";
    for(int i=0;i<idx;i++) cout<<a[i]<<" ";

}



