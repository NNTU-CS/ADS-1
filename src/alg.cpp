// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int right=0, left=size-1, sum=0;//левая и правая границы массива
  while (right<left) {// пока не сошлись границы массива
    int middle=(right+left)/2;// индекс среднего элемента
// сужаем массив
    if (arr[middle]<value)
      right=middle+1;
    else
      left=middle;
  }
//подсчёт количества искомого числа
  if (arr[right]==value) {
    while(arr[right]==value) {
      sum++;
      right++;
    }
  }
  if (sum!=0)
    return sum;
  else return 0; // если ничего не найдено
}
