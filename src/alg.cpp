// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
        int middle, n = 0, left = 0, right = size - 1;
        while (left < right) {
                middle = left + (right - left) / 2;
                if (arr[middle] == value) {
                        while (arr[middle-1] == value) middle--;
                        while (arr[middle] == value) middle++, n++;
                        return n;
                } else if (arr[middle] > value) {
                        right = middle;
                } else {
                        left = middle+1;
                }
        }
        return 0; // если ничего не найдено
}
