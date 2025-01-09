#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int ascending) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int)); 
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    printf("Enter %d integers:\n", n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int choice;
    printf("\nChoose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    int ascending = (choice == 1);
    bubbleSort(arr, n, ascending);

    printf("\nSorted array in %s order:\n", ascending ? "ascending" : "descending");
       // int i;
	    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); 

    return 0;
}

