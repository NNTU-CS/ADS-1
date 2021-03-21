// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int count = 0, min = 0, max = size - 1, mid = 0;
    while (min <= max) {
        mid = (min + max) / 2;
        if (arr[mid] == value) {
            count++;
            break;
        }
        value < arr[mid] ? max = mid - 1 : min = mid + 1;
    }
    int l = 1;
    bool bo1 = true, bo2 = true;
    if (count) {
        while (bo1 || bo2) {
            if (mid + l < size) {
                arr[mid + l] == value ? count++ : bo1 = false;
            }
            if (mid - l >= 0) {
                arr[mid - l] == value ? count++ : bo2 = false;
            }
            if (mid + l >= size && mid - l < 0) break;
            l++;
        }
    }
    return count;
}
