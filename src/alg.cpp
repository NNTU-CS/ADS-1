// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int z = 0;
    int a = 0;
    int b = size - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (arr[k] == value) {
            for (int i = 0; i < size; i++) {
                if (arr[i] == value) {
                    z++;
                }
            }
            break;
        }
        if (arr[k] < value)
            a = k + 1;
        else
            b = k - 1;
    }
    return z;
}
