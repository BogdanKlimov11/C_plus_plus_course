#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int>& arr) {
    int n = arr.size();
    // Проходим по всем элементам массива
    for (int i = 0; i < n; ++i) {
        // Установим флаг, который будет служить индикатором, были ли какие-либо обмены в этой итерации
        bool swapped = false;
        // Проходим по массиву сравнивая каждую пару соседних элементов
        // и меняем их местами, если они находятся в неправильном порядке
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        // Если в этой итерации не было ни одного обмена, то массив уже отсортирован
        if (!swapped) {
            break;
        }
    }
    return arr;
}
