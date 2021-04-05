// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int SIZE_ARR, int input) {
int left_border = 0;
int right_border = SIZE_ARR;
int mid = 0;
int desir_position = 0;
int buff = 0;

while (left_border < right_border) {
mid = (left_border + right_border) / 2;
if (arr[mid] > input) right_border = mid;
else if (arr[mid] < input) left_border = mid + 1;
else if (arr[mid] == input)
{ desir_position = mid;
break;}
else
  return 0;
}
  if (desir_position >= 0) {
for (int j = desir_position; arr[j] == input; j++) {
if (arr[j] == input)
buff++;}
for (int i = desir_position - 1; arr[i] == input; i--) {
if (arr[i] == input)
buff++; }
} else {
return buff;
}return buff;
}
