//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private: 
    void mySerial (TreeNode* root, ostringstream &oss) {
        if (root) {
            //that is if the root exists
            oss << root->val << ' ';
            mySerial(root->left, oss);
            mySerial(root->right, oss);
        }
        else {
            oss << "# ";
        }
    }
    TreeNode* myDeserial(istringstream &iss) {
        string val;
        iss >> val; //means read 'iss', and store the contents till first whitespace into 
        //the variable 'val'
        if (val == "#") {
            //means use it for null
            return NULL;
        }
        TreeNode* root = new TreeNode (stoi(val));
        root->left = myDeserial(iss);
        root->right = myDeserial(iss);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss; //made an object of the output stream class
        mySerial(root, oss);
        return oss.str(); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss {data};
        return myDeserial(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
