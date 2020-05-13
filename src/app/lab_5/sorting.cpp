#include <iostream>

/**
 * If the length of an array to be sorted is less than this
 * constant, insertion sort is used.
 */
int const INSERTION_SORT_THRESHOLD = 47;

template<typename T>
void quick_sort(T* array, int left, int right) {
    int wall = left;
    int current = right;
    T pivot = array[(left + right) / 2];
    do {
        while (array[wall] < pivot) {
            wall++;
        }
        while (array[current] > pivot) {
            current--;
        }
        if (wall <= current) {
            //swap
            if (wall < current) {
                T tmp = array[wall];
                array[wall] = array[current];
                array[current] = tmp;
            }
            wall++;
            current--;
        }
    } while (wall <= current);

    if (wall <= right) {
        quick_sort(array, wall, right);
    }
    if (current > left) {
        quick_sort(array, left, current);
    }
}

template<typename T>
void insertion_sort(T* array, int size) {
    for (int left = 0; left < size; left++) {
        T value = array[left];
        int i = left - 1;
        while (i >= 0) {
            if (value < array[i]) {
                array[i + 1] = array[i];
            } else {
                break;
            }
            i--;
        }
        array[i + 1] = value;
    }
}

template<typename T>
void sort(T* array, int size) {
    if (size < INSERTION_SORT_THRESHOLD) {
        insertion_sort(array, size);
    }
    quick_sort(array, 0,  size - 1);
}

template<typename T>
void print(T *array, int n) {
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << " ";
}

int main() { }