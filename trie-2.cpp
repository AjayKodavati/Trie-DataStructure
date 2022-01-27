
class Node{
  public:
    Node* links[26];
    int wordsEnding = 0, preffixCount = 0;
  public:
    bool containsKey(char ch){
        return (links[ch - 'a'] != nullptr);
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void incrementPreffix(){
        preffixCount++;
    }
    
    void incrementCount(){
        wordsEnding++;
    }
    
    int getWordsCount(){
        return wordsEnding;
    }
    
    int getPreffixCount(){
        return preffixCount;
    }
    
    void deleteEnd() {
        wordsEnding--; 
    }
    void reducePrefix() {
        preffixCount--; 
    }
};
 


class Trie{
	
    public:
		Node* root;
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incrementPreffix();
        }
        node->incrementCount();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getWordsCount();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getPreffixCount();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }
        node->deleteEnd();
    }
};
