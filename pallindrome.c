#include <stdio.h>
#include <string.h>
#include <ctype.h>

void preprocessString(char *input, char *processed, int max_size) {
    int j = 0;
    int i;
    for (i = 0; input[i] != '\0' && j < max_size - 1; i++) {
        if (isalnum(input[i])) {
            processed[j++] = tolower(input[i]);
        }
    }
    processed[j] = '\0'; 
}

int isPalindrome(char *str) {
    int left = 0, right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; 
        }
        left++;
        right--;
    }
    return 1; 
}

int main() {
    char input[100], processed[100];
    printf("Enter a word or phrase: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    preprocessString(input, processed, sizeof(processed));
    if (isPalindrome(processed)) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is not a palindrome.\n");
    }

    return 0;
}

