#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

using namespace std;

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        stack<T>* remaining;
        stack<T>* traversed;
    public:
        Iterator() {
            // TODO
        }

        Iterator(Node<T> *node) {
            remaining = new stack<T>;
            traversed = new stack<T>;
            current = node;
            while(current->left){
                remaining->push(current);
                current = current->left;
            }
        }

        Iterator<T> operator=(Iterator<T> other) {          
            this = other;
            return other;
        }

        bool operator!=(Iterator<T> other) {
            return true;
        }

        Iterator<T> operator++() {
            traversed->push();
        }

        Iterator<T> operator--() {
            return Iterator<T>(this->current);
        }
        T operator*() {
            return current->data;
        }
};

#endif
