#include <iostream>
#include <algorithm>

using namespace std;

void chooseSort(int *a, int size);

void bubbleSort(int *a, int size);

void insertSort(int *a, int size);

void insertSortBinary(int *a, int size);

void quickSort(int *a, int size);

void printArr(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {1, -5, 7, -2, 0, 11, 6, 8, -3, -4};
//    chooseSort(arr, 10);
//    bubbleSort(arr, 10);
//    insertSort(arr, 10);
//    insertSortBinary(arr, 10);
//    quickSort(arr, 10);
    sort(arr, arr+10);
    printArr(arr, 10);
    return 0;
}

void qsort(int *a, int left, int right) {
    int mid = (left+right)/2;
    int i = left;
    int j = right;
    while (i<=j){
        while (a[i]<a[mid]) i++;
        while (a[j]>a[mid]) j--;
        int t = a[i]; a[i] = a[j]; a[j] = t;
        i++; j--;
    }
    if (left < j) qsort(a, left, j);
    if (right > i) qsort(a, i, right);
}

void quickSort(int *a, int size) {
    qsort(a, 0, size-1);
}

void insertSortBinary(int *a, int size) {
    for (int i=1; i<size; i++) {
        if (a[i-1] > a[i]) {
            int left = 0;
            int right = i-1;
            int t = a[i];
            while (left<=right) {
                int mid = (left+right)/2;
                if (a[mid]<t) left = mid +1;
                else right = mid-1;
            }
            for (int j=i-1; j>=left; j--) {
                a[j+1] = a[j];
            }
            a[left] = t;
        }
    }
}

void insertSort(int *a, int size) {
    for (int i=1; i<size; i++) {
        int t = a[i];
        int j=i-1;
        while (j>=0 && a[j]>t) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
}

void bubbleSort(int *a, int size) {
    for (int i=size-1; i>0; i--) {
        bool obmen = false;
        for (int j=0; j<i; j++) {
            if (a[j]>a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                obmen = true;
            }
        }
        if (!obmen) break;
    }
}


//TODO chooseSort implementation here
void chooseSort(int *a, int size) {
    for (int i=0; i<size-1; i++) {
        int nMin = i;
        for (int j=i+1; j<size; j++) {
            if (a[j]<a[nMin]) nMin=j;
        }
        if (nMin!=i) {
            int t = a[i]; a[i]=a[nMin]; a[nMin] = t;
        }
    }
}