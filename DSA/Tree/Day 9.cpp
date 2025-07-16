
// 129. Sum Root to Leaf Numbers
// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.

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
    int findSum(TreeNode * root, int sum){
        if(root==NULL) return 0;
        sum = sum*10 + root->val;    //building the number
        if(root->left==NULL && root->right==NULL) return sum;   //if it's the leaf node return it
        return findSum(root->left,sum)+ findSum(root->right,sum);   //otherwise  keep getting sum from  left and right subtree
    }
    int sumNumbers(TreeNode* root) {
        return findSum(root,0); //initially sum is 0
    }
};







// 450. Delete Node in a BST
// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
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
    TreeNode* getSucc(TreeNode* root){  //find inorder successor i.e. the leftmost node in right subtree
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key<root->val){ //if key is small search in left node
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){ //if key is small search in right node
            root->right=deleteNode(root->right,key);
        }
        else{  //if key is found
            if(root->left==NULL && root->right==NULL){  //if it is leaf node
                delete root;
                return NULL;
            }
            else if(root->left==NULL){  //if it has no left child return right child
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){  //if it has no right child return left child
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
          //if node found have both children ,find first inorder successo in right subtree
            TreeNode *succ=getSucc(root->right);
            root->val=succ->val;   //replace value with inorder succcessor value
            root->right=deleteNode(root->right,succ->val);  //and delete the successor value from right subtree
        }
        return root;
    }
};






// 530. Minimum Absolute Difference in BST
// Input: root = [4,2,6,1,3]
// Output: 1
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
    void inorder(TreeNode *root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int minD=INT_MAX;
        for(int i=1;i<v.size();i++){
            minD=min(minD,v[i]-v[i-1]);
        } 
        return minD;
    }
};







// 1026. Maximum Difference Between Node and Ancestor
// Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

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
    int findDiff(TreeNode *root, int currMin,int currMax){
        if(root==NULL) return currMax-currMin;  //if root is Null calculating difference

        currMin=min(currMin,root->val);  //it hold the minimum value amoung the [current root and minimum value till now]
        currMax=max(currMax,root->val);  //it hold the maximum value amoung the [current root and maximum value till now]
      
        int left=findDiff(root->left,currMin,currMax);  //for each root we'll traverse it's left subtree
        int right=findDiff(root->right,currMin,currMax);  //for each root we'll traverse it's right subtree
      
        return max(left,right);  //the ,max value amoung the left and right subtree diffeence calculated

    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        return findDiff(root,root->val,root->val);  //initailly root itself is minimum and maximum value
    }
};

