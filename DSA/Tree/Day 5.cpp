// 111. Minimum Depth of Binary Tree
// Input: root = [3,9,20,null,null,15,7]
// Output: 2

// | Case                     | What We Do                   |
// | ------------------------ | ---------------------------- |
// | Both left and right NULL | return 1                     |
// | One child NULL           | Go through the other subtree |
// | Both present             | Take min of the two depths   |

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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL) return 1+minDepth(root->right);   // If left is NULL, go right
        if(root->right==NULL) return 1+minDepth(root->left);   // If right is NULL, go left
        int l=minDepth(root->left);  
        int r=minDepth(root->right);
        return 1+min(l,r);    // If both children exist, take min of left & right
    }
};







// 113. Path Sum II
// return all root-to-leaf paths where the sum of the node values in the path equals targetSum
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22

/*approach:
->Use DFS (Depth-First Search) to explore all root-to-leaf paths.
->Maintain:A vector path to store the current path, An integer targetSum that you reduce as you go deeper.
->When a leaf node is reached: If the remaining targetSum == node->val, add the path to the result.
->After visiting a node (and its children), backtrack by removing it from the path.
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
public:   //result will store path vector
    vector<vector<int>>result;
    void findPath(TreeNode* root,vector<int> path,int targetSum){
        if(root==NULL) return ;
        path.push_back(root->val);   //firstly add current value in path 
        targetSum-=root->val;   //and subtract root value from Sum

        if(root->left==NULL && root->right==NULL && targetSum==0){    //if it is leaft node and targetSum == 0 ,then add the path in result
            result.push_back(path);
        }
        else{  //else recursively traverse the left path first and then right
            findPath(root->left,path,targetSum);
            findPath(root->right,path,targetSum);
        }
        path.pop_back();  //at last remove the val[for example we reached at the end and path is not found, the value will be popped back and go to previous function to check for right subtree]
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        findPath(root,path,targetSum);
        return result;
    }
};







// 572. Subtree of Another Tree
// if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

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
/*
//this solution works el but have logical error as it check if the two trees are the same by using isSubtree(...) recursively.
//as it says: "Let’s see if the left child of root contains subRoot’s left child as a subtree, and the right child of root contains subRoot’s right child as a subtree."
//which is eventually not a good idea because if there's any way when root tree has same values at multiple node, code will return wrong output
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        if(root->val==subRoot->val){
            return isSubtree(root->left,subRoot->left) && isSubtree(root->right,subRoot->right);
            // return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    
    }
};
*/
//optimal 
//“Let’s check whether the entire subtree rooted at root is exactly equal to the entire subtree rooted at subRoot.”
//therefore we'll use a different function to check Same values and Same structure (e.g., left is NULL in both trees, right is NULL in both trees)
class Solution {
public:
    bool same(TreeNode *t1, TreeNode* t2){
        if(t1==NULL && t2==NULL) return true;
        if(t1==NULL || t2==NULL) return false;
        if(t1->val!=t2->val) return false;      
      
        return same(t1->left,t2->left) && same(t1->right,t2->right); //keep checking right and left subtree [if it is same]
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(same(root,subRoot)) return true;
      //"If root itself doesn’t match subRoot, then maybe subRoot is located somewhere deeper in root — either in the left subtree or the right subtree."
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);  //recursively searches for the subRoot in: root->left subtree or root->right subtree
    
    }
};







// 872. Leaf-Similar Trees
// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    vector<int> a;
    vector<int> b;
    
    void store(TreeNode *t,vector<int> &v){   //store leaf nodes of root1 and root2 in vector a and vector b respectively
        if(t==NULL) return;
        if(t->left==NULL && t->right==NULL){
            v.push_back(t->val);
            return;
        }
        store(t->left,v);
        store(t->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        store(root1,a);
        store(root2,b);
        return a==b;   //compare both vectors    
    }
};





// 94. Binary Tree Inorder Traversal
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
    void display(TreeNode* root){
        if(root==NULL) return ;
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        display(root);
        return v;
    }
};







// 938. Range Sum of BST
// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
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
class Solution {   //as it is BST all value on left < root ,, and all value in right > root
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        if(root->val > high) return rangeSumBST(root->left,low,high);   // All values in left subtree will also be > high, so we'll call the left subtree
        if(root->val < low) return rangeSumBST(root->right,low,high);   // All values in left subtree will also be < low,  so we'll call right subtree
        return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);   //if the root is inclusive in range, add it, and call right and left both
    }
};


