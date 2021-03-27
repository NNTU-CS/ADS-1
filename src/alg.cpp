// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int res = 0, mid = 0, left = 0, right = size;
    while (true) {
        mid = (right + left) / 2;
        if (value < arr[mid]) {
            right = mid - 1;
        } else if (value > arr[mid]) {
            left = mid + 1;
        } else {
            while (arr[mid] == value) {
                mid--;
            }
            mid++;
            while (arr[mid] == value) {
                res++;
                mid++;
            }
            break;
        }
        if (left > right) {
            break;
        }
    }
    return res;
}
