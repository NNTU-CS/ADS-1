// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int i = 0, j = size - 1;
int index = -1;
int s = 0;
while (i < j) {
int center = i + (j - i) / 2;
if (arr[center] == value)
index = center;
if (arr[center] > value)
j = center - 1;
else
i = center + 1;
}
for (int i = 0; i < size; i++) {
if (arr[index] == arr[i])
s++;
}
return s;
}
