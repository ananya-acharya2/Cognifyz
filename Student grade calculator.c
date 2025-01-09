#include <stdio.h>

int main() {
    int numSubjects;
    float grades[100], sum = 0, average;
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    if (numSubjects <= 0 || numSubjects > 100) {
        printf("Invalid number of subjects. Please enter a number between 1 and 100.\n");
        return 1;
    }
    printf("Enter the grades for %d subjects:\n", numSubjects);
    int i;
    for (i = 0; i < numSubjects; i++) {
        printf("Grade for subject %d: ", i + 1);
        scanf("%f", &grades[i]);

        
        if (grades[i] < 0 || grades[i] > 100) {
            printf("Invalid grade. Please enter a grade between 0 and 100.\n");
            return 1;
        }

        sum += grades[i];
    }
    average = sum / numSubjects;

    printf("\nThe average grade is: %.2f\n", average);

    return 0;
}
