
 class LRUCache {
    public:
    class node{
        public:
        int key;
        int val;
        node*next;
        node*prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node* n){
        node* temp=head->next;
        n->next=temp;
        n->prev=head;
        head->next=n;
        temp->prev=n;
    }
    void deletenode(node *n){
        node * deleteprev=n->prev;
        node *deletenext=n->next;
        deleteprev->next=deletenext;
        deletenext->prev=deleteprev;
    }
    int get(int key) {
         if(m.find(key)!=m.end()){
             node* rec=m[key];
             int ans=rec->val;
             m.erase(key);
             deletenode(rec);
             addnode(rec);
             m[key]=head->next;
             return ans;
         }
         return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* a=m[key];
            m.erase(key);
            deletenode(a);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
        

    
};

