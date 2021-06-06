// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
    int count = 0, min = 0, max = size - 1, ave = 0;
    while (min <= max) {
        ave = (min + max) / 2;
        if (arr[ave] == value) {
            count++;
            break;
        }
        value < arr[ave] ? max = ave - 1 : min = ave + 1;
    }
    int l = 1;
    bool boo1 = true, boo2 = true;
    if (count) {
        while (boo1 || boo2) {
            if (ave + l < size) {
                arr[ave + l] == value ? count++ : boo1 = false;
            }
            if (ave - l >= 0) {
                arr[ave - l] == value ? count++ : boo2 = false;
            }
            if (ave + l >= size && ave - l < 0) break;
            l++;
        }
    }
    return count;
}
