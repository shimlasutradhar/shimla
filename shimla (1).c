#include <stdio.h>

int main() {
    int arr[100], n, i, choice, number, pos, newValue, value, found;

    printf("Enter number of array: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nArray Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Update\n");
        printf("4. Delete by value\n");
        printf("5. Sort\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number to insert at beginning: ");
                scanf("%d", &number);
                for(i = n; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = number;
                n++;
                break;

            case 2:
                printf("Enter number to insert: ");
                scanf("%d", &number);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                if(pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = number;
                n++;
                break;

            case 3:
                printf("Enter position to update (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter new value: ");
                scanf("%d", &newValue);
                arr[pos] = newValue;
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                found = 0;
                for(i = 0; i < n; i++) {
                    if(arr[i] == value) {
                        found = 1;
                        break;
                    }
                }
                if(found) {
                    for(int j = i; j < n - 1; j++) {
                        arr[j] = arr[j + 1];
                    }
                    n--;
                    printf("Value deleted.\n");
                } else {
                    printf("Value not found!\n");
                }
                break;

            case 5:
                for(i = 0; i < n - 1; i++) {
                    for(int j = 0; j < n - i - 1; j++) {
                        if(arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Array sorted.\n");
                break;

            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = 0;
                for(i = 0; i < n; i++) {
                    if(arr[i] == value) {
                        found = 1;
                        printf("Value found at position %d\n", i);
                        break;
                    }
                }
                if (!found) {
                    printf("Value not found.\n");
                }
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("Current array: ");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } while(choice != 7);

    return 0;
}
