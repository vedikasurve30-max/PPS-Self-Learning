
“Analyze this C code, find any hidden bugs or errors, explain why they occur, and show me the corrected code.” This report documents the three supplied snippets, explains each bug, and gives corrected versions with sample output previews.

Snippet A: Syntax and input handling 

What was wrong: The declaration int age lacks a semicolon, so the source does not compile. Also, scanf("%d", age) passes the integer value as if it were an address. scanf must receive &age so it can store the input. The corrected version checks scanf’s return value before using the variable. 

Corrected code:

#include <stdio.h>
int main(void) {
    int age;

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Your age is %d\n", age);
    return 0;
}

Output:















Snippet B: Assignment instead of comparion 

What was wrong: The original condition marks = 40 assigns 40 to marks. The assignment expression evaluates to 40, which is true in a C condition, so the pass branch runs regardless of the original mark. The corrected code uses marks == 40 to compare the value. With marks set to 35, the student fails. If a score of 40 or more should pass, use marks >= 40 instead. 

Corrected code:
#include <stdio.h>
int main(void) {
    int marks = 35;

    printf("Checking student result...\n");
    if (marks == 40) {
        printf("Student has passed!\n");
    } else {
        printf("Student has failed.\n");
    }

    return 0;
}

Output:











Snippet C: Countdown loop never terminates What was wrong: The loop condition is count > 0, but the body uses count++, increasing count. It therefore never approaches the stopping condition. Eventually signed integer overflow would occur, which is undefined behavior in C. Decrementing with count-- makes the loop reach zero.

Corrected code:
#include <stdio.h>
int main(void) {
    int count = 5;

    printf("Starting countdown:\n");
    while (count > 0) {
        printf("Count: %d\n", count);
        count--;
    }

    printf("Done!\n");
    return 0;
}

Output:


