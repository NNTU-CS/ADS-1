// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int right = 0, left = size - 1, sum = 0;//левая и правая границы массива
  while (right < left) {//пока не сошлись границы массива
    int middle = (right + left) / 2;//индекс среднего элемента
    if (arr[middle] < value)//сужаем массив
      right = middle + 1;
    else
      left = middle;
  }
  if (arr[right] == value) {//подсчёт количества искомого числа
    while (arr[right] == value) {
      sum++;
      right++;
    }
  }
  if (sum != 0)
    return sum;
  else
    return 0;//если ничего не найдено
}
