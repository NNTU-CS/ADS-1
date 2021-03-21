// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int low = 0, high = size - 1, left = -1, right = -1;
    int resLeft = -1, resRight = -1;
    while (low <= high) {
        left = (low + high) / 2;

        if (arr[left] == value && (left == 0 || arr[left - 1] != value)) {
            resLeft = left;
            break;
        } else if (value <= arr[left]) {
            high = left - 1;
        } else {
            low = left + 1;
        }
    }

    low = 0, high = size - 1;

    while (low <= high) {
        right = (low + high) / 2;

        if (arr[right] == value && (right == 0 || arr[right + 1] != value)) {
            resRight = right;
            break;
        } else if (value < arr[right]) {
            high = right - 1;
        } else {
            low = right + 1;
        }
    }
    if (resLeft == -1 || resRight == -1) {
        return 0;
    } else if (resLeft == resRight) {
        return 1;
    } else {
        return resRight - resLeft + 1;
    }
}
