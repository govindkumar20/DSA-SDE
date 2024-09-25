class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    set<int> s;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            q.push(i);
            s.insert(i);
        }
        
    }
    
    int popSmallest() {
        int temp=q.top();
        q.pop();
        s.erase(temp);
        return temp;

    }
    
    void addBack(int num) {
        if(s.find(num)==s.end()){
            q.push(num);
            s.insert(num);
        }
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */