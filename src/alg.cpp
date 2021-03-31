// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int count = 0, left = 0, right = size, m, index;
while (left <= right) {
m = left + ((right - left) / 2);
if (value < arr[m]) {
right = m - 1;
} else if (value > arr[m]) {
left = m + 1;
} else if (value == arr[m]) {
index = m;
break;
} else {
return 0;
}
}
if (index >= 0) {
for (int i = index; i >= 0; i--) {
if (arr[i] == value) {
count++;
}
}
}
if (index < size) {
for (int i = index + 1; i < size; i++) {
if (arr[i] == value) {
count++;
}
}
}
return count;
}
