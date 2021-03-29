// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int i = 0, j = size - 1, c = 0;
while (i < j) {
int m = (i + j) / 2;
if (arr[m] < value)
i = m + 1;
else
j = m;
}

if (arr[i] == value) {
while (arr[j] == value) {
c++;
i++;
}
}

if (c)
return c;
else
return 0; // если ничего не найдено
}
