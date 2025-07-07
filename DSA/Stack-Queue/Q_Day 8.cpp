// 1700. Number of Students Unable to Eat Lunch
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0 

// approach:
// if student need and sandwich availability is same take it and remove that student ,
// else until the need is satisfied remove student from front and push the student back in queue
// (but if count == q.size()	No one wants the current sandwich → stop [count tracks how many consecutive students have refused the current sandwich at the top of the stack.])
  
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int i=0;
        int count=0;
        while(!q.empty()){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                count=0;     // someone took the sandwich, reset the counter
            }
            else {
                q.push(q.front());
                q.pop();
                count++;    //increase count when student is pushed back 
            }
            if(count==q.size()) break;   //no one wants the current sandwich
        }
        return q.size();     //number of students unable to eat    
    }
};







// 950. Reveal Cards In Increasing Order
// Input: deck = [17,13,11,2,3,5,7]
// Output: [2,13,3,11,5,17,7]
// Explanation: 
// We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
// After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
// We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
// We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
// We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
// We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
// We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
// We reveal 13, and move 17 to the bottom.  The deck is now [17].
// We reveal 17.
// Since all the cards revealed are in increasing order, the answer is correct.


//aproach:
/* we need to return vector in such a order that at ending the order of revealed card is in ascending order 
that when we see the top card ,remove it and place the 2nd card at the bottom of queue 
to solve we'll think backwards i.e.  (i) sort the vector, (ii)Move last card to the front and (iii)place the new card at the front 

So firstly, Loop through sorted deck from largest to smallest:
If deque is not empty:
Move the last card to front (reverse of putting 2nd card to bottom)
Then insert the current card at front (undo revealing) 
*/
class Solution{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());    // sort the vector
        deque<int> dq;
        for(int i=deck.size()-1;i>=0;i--){
            if(!dq.empty()){
                dq.push_front(dq.back());   //Move last card to the front
                dq.pop_back();
            }
            dq.push_front(deck[i]);     //place the new card at the front 
        }
        vector<int> v(dq.begin(),dq.end());   //make vector v for the elements in deque
        return v;
    }
};






// 649. Dota2 Senate
// In each round, each senator can exercise one of the two rights:
// Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
// Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R') r.push(i);    //if it is R push index in queue r
            else d.push(i);                  //if it is D push index in queue d
        }
      //compare the front of both queue
        while(!r.empty() && !d.empty()){
            // Radiant senator acts first and bans the Dire senator
            // Push this Radiant back into queue with 'updated index' to simulate future round
            if(r.front() < d.front()) r.push(r.front()+senate.length()); 
              
            // Dire senator acts first and bans the Radiant senator 
            else d.push(d.front()+senate.length()); 

            //remove front from both queue
            r.pop();    
            d.pop();
        }
      //return whichever queue has elements
        if(!r.empty()) return "Radiant";
        return "Dire";
    }
};










