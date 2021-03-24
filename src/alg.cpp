// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int R, L = 0, sum = 0, midl;
    R = size - 1;
    while (L < R) {
        midl = (R - L) / 2 + L;
        if (arr[midl] == value) {
            while (arr[midl - 1] == value) {
                sum++;
                midl--;
            }
            midl += sum;
            while (arr[midl] == value) {
                midl++;
                sum++;
            }
            return sum;
        }
        if (arr[midl] > value) {
            R = midl;
        } else {
            L = midl + 1;
        }
    }
    return 0;
}
