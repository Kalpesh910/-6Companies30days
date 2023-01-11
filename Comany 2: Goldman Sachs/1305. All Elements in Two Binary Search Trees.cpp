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
    void dfs(TreeNode* node, vector<int>& vec){
        if(node==NULL)  return;
        if(node->left!=NULL)    dfs(node->left, vec);
        vec.push_back(node->val);
        if(node->right!=NULL)   dfs(node->right, vec);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>vec1;
        vector<int>vec2;
        dfs(root1, vec1);
        dfs(root2, vec2);
        vector<int>ans;
        int i=0, j=0, m=vec1.size(), n=vec2.size();
        while(i<m && j<n){
            if(vec1[i] < vec2[j]){
                ans.push_back(vec1[i]);
                i++;
            }
            else{
                ans.push_back(vec2[j]);
                j++;
            }
        }
        while(i<m){
            ans.push_back(vec1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(vec2[j]);
            j++;
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
