#include <vector>

void counting_sort(std::vector<int>& arr, int max_value) {
    std::vector<int> count(max_value + 1, 0);
    std::vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); ++i) {
        ++count[arr[i]];
    }

    for (int i = 1; i <= max_value; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}
