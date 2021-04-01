// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int left = 0;
    int right = size - 1;
    int count = 0;
    int c = 1;
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] > value)
            right = mid;
        if (arr[mid] < value)
            left = mid + 1;
        if (arr[mid] == value) {
            count = 1;
            break;
        }
    }
    int n = 0;
    while (n == 0) {
        if (arr[mid + c] == value) {
            count++;
            c++;
        } else {
            n = 1;
        }
    }
    n = 0;
    c = 1;
    while (n == 0) {
        if (arr[mid - c] == value) {
            count++;
            c++;
        } else {
            n = 1;
        }
    }
    if (count == 0)
        return 0;
    else
        return count;
}
