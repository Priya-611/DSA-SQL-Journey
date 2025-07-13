
// 637. Average of Levels in Binary Tree
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
    vector<double> result;
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);  //firstly push the root node
        while(!q.empty()){  //till queue in not empty   <<< ------------------------------------------------- |
            double sum=0;                                                                  //                 |
            int size=q.size();                                                             //                 |
            for(int i=0;i<size;i++){  //use for loop till  size of queue                                      |
                TreeNode *node=q.front(); //get abd delete thre first node                                    |
                q.pop();                                                                  //                  |
                sum+=node->val;  // and add the node ->val                                                    |
                if(node->left!=NULL) q.push(node->left);   //add it's left and right child in the queue       |
                if(node->right!=NULL) q.push(node->right);                                 //                 |
                                                                                           //                 |                                              
            }                                                                              //                 |
            result.push_back(sum/size);  //after addition of a level us done push the avg in result vector  --^
        }
        return result;
        
    }
};








// 236. Lowest Common Ancestor of a Binary Tree
/*
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
If p = 5 and q = 1, return 3 (their LCA).
*/
/*Approach: DFS Recursive
We do a post-order traversal:
->If current node is NULL, return NULL.
->If current node is either p or q, return current node.
->Recur for left and right subtree.
->If both left and right are not NULL → this node is the LCA.
->Else → return non-null one (either p or q is deeper down one side).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;   
        if(p==root || q==root) return root;   //if while traversing root==p or root==q return root i.e.[ node with p or q]
          
        TreeNode* l=lowestCommonAncestor(root->left,p, q);  //recurse through left subtree 
        TreeNode* r=lowestCommonAncestor(root->right,p, q);  //recurse through right subtree
        if(l!=NULL && r!=NULL) return root;  //p and q are not null return the root[the parent of p and q][i.e. one if found at left subtree and another at right subtree]
  
//if one is null and other is non-null return one which is non-null
        if(l!=NULL)return l;    //[if any of the children is null just return the other]
        return r;
    }
};





// 235. Lowest Common Ancestor of a Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode *l=lowestCommonAncestor(root->left, p, q);
        TreeNode *r=lowestCommonAncestor(root->right, p, q);

        if(l!=NULL && r!=NULL) return root;
        if(l!=NULL) return l;
        return r;
    }
};





// 700. Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(val==root->val) return root;
        if(val<root->val) return searchBST(root->left,val);
        return searchBST(root->right,val);
    }
};





// 701. Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);  //root is null make enory for val and return that node
        if(root->val >val) root->left=insertIntoBST(root->left,val);
        else if(root->val < val) root->right=insertIntoBST(root->right,val);
        return root;

    }
};







// 653. Two Sum IV - Input is a BST
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
//make a vector and store values in sorted order,, then start adding 1st and last value
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
    void inorder(TreeNode* root, vector<int> &v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;  //v have values in sorted order(inorder)
        inorder(root,v);
        int l=0;
        int r=v.size()-1;
        while(l<r){  //till l < r  ,,add them and chcek the sum
            int sum=v[l]+v[r];
            if(sum==k) return true;
            else if(k>sum) l++;   //if (sum < k ) we need to add higher number therefore we will move l to next number [as v is in sorted order]
            else r--;   //if (sum > k)   we'll move r [lower number to be added]
        }
        return false;
    }
};






// 108. Convert Sorted Array to Binary Search Tree
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:
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
    TreeNode* build(vector<int> nums, int l,int r){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;   //find mid

        TreeNode* root=new TreeNode(nums[mid]);  //insert mid node
        root->left=build(nums,l,mid-1);  //on the left side [insert values less than mid]
        root->right=build(nums,mid+1,r); //on the right side [insert values more than mid]
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);  //pass array with size
    }
};


