// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
  int rightelem = 0;
  int leftelem = size - 1;
  int summa = 0;
  while (rightelem < leftelem) {
    int midelem = (rightelem + leftelem) / 2;//находим середину массива
    if (arr[midelem] < value)//уменьшаем массив
      rightelem = midelem + 1;
    else
      leftelem = midelem;
  }
  if (arr[rightelem] == value) {
    while (arr[rightelem] == value) {
      summa++;
      rightelem++;
    }
  }
  if (summa != 0)
    return summa;
  else
    return 0;//если ничего не найдено
}
