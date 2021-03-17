// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int left = 0, right = size-1, count = 0, mid;

    while (left < right) {
       mid = (left + right) / 2;

    if (value > arr[mid])
        left = mid + 1;
    else
        right = mid;
    }

    while (arr[left] == value) {
        count++;
        left++;
    }

    if (count)
        return count;
    else
        return 0;
}
