// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int a = 0, c = size - 1, number = 0;
while (a < c) {
int b = (a + c) / 2;
if (arr[b] < value)
a = b + 1;
else
c = b;
}
if (arr[a] == value) {
while (arr[a] == value) {
number++;
a++;
}
}
if (number)
return number;
else
return 0; // если ничего не найдено
}
