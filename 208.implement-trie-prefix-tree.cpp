
class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie
{
private:
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
            {
                node->children[word[i] - 'a'] = new TrieNode();
            }
            node = node->children[word[i] - 'a'];
        }
        node->isEnd = true;

    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
            {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (node->children[prefix[i] - 'a'] == NULL)
            {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};

