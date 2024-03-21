#include <vector>

void sift_down(std::vector<int>& arr, int start, int end) {
    int root = start;
    while (root * 2 + 1 <= end) {
        int child = root * 2 + 1;
        int swapIdx = root;

        if (arr[swapIdx] < arr[child])
            swapIdx = child;
        if (child + 1 <= end && arr[swapIdx] < arr[child + 1])
            swapIdx = child + 1;
        if (swapIdx == root)
            return;
        else {
            std::swap(arr[root], arr[swapIdx]);
            root = swapIdx;
        }
    }
}

void smooth_sort(std::vector<int>& arr) {
    int n = arr.size();
    int p = 1, r = 1, q = 1, b = 1, c = 1;

    while (p < n) {
        if (r % 8 == 3) {
            sift_down(arr, 1, r);
            q *= 10;
            b = c = q;
            q *= 2;
        } else {
            if (r % 4 == 1) {
                if (r + 1 < n && arr[r - 1] < arr[r + 1]) {
                    ++r;
                }
                sift_down(arr, p, r);
                p -= c;
                c /= 10;
            } else {
                if (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                sift_down(arr, b, r);
                if (p != 1) {
                    p -= c;
                    c /= 10;
                }
            }
        }
        ++r;
    }

    while (r > 1) {
        --r;
        std::swap(arr[1], arr[r]);
        sift_down(arr, p, r - 1);
        if (p != 1) {
            p -= c;
            c /= 10;
        }
    }
}
