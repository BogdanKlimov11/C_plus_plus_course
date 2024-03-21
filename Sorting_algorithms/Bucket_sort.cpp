#include <vector>
#include <algorithm>

void bucket_sort(float arr[], int n) {
    std::vector<float> buckets[n];

    for (int i = 0; i < n; ++i) {
        int bucket_index = n * arr[i];
        buckets[bucket_index].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}
