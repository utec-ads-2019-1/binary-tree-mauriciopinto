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
        BSTree() : root(nullptr), nodes(0) {};
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
                    nodes++;
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
            // En vez de excepción, deberías retornar false
            // Da error
            if(!root){
                throw out_of_range("No elements to remove");
            }
            if(find(data)) {
                Node<T> *temp1 = root;
                Node<T> *temp2 = root;
                while(temp2->data != data){
                        if (data > temp1->data) {
                            temp1 = temp1->right;
                        }
                        else {
                            temp1 = temp1->left;
                        }
                        if (data > temp1->data) {
                            temp2 = temp1->right;
                        }
                        else {
                            temp2 = temp1->left;
                        }
                    }
                if (temp2->right == nullptr && temp2->left == nullptr) {
                    delete temp2;
                    nodes--;
                    return true;
                }
                else if (temp2->right != nullptr && temp2->left == nullptr) {
                    if(temp2 == temp1->right){
                        temp1->right = temp2->right;
                        delete temp2;
                        nodes--;
                        return true;
                    }
                    else if(temp2 == temp1->left){
                        temp1->left = temp2->left;
                        delete temp2;
                        nodes--;
                        return true;
                    }
                }
                else if (temp2->right ==nullptr && temp2->left != nullptr) {
                    if (temp2 == temp1->right) {
                        temp1->right = temp2->right;
                        delete temp2;
                        nodes--;
                        return true;
                    } else if (temp2 == temp1->left) {
                        temp1->left = temp2->left;
                        delete temp2;
                        nodes--;
                        return true;
                    }
                }
                else if (temp2->right != nullptr && temp2->left != nullptr) {
                    T datatemp;
                    temp1 = temp2;
                    temp2 = temp2->right;
                    while(temp2->left != nullptr){
                        temp2 = temp2->left;
                    }
                    datatemp = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = datatemp;
                    remove(temp2->data);
                }
            }
            else{
                return false;
            }
            return false;
        }

        unsigned int size() {
            return nodes;
        }

        void traversePreOrder(Node<T>* node1) {
            while(node1 != nullptr){
            cout << node1->data << " ";
            traversePreOrder(node1->left);
            traversePreOrder(node1->right);
            }
            return;
        }

        void traverseInOrder() {
            Iterator<T> it = this->begin();
            while(it != this->end()){
                cout << it.operator*() << " ";
                it.operator++();
            }
        }

        void traversePostOrder(Node<T>* node1) {
            while(node1 != nullptr){
                traversePostOrder(node1->left);
                traversePostOrder(node1->right);
                cout << node1->data << " ";
            }
        }

        Iterator<T> begin() {
            // Esto debería hacerse desde el iterador, o al menos desde una función static
            Node<T>* current = root;
            while(current->left != nullptr){
                current = current->left;
            }
            return Iterator<T>(current);
        }

        Iterator<T> end() {
            // Esto debería hacerse desde el iterador, o al menos desde una función static
            Node<T>* current = root;
            while(current->right != nullptr){
                current = current->right;
            }
            current = current->right;
            return Iterator<T>(current);
        }

        ~BSTree() {
            // Falta destructor
            // TODO
        }
};

#endif
