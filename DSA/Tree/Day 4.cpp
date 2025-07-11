
// 226. Invert Binary Tree
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

//approach:
//1. recursively call root->left and root->right
//2. swap them
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        //recursively invert left and right subtree 
        TreeNode *right=invertTree(root->right);
        TreeNode *left=invertTree(root->left);
        //swap them
        root->left=right;
        root->right=left;
        return root;

    }
};

//or
/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode *temp=root->right;
        root->right=invertTree(root->left);
        root->left=invertTree(temp);
        return root;
    }    
};
*/






// 104. Maximum Depth of Binary Tree
// Input: root = [3,9,20,null,null,15,7]
// Output: 3
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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return 1+ max(l,r);
    }
};






// 101. Symmetric Tree
// Input: root = [1,2,2,3,4,4,3]
// Output: true
/**
      1
     / \
    2   2
   / \ / \
  3  4 4  3

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
//recursion will work in this function
    bool check(TreeNode *t1, TreeNode *t2){
        if(t1==NULL && t2==NULL) return true;  //if both nodes are null return true
        if(t1==NULL || t2==NULL) return false;  //if any one is null return false
        if(t1->val!=t2->val) return false;    //if the value is different return false
        return check(t1->left,t2->right) && check(t1->right, t2->left);   //will check left of t1 with right of t2 [for mirror image] && right of t1 with left of t2

    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;    
        return check(root->left,root->right);  //call check function with left and rigth of root
    }
};





// 543. Diameter of Binary Tree
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// approach:
// Use a reference variable maxdiameter to keep track of max diameter.
// In the recursive function:
// Get left and right subtree heights.
// Update maxdiameter as max(dia, left + right).
// Return 1 + max(left, right) as current height.
  
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
    int maxdiameter=0;
    int dia(TreeNode *root){
        if(root==NULL) return 0;
        int l=dia(root->left);
        int r=dia(root->right);
        maxdiameter= max(maxdiameter,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return maxdiameter;
    }
};





// 112. Path Sum
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown.
/*
Function Calls:
hasPathSum(5, 22)
    → hasPathSum(4, 17)
        → hasPathSum(11, 13)
            → hasPathSum(7, 2)
              Not a leaf: sum ≠ 7 → false
            → hasPathSum(2, 2)
              Leaf node & val = 2 → ✅ true
Since left side returned true, final result is true.
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
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return targetSum==root->val;    //if the current node is a leaf node,,  if targetSum is equal to root->val[as targetSum is reduced by root->val in every call]
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);   //Recurse down to the left and right subtrees.[Subtract the current node’s value from targetSum.]
    }  
};






// 100. Same Tree
//Example 1: Input: p = [1,2,3], q = [1,2,3]   Output: true
//Example 2: Input: p = [1,2], q = [1,null,2]  Output: false
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};







// 110. Balanced Binary Tree
// [height of left subtree - right subtree must be <=1]
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
    int height(TreeNode *t){  //to find height
        if(t==NULL) return 0;
        int l=height(t->left);
        int r=height(t->right);
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(abs(height(root->left)-height(root->right))>1) return false;  //if height of left - right > 1 [it is not balanced]
        return isBalanced(root->right) && isBalanced(root->left);   //recursively check for left and right subtree
    }
};

