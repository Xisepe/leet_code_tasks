#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double avg = 0;
    char isTwo = 0;
    short divSum = (nums1Size+nums2Size)/2;
    if (divSum == (nums1Size+nums2Size + 1)/2) {
        isTwo = 1;
    }
    for (short  i = 0, j = 0; i + j <= divSum ;) {
        int t1 = INT_MAX;
        int t2 = INT_MAX;
        if (i < nums1Size) {
            t1 = nums1[i];
        }
        if (j < nums2Size) {
            t2 = nums2[j];
        }
        if (t1 < t2) {
            i++;
        } else {
            j++;
            t1 = t2;
        }
        if (isTwo) {
            if (i + j - 1 == divSum - 1) {
                avg += t1;
            }
        }
        if (i + j - 1 == divSum) {
            avg += t1;
        }
    }
    if (isTwo) {
        avg /= 2;
    }
    return avg;
}

int main(void) {

    return 0;
}