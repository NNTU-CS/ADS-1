// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int left, right, mid, kol;
kol = 0;
left = 0;
right = size - 1;
while (left < right) {
mid = (left + right) / 2;
if (*(arr + mid) < value)
left = mid + 1;
else
right = mid;
}
if (*(arr + left) == value) {
while (*(arr + left) == value) {
kol++;
left++;
}
}
return kol;
  return 0; // если ничего не найдено
}
