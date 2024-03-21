#include <algorithm>
#include <cmath>

template<typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<typename T>
int median_of_three(T arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        std::swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        std::swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        std::swap(arr[mid], arr[high]);
    return mid;
}

template<typename T>
void quick_sort(T arr[], int low, int high, int depth_limit) {
    while (low < high) {
        if (depth_limit == 0) {
            std::partial_sort(arr + low, arr + high + 1, arr + high + 1);
            return;
        }
        --depth_limit;
        int pivot_index = median_of_three(arr, low, high);
        std::swap(arr[pivot_index], arr[high]);
        int pivot = partition(arr, low, high);
        if (pivot - low < high - pivot) {
            quick_sort(arr, low, pivot - 1, depth_limit);
            low = pivot + 1;
        } else {
            quick_sort(arr, pivot + 1, high, depth_limit);
            high = pivot - 1;
        }
    }
}

template<typename T>
void intro_sort(T arr[], int n) {
    int depth_limit = 2 * static_cast<int>(log(n));
    quick_sort(arr, 0, n - 1, depth_limit);
}
