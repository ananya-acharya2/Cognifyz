#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str); 
    printf("Reversed string: ");
    int i;   
	for (i=length-1; i>= 0; i--) {
        printf("%c", str[i]); 
    }
    printf("\n");
}

int main() {
    char str[100]; 
    printf("Enter a string to reverse: ");
    fgets(str, sizeof(str), stdin); 
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
    reverseString(str); 
    getch();
    return 0;
}

