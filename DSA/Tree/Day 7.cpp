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






// 617. Merge Two Binary Trees
/*if any one child is null return the other
else keep adding both trees*/
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;   //if any one is null return other
        if(root2==NULL) return root1;
        root1->val+=root2->val;    //merge current nodes
        root1->left=mergeTrees(root1->left,root2->left);  //recursively ,merge left and right children
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;        
    }
};





// 102. Binary Tree Level Order Traversal
/*
      3
     / \
    9  20
       / \
      15  7
output: [[3], [9, 20], [15, 7]]

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
    vector<vector<int>>res;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);  //initially push the root
        while(!q.empty()){   //till queue is not empty
            int size=q.size();
            vector<int> v;  //a vector to store values
            for(int i=0;i<size;i++){    // a loop till the size of queue
                TreeNode *node=q.front();  //get the front node and push it's value in vector 
                q.pop();
                v.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            res.push_back(v);
        }
        return res;
    }
};





// 103. Binary Tree Zigzag Level Order Traversal
/*
      1
     / \
    2   3
   / \   \
  4   5   6
Output: [[1],[3, 2],[4, 5, 6]]
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
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;  //initially will have flag as true [val will be inserted at ith poition]
        while(!q.empty()){
            int size=q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++){ //loop works for a same level
                TreeNode* node=q.front();
                q.pop();
                int idx;
                // Choose correct index based on direction
                if(flag) idx=i;  //if flag is true, You are traversing Left to Right, So the values should be inserted in the same order
                else idx=size-i-1; //if flag is false , traversing right to left, so value will be inserted in reverse order
                v[idx]=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            res.push_back(v);
            flag=!flag;  // Flip direction for next level
        }
        return res;
    }
};






// 107. Binary Tree Level Order Traversal II
// the final array is reversed
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
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(),res.end());
        return res;

    }
};





// 513. Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(),res.end());
        return res[0][0];
    }
};
//here reverse(res.begin(), res.end()) adds an extra O(n) time + space overhead.
//optimal:
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l=root->val;  //store current value 
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(i==0) l=node->val;   //for each level if it's first iteration then this is the left-most node, at last we'll get bottom leftmost node
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        return l;
    }
};

