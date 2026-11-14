class MyCircularQueue {
private:
    std::vector<int> slots;
    int capacity;
    int frontIndex;
    int count;

public:
    MyCircularQueue(int k)
        : slots(k), capacity(k), frontIndex(0), count(0) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        int writeIndex = (frontIndex + count) % capacity;
        slots[writeIndex] = value;
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return true;
    }

    int Front() const {
        if (isEmpty()) {
            return -1;
        }

        return slots[frontIndex];
    }

    int Rear() const {
        if (isEmpty()) {
            return -1;
        }

        int rearIndex = (frontIndex + count - 1) % capacity;
        return slots[rearIndex];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }
};