class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key, int _val){
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node *temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }

    void deleteNode(Node* newNode){
        Node* prevNode = newNode->prev;
        Node* nextNode = newNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* toDelete = mp[key];
            mp.erase(key);
            deleteNode(toDelete);
        }
        if(mp.size()==cap){
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};
