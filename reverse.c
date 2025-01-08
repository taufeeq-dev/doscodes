#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void reverseString(char *str, char *reversed) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
}

int main() {
    char str[100], reversed[100];
    pid_t pid;

    printf("Enter a string: ");
    scanf("%s", str);

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) { // Child process
        reverseString(str, reversed);
        printf("Reversed string: %s\n", reversed);
        exit(0);
    } else { // Parent process
        wait(NULL); // Wait for child process to finish
        if (strcmp(str, reversed) == 0) {
            printf("The string is a palindrome.\n");
        } else {
            printf("The string is not a palindrome.\n");
        }
    }

    return 0;
}
