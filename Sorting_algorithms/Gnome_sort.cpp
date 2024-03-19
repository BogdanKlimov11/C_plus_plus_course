void gnome_sort(int arr[], int n) {
    int pos = 0;

    while (pos < n) {
        if (pos == 0 || arr[pos] >= arr[pos - 1]) {
            ++pos;
        } else {
            std::swap(arr[pos], arr[pos - 1]);
            --pos;
        }
    }
}
