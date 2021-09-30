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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if( root == nullptr )
            return result;
        else
        {
            result = postorderTraversal( root -> left );
            vector<int> right = postorderTraversal( root -> right );
            result.insert( result.end(), right.begin(), right.end() );
            result.push_back( root -> val );
        }
        return result;
    }
    
    vector<int> postorderTraversal_iterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> roots;
        
        while( root != nullptr || !roots.empty() )
        {
            while( root != nullptr )
            {
                roots.push( root );
                root = root -> left;
            }
            
            TreeNode* pCurRoot = roots.top();
            
            if( pCurRoot -> right == nullptr )
            {
                result.push_back( pCurRoot -> val );
                roots.pop();
            } 
            else
            {
                root = pCurRoot -> right;
                pCurRoot -> right = nullptr;
            }
                
        }
        
     
        return result;
    }
};
