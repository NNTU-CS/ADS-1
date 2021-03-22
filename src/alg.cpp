// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
        int num = 0, left = 0, right = size - 1, mid;
        while (left < right) {
                mid = left + (right - left) / 2;
                if (arr[mid] == value) {
                        while (arr[mid-1] == value) mid--;
                        while (arr[mid] == value) mid++, num++;
                        return num;
                } else if (arr[mid] > value) {
                        right = mid;
                } else {
                        left = mid+1;
                }
        }
        return 0; // если ничего не найдено
}
