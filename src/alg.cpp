// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int i = 0;
    int j = size - 1;
    int q = 0;
    while (i < j) {
        int mid = i + (j - i) / 2;
        if (arr[mid] >= value)
            j = mid;
        else
            i = mid + 1;
        if (arr[i] == value) {
            while (arr[i] == value) {
               q++;
               i++;
            }
        }
    }
    if (q > 0)
        return q;
    else
        return 0;
}
