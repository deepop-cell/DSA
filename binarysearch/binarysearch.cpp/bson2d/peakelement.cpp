#include<iostream>

void peak(int matrix[][1000000], int r, int c) {
    int low = 0;
    int high = c - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int cmax = matrix[0][mid];
        int maxidx = 0;

        for (int i = 1; i < r; i++) {
            if (matrix[i][mid] > cmax) {
                maxidx = i;
                cmax = matrix[i][mid];
            }
        }

        int left = (mid > 0) ? matrix[maxidx][mid - 1] : -1;
        int right = (mid < c - 1) ? matrix[maxidx][mid + 1] : -1;

        if (cmax > left && cmax > right) {
            std::cout << "[" << maxidx << "," << mid << "]";
            return;
        }
        else if (right > cmax) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}