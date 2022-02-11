class Node{
  public:
    Node* links[2];
    
    bool containsKey(int bit){
        return (links[bit] != nullptr);
    }
    
    Node* getNode(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* newNode){
        links[bit] = newNode;
    }
};


class Trie{
  public:
    Node* root;

  Trie(){
      root = new Node();
  }
    
  void insert(int num){
      Node* node = root;
      for(int i = 31; i >= 0; i--){
          int currBit = (num >> i) & 1;
          if(!node->containsKey(currBit)){
              node->put(currBit, new Node());
          }
          node = node->getNode(currBit);
      }
  }
    
  int getMax(int num){
      Node* node = root;
      int currMax = 0;
      for(int i = 31; i >= 0; i--){
          int currBit = (num >> i) & 1;
          if(node->containsKey(1 - currBit)){
              currMax |= (1 << i);
              node = node->getNode(1- currBit);
          }
          else
              node = node->getNode(currBit);
      }
      return currMax;
  }
};
