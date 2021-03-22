// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int start = 0;
    int end = size - 1;
    int count = 0;

    while (start < end) {
        int k = (start + end) / 2;
        if (arr[k] < value) {
            start = k+1;
        } else {
            end = k;
        }
    }

    if (arr[start] == value) {
        while (arr[start] == value) {
            count++;
            start++;
        }
    }

    return count;
}
