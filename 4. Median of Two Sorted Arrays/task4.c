#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    short index = 0;
    double avg = 0;
    for (short first = 0, second = 0; index < (nums1Size + nums2Size) / 2;) {
        if (nums1[first] < nums2[second]) {
            index++;
            first++;
        }
    }

}

int main(void) {

    return 0;
}