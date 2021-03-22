// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int score = 0, left = 0, right = size - 1, center;
    while (left < right) {
        center = (left + right) / 2;
        if (arr[center] < value)
            left = center + 1;
        else
            right = center;
    }
        while (arr[left] == value) {
            score++;
            left++;
        }
  if (score != 0)
      return score;
  else
      return 0;
}
