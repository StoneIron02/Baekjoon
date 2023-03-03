template<typename T, unsigned int N = 20> class array {
private:
    int capacity;
    int* arr;

public:
    array() : capacity(N) {
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++)
            arr[i] = 0;
    }

    ~array() {
        delete[] arr;
    }

    unsigned int size() {
        return capacity;
    }

    unsigned int max_size() {
        return capacity;
    }

    bool empty() {
        return false;
    }

    T operator[](unsigned int index) {
        return arr[index];
    }

    T at(unsigned int index) {
        return arr[index];
    }

    T front() {
        return arr[0];
    }

    T end() {
        return arr[capacity - 1];
    }

    void insert(unsigned int index, T value) {
        for (unsigned int i = capacity - 2; i >= index; i--)
            arr[i + 1] = arr[i];
        arr[index] = value;
    }

    void erase(unsigned int index) {
        for (unsigned int i = index + 1; i <= capacity - 1; i++)
            arr[i - 1] = arr[i];
        arr[capacity - 1] = 0;
    }

    void set(unsigned int index, T value) {
        arr[index] = value;
    }

    void fill(T value) {
        for (int i = 0; i < capacity; i++)
            arr[i] = value;
    }

    void swap(unsigned int index1, unsigned int index2) {
        T temp = arr[index2];
        arr[index2] = arr[index1];
        arr[index1] = temp;
    }
};