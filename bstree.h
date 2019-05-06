#ifndef BSTREE_H
#define BSTREE_H
#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;
        unsigned int nodes = 0;

    public:
        BSTree() : root(nullptr) {};
        bool find(T data) {
            Node<T>* current = this->root;
            while(current != nullptr){
                if (data == current->data) {
                    return true;
                } else {
                    if (data > current->data) {
                        current = current->right;
                    } else {
                        current = current->left;
                    }
                }
            }
            return false;
        } 

        bool insert(T data) {
            if(!find(data)) {
                Node<T> *newNode = new Node<T>(data);
                Node<T> *current = this->root;

                if (!root) {
                    root = newNode;
                    return true;
                }

                while (current != nullptr) {
                    if (data > current->data) {
                        if (current->right != nullptr) {
                            current = current->right;
                        } else {
                            current->right = newNode;
                            this->nodes++;
                            return true;
                        }
                    } else {
                        if (data < current->data) {
                            if (current->left != nullptr) {
                                current = current->left;
                            } else {
                                current->left = newNode;
                                this->nodes++;
                                return true;
                            }
                        }
                    }
                }
            }

            return false;
        }

        bool remove(T data) {
            T temp;
            if(!root){
                throw out_of_range("No elements to remove")
            }
            Node<T>* current = this->root;
            while(current->data != data) {
                if (data == current->data) {
                    return true;
                } else {
                    if (data > current->data) {
                        current = current->right;
                    } else {
                        current = current->left;
                    }
                }
            }
            if(!current->right && !current->left){
                delete current;
            }
            else if(current->right && !current->left){
                while(current->right != nullptr) {
                    temp = current->data;
                    current->data = current->right->data;
                    current->right->data = temp;
                    current = current->right;
                }
                delete current;
            }
            else if(!current->right && current->left){
                while(current->left != nullptr) {
                    temp = current->data;
                    current->data = current->left->data;
                    current->left->data = temp;
                    current = current->left;
                }
                delete current;
            }
            else if(current->right && current->left){
                while(current->right != nullptr && current->left != nullptr) {
                    temp = current->data;
                    current->data = current->right->data;
                    current->right->data = temp;
                    current = current->right;
                }
                if(){

                }
            }
            return true;
        }

        unsigned int size() {
            return nodes;
        }

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            return Iterator<T>(root);
        }

        Iterator<T> end() {
            return Iterator<T>(root);
        }

        ~BSTree() {
            // TODO
        }
};

#endif
