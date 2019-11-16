#include <memory>
#include <string>
#include <map>

class trie{

  private:
  class node;

  private:
  using letter_t = char;
  using word_t = std::string;
  using ptr_t = std::shared_ptr<node>;
  using connections = std::map<letter_t, ptr_t>;

  private:
  class node{
    public:
    bool is_word;
    connections childrens;

    public:
    node(void) = default;
    //node(const bool& is_word):is_word{is_word}{}

  };

  private:
  ptr_t root;

  private:
  void insert(ptr_t& actual, word_t word, const bool& is_word){
    if(!actual) actual = std::make_shared<node>();
    if(is_word) {actual->is_word = true; return;}

    letter_t letter = word[0];
    word.erase(begin(word));
    
    insert(actual->childrens[letter], word, word.length() == 0);
  }

  void erase(ptr_t& actual, word_t word, const bool& is_word){
    if(!actual) return;
    if(is_word) {actual->is_word = false; return;}

    letter_t letter = word[0];
    word.erase(begin(word));
    
    if(actual->childrens.find(letter) == actual->childrens.end()) return;
    erase(actual->childrens[letter], word, word.length() == 0);
    if(actual->childrens[letter]->childrens.empty()) actual->childrens.erase(letter);
    
  }

  void print(const ptr_t& actual, const unsigned int& tabs){
    if(actual)
     for(const auto& letter: actual->childrens){
      for(int i = 0; i<tabs; i++) std::cout<<'\t';
      std::cout<<letter.first<<std::endl;
      print(letter.second, tabs + 1);
      std::cout<<std::endl;
    }
  }

  public:
  void insert(const word_t& word){
    insert(root, word, false);
  }

  void erase(const word_t& word){
    erase(root, word, false);
    
  }

  void print(){
   print(root, 0);
  }

};