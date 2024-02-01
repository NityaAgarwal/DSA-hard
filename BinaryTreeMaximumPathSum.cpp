//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

class Solution {
public:
    int maxPathDown(TreeNode* root, int &maxi) {
        if (!root) return 0;
        //taking max with 0 in both the cases because if any of these comes out to be negative
        //then why should we even bother considering it - it will only reduce our sum
        int leftAns = max(maxPathDown(root->left, maxi), 0); 
        int rightAns = max(maxPathDown(root->right, maxi), 0);
        //result WITH split
        //so here all three will be considered - root and left and right
        //and since it could potentially be our result, we will compare it to the 
        //previously computed value of maxi, and reset our maxi accordingly
        maxi = max(maxi, leftAns + rightAns + root->val);

        //but actually we cant split right? because that would mean taking both
        //the left and right paths - it will coz repetition of the nodes
        return max(leftAns, rightAns) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return  maxi;
    }
};
