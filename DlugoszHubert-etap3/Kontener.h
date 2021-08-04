#ifndef KONTENER_H_
#define KONTENER_H_

template<typename T>
class Kontener {
    T* arr;
    int pos;
    int size;

public:
    Kontener(int p_size = 0) {
            arr = new T[p_size]{};
            pos = 0;
            size = p_size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            std::cout << "Proba wyjscia poza zakres kontenera. \n";
            exit(0);
            }
        else {
            return arr[index];
        }   
    }

    void push_back(T a) {
        if (pos < size) {
            arr[pos] = a;
        }
        else {
            T* tmp = new T[size + 1];
            for (int i = 0; i < size; i++) {
                tmp[i] = arr[i];
            }
            tmp[size] = a;
            delete[] arr;
            arr = tmp;
            size++;
        }
        pos++;
    }

    int get_size() {
        return size;
    };
};

#endif