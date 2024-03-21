#include <vector>

int find_max(std::vector<int>& arr) {
    int max_val = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

void counting_sort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; ++i) {
        ++count[(arr[i] / exp) % 10];
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radix_sort(std::vector<int>& arr) {
    int max_val = find_max(arr);

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort(arr, exp);
    }
}
