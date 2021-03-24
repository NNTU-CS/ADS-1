// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int left = 0, right = size - 1, middle, count = 0;
    if (arr[left] <= value && value <= arr[right]) {
        while (left <= right) {
            middle = (left + right) / 2;
            if (arr[middle] == value) {
                count++;
                int buff = middle + 1;
                while (buff < size && arr[buff] == value) {
                    count++;
                    buff++;
                }
                buff = middle - 1;
                while (buff >= 0 && arr[buff] == value) {
                    count++;
                    buff--;
                }
                break;
            } else if (value < arr[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
    }
    return count;
}
