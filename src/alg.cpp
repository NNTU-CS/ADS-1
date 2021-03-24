// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int l = 0;
int r = size - 1;
int e = 0;
int e1 = 0;
int m = 0;
int mid;
while ((l <= r) && (e != value)) {
mid = (l + r) / 2;
if (arr[mid] == value) e = mid;
if (arr[mid] > value) r = mid - 1;
else {
l = mid + 1;
}
}
e1 = e;
while (arr[e1] == value) {
++m;
++e1;
}
e1 = e-1;
while (arr[e1] == value) {
++m;
--e1;
}
cout << m;
return 0;
}
