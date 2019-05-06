#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
    private:
        T data;
        Node<T> *left;
        Node<T> *right;
public:
    Node<T>(T data) : left(nullptr), right(nullptr), data(data){};

    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 
};

#endif