// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int left, right, mid, kolvo;
    left = 0;
    right = size - 1;
    kolvo = 0;
    while (left < right) {
        mid = (left+right) / 2;
        if (*(arr+mid) < value)
            left = mid + 1;
        else
            right = mid;
    }
    if (*(arr + left) == value) {
        while (*(arr+left) == value) {
            kolvo++;
            left++;
        }
    }
        return kolvo;
}
