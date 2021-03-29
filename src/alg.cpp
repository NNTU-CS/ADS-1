// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int m = 0,
    int r = size - 1;
    int c = 0;
    while (m < r) {
        int mid = (m + r) / 2;
        if (arr[mid] < value)
        m = mid + 1;
        else
        r = mid;
        if (arr[m] == value) {
            while (arr[m] == value) {
            c++;
            m++;
            }
        }
    }
    if (c > 0)
        return c;
    else
  return 0; // если ничего не найдено
}
