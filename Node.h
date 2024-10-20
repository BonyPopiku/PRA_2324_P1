#include <ostream>

#ifndef NODE_H
#define NODE_H

template <typename T> 
class Node {
    public:
        T data;
        Node<T>* next;

        //Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

        Node(T data, Node<T>* next=nullptr){
            this -> data = data;
            this -> next = next;
        }

        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
            Node<T> aux = &node;
            while (aux != nullptr){
            out << aux -> data;
            aux = aux -> next;
            }
            
            
            return aux;
        }
};
#endif