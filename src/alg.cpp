// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int i = 0, j = size - 1, countNum = 0;
    while (i < j) {
        int mid = (i + j) / 2;
        if (arr[mid] < value)
            i = mid+1;
        else
            j = mid;
    }

    if (arr[i] == value) {
        while (arr[i] == value) {
            countNum++;
            i++;
        }
    }

    if (countNum)
        return countNum;
    else
        return 0;
}
