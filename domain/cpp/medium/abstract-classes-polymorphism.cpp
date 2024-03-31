#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache {
    private:
        Node *ptr_bf{};
    public:
        LRUCache(int capacity){
            this->cp = capacity;
        }

    void set(int k, int v) {
        if (mp.find(k) != mp.end()) { // if key found
            ptr_bf = mp[k];
            ptr_bf->value = v;

            if (ptr_bf->prev != nullptr) {
                if (ptr_bf->next == nullptr) {
                    tail = ptr_bf->prev;
                    ptr_bf->prev->next = nullptr;
                } else { 
                    ptr_bf->prev->next = ptr_bf->next;
                    ptr_bf->next->prev = ptr_bf->prev;
                }
                ptr_bf->prev = nullptr;
                ptr_bf->next = head;
                head = mp[k];
            }
        } else { 
            if (mp.empty()) { 
                Node *new_node = new Node(k, v);
                mp[k] = new_node;
                head = new_node;
                tail = new_node;
            } else if (mp.size() >= cp) { 
                mp.erase(tail->key);
                ptr_bf = tail->prev;
                delete tail;
                tail = ptr_bf;
                tail->next = nullptr;

                Node *new_node = new Node(nullptr, head, k, v);
                mp[k] = new_node;
                head->prev = new_node;
                head = new_node;
            } else {
                Node *new_node = new Node(nullptr, head, k, v);
                mp[k] = new_node;
                head->prev = new_node;
                head = new_node;
            }
        }
    }
        int get(int key) override{
            auto it = this->mp.find(key);
            if(it != this->mp.end()){
                return it->second->key == key ? it->second->value : -1;
            } else {
                return -1;
            }
        }

        ~LRUCache() {
        while (head != nullptr) {
            ptr_bf = head->next;
            delete head;
            head = ptr_bf;
        }
}
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
