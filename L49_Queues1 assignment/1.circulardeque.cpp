#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
public:
    int f, b, s, c;
    vector<int> arr;

    MyCircularDeque(int k) {
        f = b = s = 0;
        c = k;
        arr = vector<int>(k);
    }
    
    bool insertFront(int value) {
        if (s == c) return false;
        if (s == 0) b = (b + 1) % c;
        arr[f] = value;
        f = (f - 1 + c) % c;
        s++;
        return true;
    }
    
    bool insertLast(int value) {
        if (s == c) return false;
        if (s == 0) f = (f - 1 + c) % c;
        arr[b] = value;
        b = (b + 1) % c;
        s++;
        return true;
    }
    
    bool deleteFront() {
        if (s == 0) return false;
        f = (f + 1) % c;
        s--;
        if (s == 0) b = (b - 1 + c) % c;
        return true;
    }
    
    bool deleteLast() {
        if (s == 0) return false;
        b = (b - 1 + c) % c;
        s--;
        if (s == 0) f = (f + 1) % c;
        return true;
    }
    
    int getFront() {
        if (s == 0) return -1;
        return arr[(f + 1) % c];
    }
    
    int getRear() {
        if (s == 0) return -1;
        return arr[(b - 1 + c) % c];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        return s == c;
    }
};

int main() {
    MyCircularDeque* obj = new MyCircularDeque(3);
    cout << obj->insertLast(1) << endl;
    cout << obj->insertLast(2) << endl;
    cout << obj->insertFront(3) << endl;
    cout << obj->insertFront(4) << endl;
    cout << obj->getRear() << endl;
    cout << obj->isFull() << endl;
    cout << obj->deleteLast() << endl;
    cout << obj->insertFront(4) << endl;
    cout << obj->getFront() << endl;
    delete obj;
    return 0;
}
