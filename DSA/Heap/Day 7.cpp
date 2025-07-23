// 506. Relative Ranks
// Input: score = [10,3,8,9,4]
// Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
// Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
  
class Solution {
public:
    priority_queue<pair<int,int>> maxHeap;
    vector<string> findRelativeRanks(vector<int>& score) {
        int i=0;
        for(int num:score){
            maxHeap.push({num,i});  //push num firstly and then index
            i++;
        }
        vector<string> v(score.size());
        int a=1;
        //whichever num is at the top i.e. comes first i.e. the largest have rank one assign value at those indexes and increas a
        while(!maxHeap.empty()){
            auto [num,idx]=maxHeap.top();
            maxHeap.pop();
            if(a==1) v[idx]="Gold Medal";
            else if(a==2) v[idx]="Silver Medal";
            else if(a==3) v[idx]="Bronze Medal";
            else v[idx]=to_string(a);
            a++;
        }
        return v;
    }
};
/*
int a = 1;
a is a counter for rank:
a = 1 → highest score → Gold Medal,
a = 2 → second highest → Silver Medal,
a = 3 → third highest → Bronze Medal,
else → numeric rank.


Why use idx?
Because v must be in original order, so we place the result at the athlete’s original position.

auto [num, idx] = maxHeap.top();
Look at the top of the heap (highest score so far).
Decompose the pair into:
  num = score,
  idx = original index in the input.
*/




// 786. K-th Smallest Prime Fraction
// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// Explanation: The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// The third fraction is 2/5.

//using brute force
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<tuple<double,int,int>> v;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double val=(double)arr[i]/arr[j];
                v.push_back({val,i,j});
            }
        }
        sort(v.begin(),v.end(),[](const auto &a, const auto &b){
            return get<0>(a) < get<0>(b);
        });

        auto [val,i,j]=v[k-1]; //if we want 3rd smallest we'll get v[2] as it now sorted
        return {arr[i],arr[j]};
    }
};

/*std::sort (from <algorithm>) needs a way to compare two elements a and b.
👉 The comparison function (or lambda) must return true if a should come before b in the sorted order.

inside lambda funtion:
✅ get<0>(a) → the val from the first tuple.
✅ get<0>(b) → the val from the second tuple.
✅ We check: is a’s value less than b’s value?

If true, a will be placed before b in the sorted vector.
*/



