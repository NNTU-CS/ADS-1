// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int first = 0, last = size - 1, count = 0, mid = (first + last) / 2;
    while ((last != first+1)) {
        if (value < arr[mid]) {
            last = mid;
            mid = (first + last) / 2;
        } else {
            first = mid;
            mid = (first + last) / 2;
        }
    }
    if (arr[mid] == value) {
        count++;
        int i = mid-1;
        while ((i > -1) && (arr[i] == value)) {
            count++;
            i--;
        }
        i = mid + 1;
        while ((i < size) && (arr[i] == value)) {
            count++;
            i++;
        }
    }
    return count;
}
