// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int count = 0;
int middle = size / 2;
if (!size) {
return 0;
}
if (arr[middle] == value) {
int count1 = 0, count2 = 0;
do {
++count1;
} while (arr[middle + count1] == value);
do {
++count2;
} while (arr[middle - count2] == value);
return count1 + count2 - 1;
} else {
if (arr[middle] > value) {
return cbinsearch(arr, middle, value);
} else {
return cbinsearch(arr + middle + 1, middle, value);
}
}
}
