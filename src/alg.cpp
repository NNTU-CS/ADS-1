// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
        int l = 0, r = size - 1;
        int count = 0;
        while (l < r) {
                int midd = (l + r) / 2;
                if (arr[midd] < value)
                        l = midd + 1;
                else
                        r = midd;
                if (arr[l] == value) {
                        while (arr[l] == value) {
                                count++;
                                l++;
                        }
                }
        }
        if (count != 0)
                return count;
        else
                return 0; // если ничего не найдено
}
