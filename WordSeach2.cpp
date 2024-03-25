//https://leetcode.com/problems/word-search-ii/description/

class TrieNode {
public: 
    TrieNode* child [26];
    bool is_word;
    TrieNode() {
        for (int i = 0; i<26; i++) {
            this->child[i] = nullptr;
            is_word = false;
        }
    }
};
class Trie {
public: 
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (!p->child[index]) {
                p->child[index] = new TrieNode();
            }
            p = p->child[index];
        }
        p->is_word = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i<word.size(); i++) {
            int index = word[i]-'a';
            if (!p->child[index]) return false; //ensuring condition 1
            p = p->child[index];
        }
        return p->is_word;
    }

    void dfs(vector<vector<char>>&board, vector<vector<int>>&visited, vector<string>&ans, int row, int col, TrieNode* this_node, string word) {
        //base conditions
            //cond1 - out of bounds
            //cond2 - already visited
            //cond3 - the current character is not a child of the current node (basically, doesnt exist in trie)
        
        //cond 1 and 2
        if (row < 0 || row == board.size() || col < 0 || col == board[0].size() || 
        visited[row][col] == 1) return;
        //cond 3
        int index;
        bool found_in_children = false;
        for (int i = 0; i<26; i++) {
            index = board[row][col] - 'a';
            if (this_node -> child[index]) {
                found_in_children = true;
                break;
            }
        }
        if (!found_in_children) return; 

        // main logic
        visited[row][col] = 1; //mark as visited
        this_node = this_node -> child[index]; //shift to the next node
        word += board[row][col]; //add the current character to the word
        if (this -> search(word) && find(ans.begin(), ans.end(), word) == ans.end()) ans.push_back(word); //if found, add to answer
        //recursive calls
        this -> dfs(board, visited, ans, row+1, col, this_node, word);
        this -> dfs(board, visited, ans, row-1, col, this_node, word);
        this -> dfs(board, visited, ans, row, col+1, this_node, word);
        this -> dfs(board, visited, ans, row, col-1, this_node, word);
        //remove from visited
        visited[row][col] = 0;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> ans; //final ans
        vector<vector<int>> visited(m, vector<int>(n)); //keep track of visited nodes

        //step 1 - add all the words to the trie - make a prefix tree out of them
        Trie* trie = new Trie();
        for (auto w : words) {
            trie->insert(w);
        }
        
        //step 2 - call the recursive function
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                trie->dfs(board, visited, ans, i, j, trie->root, "");
            }
        }

        return ans;
    }
};
