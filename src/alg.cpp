// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
        int r = size;
        int m = 0;
        int result = 0;
        int l = 0;
        while (true) {
        m = (r + l) / 2;
        if (value < arr[m]) {
        r = m - 1;
        } else if (value > arr[m]) {
             l = m + 1;
        } else {
              while (arr[m] == value) {
              m--;
           }
           m++;
           while (arr[m] == value) {
              result++;
              m++;
           }
           break;
        }
        if (l > r) {
        break;
        }
     }
     return result;
}
