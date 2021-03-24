// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int r = size;
    int l = 0;
    int a = 0;
    if (arr[r] < value) return 0;
    while ((r - l) > 0) {
        if (arr[r - 1] == value && r == size) {
            while (arr[r - 1 - l] == value) {
                l += 1;
            }
            cout << (l);
            return (l);
        }
        else if (arr[(r - l) / 2] < value) {
            l = (r - l) / 2;
        }
        else if (arr[(r - l) / 2] == value) {
            a = (r - l) / 2;
            r = 0;
            l = 0;
            while (arr[a + r] == value) {
                r += 1;
            }
            while (arr[a - l] == value) {
                l += 1;
            }
            cout << (r + l - 1);
            return (r + l - 1);
        }
        else if (arr[(r - l) / 2] > value) {
            r = (r - l) / 2;
        }
    }
    return 0;
}
