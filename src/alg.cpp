// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int left = 0, right = size - 1, c = 0;
    while (left < right) {
        int m = (left + right) / 2;
        if (arr[m] < value)
            left = m + 1;
        else
            right = m;
    }

    if (arr[left] == value) {
        while (arr[left] == value) {
            c++;
            left++;
        }
    }

    if (c)
        return c;
    else
        return 0;
}
