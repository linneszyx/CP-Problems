class TrieNode {
    public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    TrieNode(){
        isWord = false;
    }
};
class WordDictionary {
    private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    bool searchelper(TrieNode * node , string &word,int index){
        if(index == word.size()) return node->isWord;
        if(word[index] == '.'){
            for(auto it : node->children){
                if(searchelper(it.second,word,index+1)) return true;
            }
            return false;
        }
        else{
            if(node->children.find(word[index]) == node->children.end()) return false;
            return searchelper(node->children[word[index]],word,index+1);
        }

    }
    bool search(string word) {
        return searchelper(root,word,0);
    }
};