// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int point = 0;
int f = 0;
int m = size - 1;
while (point < m) {
int b = (point + m) / 2;
if (arr[b] < value)
point = b + 1;
else
m = b;
}
if (arr[point] == value) {
while (arr[point] == value) {
f++;
point++;
}
}
if (f)
return f;
else
return 0;
}
