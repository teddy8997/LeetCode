class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[(head + size) % q.size()] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % q.size();
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()? -1 : q[head];
    }
    
    int Rear() {
        return isEmpty()? -1 : q[(head + size - 1) % q.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == q.size();
    }
private:
    vector<int> q;
    int head = 0;
    int size = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */