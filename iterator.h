#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

using namespace std;

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        stack<Node<T>*> remaining;
        stack<Node<T>*> traversed;
    public:
        Iterator():current(nullptr){}

        Iterator(Node<T> *node) {
            current = node;
            while(current->left){
                remaining.push(current);
                current = current->left;
            }
        }

        Iterator<T>& operator=(Iterator<T> other) {
            current = other.current;
            return this;
        }

        bool operator!=(Iterator<T> other) {
            return current != other.current;
        }

        Iterator<T> operator++() {
            // Aquí la lógica está un poco mal al comienzo, va a dar violación de segmento
            traversed.push(remaining.top());
            remaining.pop();
            if (!current->right){
                current = remaining.top();
            }
            else{
                current = current->right;
                remaining.push(current);
                while(current->left != nullptr){
                    current = current->left;
                    remaining.push(current);
                }
            }
            return *this;
        }

        Iterator<T> operator--() {
            // No es tan simple, hay que tener un flag
            remaining.push(traversed.top());
            traversed.pop();
            current = remaining.top();
            return *this;
        }
        T operator*() {
            // Falta controlar el caso vacío
            return current->data;
        }
};

#endif
