// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int right, left = 0, sum = 0, midlef;
    right = size - 1;
    while (left < right) {
        midlef = (left + (right - left)) / 2;
        midlef = (right - left) / 2 + left;
        if (arr[midlef] == value) {
            while (arr[midlef - 1] == value) {
                sum++;
                midlef--;
            }
            midlef += sum;
            while (arr[midlef] == value) {
                midlef++;
                sum++;
            }
            return sum;
        }
        if (arr[midlef] > value) {
            right = midl;
        } else {
            left = midlef + 1;
        }
    }
    return 0; // если ничего не найдено
}

