#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;

    public:
        ListArray(){                        //CONSTRUCTOR
            max = MINSIZE;
            arr = new T[MINSIZE];
            n = 0;
        }

        ~ListArray(){                       //DESTRUCTOR
            delete[] T arr;
        }

        T operator[](int pos){              //DEVUELVE EL VALOR QUE HAY EN EL ARRAY DADA SU POSICIÓN
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posición fuera del intervalo [0, size()-1]");
            }
            return T arr[pos];
        }

        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){       //IMPRIME EL VECTOR
            out << "[";
            for(int i = 0; i < list.n; i++){
                out << list.arr[i];
                if (i < list.n - 1){
                    out << ",";
                }
            }
            out << "]";

            return out;
        }

        void resize(int new_size){          //REDIMENSIONAR EL ARRAY
            T* newArr = new T[new_size];
            for (int i = 0; i < n; i++){
                newArr[i] = arr[i];
            }
            delete[] arr;

            arr = newArr;
            max = new_size;
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