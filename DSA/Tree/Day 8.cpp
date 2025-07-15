// 144. Binary Tree Preorder Traversal
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
    vector<int>v;
    void func(TreeNode* root){
        if(root==NULL) return;
        v.push_back(root->val);
        func(root->left);
        func(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        func(root);
        return v;
    }
};





// 145. Binary Tree Postorder Traversal
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
    void func(TreeNode* root){
        if(root==NULL) return;
        func(root->left);
        func(root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        func(root);
        return v;
    }
};





// 257. Binary Tree Paths
/*
Input: root = [1,2,3,null,5]
    1
   / \
  2   3
   \
    5

Output: ["1->2->5","1->3"]
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
    vector<string> v;
    void func(TreeNode* root,string path){
        if(root==NULL) return ;
        if(!path.empty()) path+="->";  //add arrow only if there exist some value in path string
        path+=to_string(root->val);  //add the current value to pth by coverting it to string
        if(root->left==NULL && root->right==NULL){   //if it the leaf node  ,, add the path string in vector 
            v.push_back(path);
            return;
        }
        func(root->left,path);  //call the leftside till you reach the leaf node
        func(root->right,path);   //call the rightside till you reach the leaf node
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        func(root,"");  //intially pass empty string
        return v;
    }
};







// 404. Sum of Left Leaves
/*
    3
   / \
  9   20
     /  \
    15   7
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
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
    void sumNodes(TreeNode* root,int &sum,bool isLeft){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL && isLeft) {  //add only leaf node with isLeft==true
            sum+=root->val;
            return;
        }
        sumNodes(root->left,sum,true);   //when traversing left subtree keep isLeft=true
        sumNodes(root->right,sum,false);  //when traversing right subtree keep isLeft=false 
      //so that only the node is at the left of any other node [it is considered as left ]
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        sumNodes(root,sum,false);  //initailly root is not on the left side so pass false
        return sum;
    }
};






// 222. Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+ countNodes(root->left)+countNodes(root->right);
    }
};




