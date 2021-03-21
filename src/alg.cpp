// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
int prav = 0;
int lev = size - 1;
int count = 0;
while (prav < lev) {
int seredina = (prav + lev) / 2;
if (arr[seredina] < value)
prav = seredina + 1;
else
lev = seredina;
}
if (arr[prav] == value) {
while (arr[prav] == value) {
count++;
prav++;
}
}
if (count)
return count;
else
return 0; // если ничего не найдено
}
