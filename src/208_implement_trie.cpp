#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class TrieNode {
public:
    // Initialize your data structure here.
	bool isword;
	unordered_map<char, TrieNode*> umap;
    TrieNode(): isword(false) {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
		TrieNode* ptr = root;
		for(int i=0;i<word.size();i++){
			if(ptr->umap.find(word[i])==ptr->umap.end()){
				ptr->umap[word[i]] = new TrieNode();
			}
			ptr = ptr->umap[word[i]];
		}
		ptr->isword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
		TrieNode* ptr = root;
		for(int i=0;i<word.size();i++){
			if(ptr->umap.find(word[i])!=ptr->umap.end()){
				ptr = ptr->umap[word[i]];
			}
			else return false;
		}
		return ptr->isword;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		TrieNode* ptr = root;
		for(int i=0;i<prefix.size();i++){
			if(ptr->umap.find(prefix[i])!=ptr->umap.end()){
				ptr = ptr->umap[prefix[i]];
			}
			else return false;
		}
		return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main(){

}
