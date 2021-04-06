// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    //  поместить сюда реализацию алгоритма
    int l = 0;
    int r = size - 1;
    int mid;
    int count = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (arr[mid] == value) {
            for (int j = mid; arr[j] == value; j++) {
                if (arr[j] == value) {
                    count++;
                }
            }
            for (int i = mid-1; arr[i] == value; i--) {
                if (arr[i] == value) {
                    count++;
                }
            }
            break;
        } else if (arr[mid] > value) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return count;
}
