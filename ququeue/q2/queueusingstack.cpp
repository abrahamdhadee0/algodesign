class MyQueue {
public:
stack<int> s1;
stack<int> s2;
int count=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size()>0){
       int x=s1.top();
        s2.push(x);
        s1.pop();
        }
        int z=s2.top();
        s2.pop();
        while(s2.size()>0){
       int x=s2.top();
        s1.push(x);
        s2.pop();
        }
        return z;

    }
    
    int peek() {
        while(s1.size()>0){
       int x=s1.top();
        s2.push(x);
        s1.pop();
        }
        int z=s2.top();
         while(s2.size()>0){
       int x=s2.top();
        s1.push(x);
        s2.pop();
        }
        return z;
    }
    
    bool empty() {
     return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */