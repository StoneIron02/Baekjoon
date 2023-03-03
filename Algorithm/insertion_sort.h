template<typename T>
void insertion_sort(T* arr, int size) {
    for (int j = 1; j < size; j++) {
        T key = arr[j];
        int i;
        for (i = j - 1; i >= 0; i--) {
            if (arr[i] <= key)
                break;
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = key;
    }
}