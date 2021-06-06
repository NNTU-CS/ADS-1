// Copyright 2021 NNTU-CS
// Данилов Евгений
// 20-ИСТ-3

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  
  int d = 0;
  int a = 0;
  int b = size - 1;
  
  while (a < b) 
  {
  int c = (a + b) / 2;
  if (arr[c] < value)
  a = c + 1;
  else
  b = c;
  }
  
  if (arr[a] == value) 
  {
    while (arr[a] == value) 
    {
    d++;
    a++;
    }
  }
  
  if (d)
    return d;
  else
    return 0;
}
