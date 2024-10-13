#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
        int n;

    public:

        ListLinked(){                           //CONSTRUCTOR

            first = nullptr;
            n = 0;
        }

        ~ListLinked(){                          //DESTRUCTOR (LIBERA ESPACIO DE LA LISTA)
            while(first != nullptr){
                Node<T> aux = first;
                first = first -> next;
                delete aux;
            }
        }

        T operator[](int pos){                  //DEVUELVE EL VALOR QUE HAYA EN LA POSICION "pos"
            if(pos > n-1 || pos < 0){
                throw std::out_of_range ("Posición fuera de el alcance [0, size()-1]")
            }
            
            Node<T> current = first;
            for(int i = 0; i < pos){
                current = current -> next;
            }

            return current -> data;
        }


        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){      //IMPRIME LA CADENA DE LIST
            Node<T> current = list.first;

            cout << "[";
            if (current != nullptr){
                cout << current -> data;

                current = current -> next;
            }

            while (current != nullptr){
                cout << "," << current -> data;
                current = current -> next;
            }

            cout << "]";
            
            return out;
        }

        void insert(int pos, T e) override{     //INSERTA EL VALOR "e" EN LA POSICIÓN "pos"
            if(n == max){
                resize(max*2);
            }

            for(int i = max; i < pos; i--){
                arr [i] = arr[i - 1];
            }
            arr[pos] = e;
            n++;
        }

        void append(T e) override{              //INSERTA EL VALOR "e" AL FINAL DE LA LISTA
            if(n == max){
                resize(max+1);
            }

            arr[n] = e;     //No cuenta el cero y por eso no es n + 1
            n++;
            
        }

        void prepend(T e) override{             //INSERTA EL VALOR "e" AL PRINCICPIO DE LA LISTA
            if(n == max){
                resize(max+1);
            }

            for(int i = max; i = 0; i--){       //Desplaza elementos a la derecha
                arr[i + 1]= arr[i]
            }

            arr[0] = e;
        }
        
    void remove(int pos) override {             // ELIMINA LA POSICIÓN "pos"
        if (pos < 0 || pos >= n) {
            std::cerr << "Índice fuera de rango\n";
        }
        for (int i = pos; i < n - 1; i++) {                 //Desplaza elementos a la izquierda
            arr[i] = arr[i + 1]; 
        }

        n--;
        resize(n);
    }   

        T get(int pos) override{                //DEVUELVE EL VALOR DE LA POSICIÓN "pos"
            if (pos = 0 || pos >= max){
                throw std::out_of_range("Posición fuera del intervalo [0, size()-1]");
            }
            int valor = T[pos];
            return valor;
        }

        int search(T e) override{           //DEVUELVE LA POSICION DEL VECTOR DONDE SE ENCUENTRA EL VALOR "e"
            for(int i = 0; i < n; i++){
                if(T[i] = e){
                    return i;
                }else
                    i++;
            }
            return -1;
        }

        bool empty() override{              //DEVUELVE SI EL VECTOR ESTA VACIO O LLENO
            if(n == 0){
                return true;
            }else
                return false;
        }

        int size() override{                //DEVUELVE EL TAMAÑO DEL VECTOR
            return n;
        }
};