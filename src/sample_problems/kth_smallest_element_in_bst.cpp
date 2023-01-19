class Solution {
public:
    priority_queue<int> pq;
    int size;
    
    void help(priority_queue<int> &pq,TreeNode* root,int k){
        if(!root) return;
        
        if(pq.size()< k) pq.push(root->val);
        else if(root->val < pq.top()){
                pq.pop();
                pq.push(root->val);
            }
        
        help(pq,root->left,k);
        help(pq,root->right,k);

    }
    
    int kthSmallest(TreeNode* root, int k) {
        help(pq,root,k);
        return pq.top();
    }
};