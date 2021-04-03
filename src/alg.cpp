// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int index = -1;
int number = 0;
int i = 0, j = size - 1;
while (i <= j) {
if (arr[i + (j - i + 1) / 2] == value) {
number++;
index = i + (j - i + 1) / 2;
break;
} else {
if (arr[i + (j - i + 1) / 2] < value)
i = i + (j - i + 1) / 2 + 1;
else
j = i + (j - i + 1) / 2 - 1;
}
}
if (index != -1) {
i = index - 1;
while ((i >= 0) && (arr[i] == arr[index])) {
number++;
i--;
}
j = index + 1;
while ((j < size) && (arr[j] == arr[index])) {
number++;
j++;
}
}
return number;
}
