// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Item {
        Item* next = nullptr;
        T value;
    };
    int count = 0;
    Item* top = new Item;
 public:
    void push(T var);
    T pop();
    int length() { return count; }
};

template<typename T>
void TPQueue<T>::push(T var) {
    if (count == 0) {
        top->value = var;
        count++;
    } else {
        count++;
        Item* curr = top;
        bool flag = false;
        while (curr->value.prior >= var.prior && curr->next != nullptr) {
            curr = curr->next;
            flag = true;
        }
        Item* a = new Item;
        a->value = var;
        if (flag) {
            if (curr->next == nullptr && curr->value.prior >= var.prior) {
                curr->next = a;
                return;
            } else {
                a->next = curr;
                Item* b = top;
                while (b->next != curr) b = b->next;
                b->next = a;
            }
        } else if (curr->value.prior >= var.prior && curr->next == nullptr) {
            curr->next = a;
        } else {
            a->next = top;
            top = a;
        }
    }
}
template<typename T>
T TPQueue<T>::pop() {
    count--;
    T var = top->value;
    top = top->next;
    return var;
}


#endif  // INCLUDE_TPQUEUE_H_
