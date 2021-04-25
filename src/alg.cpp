// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int a = 0, b = size - 1, k = 0;
while (a < b) {
int mid = (a + b) / 2;
if (arr[mid] < value) a = mid + 1;
else b = mid;
}
if (arr[a] == value) {
while (arr[a] == value) {
k++;
a++;
}
}
if (k != 0)
return k;
else
return 0;
}
