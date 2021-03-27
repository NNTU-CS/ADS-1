// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
int mid = 0;
int i = 0;
int j = size - 1;
while (true) {
mid = (i + j) / 2;
if (value < arr[mid])
j = mid - 1;
else if (value > arr[mid])
i = mid + 1;
else
break;
if (i > j) return 0;
}
int cnt1 = 0, cnt2 = 0;
while (arr[mid + cnt1] == value) {
++cnt2;
++cnt1;
}
cnt1 = 1;
while (arr[mid - cnt1] == value) {
++cnt2;
++cnt1;
}
if(cnt2 == 0)
return 0;
else
return cnt2;
}
