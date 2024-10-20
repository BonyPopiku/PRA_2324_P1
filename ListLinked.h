#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
        int n;

    public:
        // Constructor
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        // Destructor (libera el espacio de la lista)
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first;
                first = first->next;
                delete aux;
            }
        }

        // Sobrecarga del operador []
        T operator[](int pos) {
            if (pos >= n || pos < 0) {
                throw std::out_of_range("Posición fuera del alcance [0, size()-1]");
            }

            Node<T>* current = first;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }

            return current->data;
        }

        // Sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;

            out << "[";
            if (current != nullptr) {
                out << current->data;
                current = current->next;
            }

            while (current != nullptr) {
                out << ", " << current->data;
                current = current->next;
            }

            out << "]";
            return out;
        }

        // Inserta el valor "e" en la posición "pos"
        void insert(int pos, T e) override {
            Node<T>* newNode = new Node<T>(e);
            if (pos == 0) {
                newNode->next = first;
                first = newNode;
            } else {
                Node<T>* aux = first;
                for (int i = 0; i < pos - 1; i++) {
                    aux = aux->next;
                }
                newNode->next = aux->next;
                aux->next = newNode;
            }
            n++;
        }

        // Inserta el valor "e" al final de la lista
        void append(T e) {
            Node<T>* newNode = new Node<T>(e);

            if (first == nullptr) {
                first = newNode;
            } else {
                Node<T>* aux = first;
                while (aux->next != nullptr) {
                    aux = aux->next;
                }
                aux->next = newNode;
            }

            n++;
        }

        // Inserta el valor "e" al principio de la lista
        void prepend(T e) override {
            Node<T>* newNode = new Node<T>(e);
            newNode->next = first;
            first = newNode;
            n++;
        }

        // Elimina la posición "pos"
        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Índice fuera de rango\n");
            }

            Node<T>* temp;
            if (pos == 0) {
                temp = first;
                first = first->next;
                delete temp;
            } else {
                Node<T>* aux = first;
                for (int i = 0; i < pos - 1; i++) {
                    aux = aux->next;
                }
                temp = aux->next;
                aux->next = temp->next;
                delete temp;
            }

            n--;
        }

        // Devuelve el valor de la posición "pos"
        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera del intervalo [0, size()-1]");
            }

            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }

            return aux->data;
        }

        // Devuelve la posición donde se encuentra el valor "e"
        int search(T e) override {
            Node<T>* aux = first;
            for (int i = 0; i < n; i++) {
                if (aux->data == e) {
                    return i;
                }
                aux = aux->next;
            }
            return -1;
        }

        // Devuelve si la lista está vacía
        bool empty() override {
            return n == 0;
        }

        // Devuelve el tamaño de la lista
        int size() override {
            return n;
        }
};
