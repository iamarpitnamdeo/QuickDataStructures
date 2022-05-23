package Sorting;
/*
Selection sort gives a time complexity of O(n2) in all cases regardless of arrangement of data
It could be useful in cases when swapping operation are very costly to do this would help as number of swaps in selection sort are :  size – 1
 Time Complexity - O(n Square)
 Space Complexity - O(n)
*/

class Main {
    public static void main(String[] args) {
        int arr[] = { 72, 50, 10, 44, 20 };
        selectionSort(arr);
        System.out.println("Sorted Array");
        printArray(arr);
    }

    static void selectionSort(int a[]) {
        int len = a.length;
        for (int i = 0; i < len - 1; i++) {
            int min = i;
            for (int j = i + 1; j < len; j++) {
                if (a[j] < a[min])
                    min = j;
            }
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }

    static void printArray(int a[]) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}