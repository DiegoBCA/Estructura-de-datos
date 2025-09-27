#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char bracket;
    int index;
} StackElement;

int check_brackets(const char *s) {
    StackElement stack[MAX_STACK_SIZE];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            if (top < MAX_STACK_SIZE - 1) {
                stack[++top].bracket = c;
                stack[top].index = i;
            } else {
                return i; // Stack overflow (tratar como error)
            }
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {
                return i; // Cierra sin abrir
            }
            char expected_open = '\0';
            if (c == ')') expected_open = '(';
            else if (c == ']') expected_open = '[';
            else if (c == '}') expected_open = '{';

            if (stack[top].bracket != expected_open) {
                return i; // No coincide
            }
            top--; // Pop
        }
    }

    if (top != -1) {
        return stack[0].index; // Quedan sin cerrar
    }

    return -1; // OK
}

int main() {
    const char *test_cases[] = {
        "([]{})",          // OK
        "([)]",            // ERROR 2
        "abc(def[ghi]{j}k",// ERROR 3
        "{[}]",            // ERROR 3
        "([{]})",          // ERROR 3
        "(",                // ERROR 0
        ")",                // ERROR 0
        "a(b)c[d]e{f}",     // OK
    };

    for (int i = 0; i < 8; i++) {
        int result = check_brackets(test_cases[i]);
        if (result == -1) {
            printf("%s → OK\n", test_cases[i]);
        } else {
            printf("%s → ERROR %d\n", test_cases[i], result);
        }
    }

    return 0;
}
