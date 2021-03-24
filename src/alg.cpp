// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int cnt = 0;
int left = 0, right = size, mid, BS;
while (left <= right) {
mid = left + (right - left) / 2;
if (value < arr[mid]) {
right = mid - 1;
} else if (value > arr[mid]) {
left = mid + 1;
} else {
BS = mid;
}
}
for (int i = BS; i >= 0; i--) {
if (arr[i] == value) {
cnt++;
}
}
for (int i = BS + 1; i < size; i++) {
if (arr[i] == value) {
cnt++;
}
}
if (BS == -1) {
return 0;
} else {
return cnt;
}
}
