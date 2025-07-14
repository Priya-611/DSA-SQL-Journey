// 98. Validate Binary Search Tree
// Input: root = [2,1,3]
// Output: true
/*LONG_MIN	-9223372036854775808	Smallest long value
LONG_MAX	9223372036854775807	Largest long value
firstly we'll compare the root with long min and long max
and then recusrively update the min and max value
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* t, long min ,long max){
        if(t==NULL) return true;
        if(min >= t->val || max <= t->val) return false;
        return check(t->left,min,t->val) && check(t->right,t->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);

    }
};
/*
      5
     / \
    3   7
   / \   \
  2   4   8
Each node checks:
5 in (-∞, ∞)
3 in (-∞, 5)
7 in (5, ∞)
and so on...
*/






// 199. Binary Tree Right Side View
/*
if the size of vector is same as the level [i.e. if this is the forts node n this level insert it]
firstly keep passing right side and if there's no right , then go to the left node 
You only add one node per level — the one you see first, which is the rightmost, because you explore right first
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void func(TreeNode * t,int l){
        if(t==NULL) return;
        if(l==v.size()) v.push_back(t->val);   //push only if size of vector is same as level i.e. this is the first rightmost node in this level
        func(t->right,l+1); // visit right subtree first
        func(t->left,l+1); // then the left subtree 
    }
    vector<int> rightSideView(TreeNode* root) {
        func(root,0);
        return v;
    }
};






