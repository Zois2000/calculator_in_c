#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = NULL;
    int count = 0;
    int capacity = 2;
    int number;
    char input;

    numbers = (int*)malloc(capacity * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter numbers. Press 'x' to save and exit.\n");

    while (1) {
        if (scanf("%d", &number) == 1) {  // Check if a number was entered
            if (count >= capacity) {
                capacity += 1;  // Increase memory if needed
                numbers = (int*)realloc(numbers, capacity * sizeof(int));
                if (numbers == NULL) {
                    printf("Memory expansion failed.\n");
                    return 1;
                }
            }
            numbers[count++] = number;
        } else {
            scanf("%c", &input);
            if (input == 'x') {
                break;
            } else {
                printf("Invalid input. Please enter a number or 'x'.\n");
                while (getchar() != '\n');  // Clear input buffer
            }
        }
    }

    printf("Entered numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);

    return 0;
}