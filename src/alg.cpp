// Copyright 2021 NNTU-CS

int cbinsearch(int arr, int size, int value) {
int l = 0;
int r = size - 1;
int mid;
int midL;
int midR;
int eL;
int eR;
int m;
mid = (l + r) / 2;
while ((l <= mid) && (eL != value)) {
 midL = (l + mid) / 2;
 if (arr[midL] == value) eL = midL;
 if (arr[midL] > value) mid = midL - 1;
 else l = midL + 1;
}
mid = (l + r) / 2;
while ((mid <= r) && (eR != value)) {
 midR = (r + mid) / 2;
 if (arr[midR] == value) eR = midR;
 if (arr[midR] > value) mid = r - 1;
 else mid = midR + 1;
}
m = (midR - midL) + 1;
return m;
}
