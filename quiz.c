#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Added for tolower function

#define qna "qna.txt"

// Convert string to lowercase
void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int get_no_of_questions() {
    FILE *fp = fopen(qna, "r");
    char question[500], option1[100], option2[100], option3[100], option4[100];
    int i = 0, correct_answer;
    while (fscanf(fp, " %499[^,], %99[^,], %99[^,], %99[^,], %99[^,], %d\n", question, option1, option2, option3, option4, &correct_answer) == 6) {
        i++;
    }
    printf("Total number of questions: %d\n", i);
    fclose(fp);
    return i;
}


int main() {
    char answer[500];
    int score = 0;
    int check_answer;
    char correct_answer[500], question[500];
    char option1[500], option2[500], option3[500], option4[500];
    int correct_option;

    FILE *fp = fopen(qna, "r");
    int noofq = get_no_of_questions();

    for (int i = 0; i < noofq; i++) {
        fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%d\n", question, option1, option2, option3, option4, &correct_option);
        printf("%s\n", question);
        printf("1. %s\n", option1);
        printf("2. %s\n", option2);
        printf("3. %s\n", option3);
        printf("4. %s\n", option4);

        printf("Enter your answer (1, 2, 3, or 4): ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';

        // Convert answer to lowercase
        toLowercase(answer);

        if (atoi(answer) == correct_option) {
            check_answer = 1;
        } else {
            check_answer = 0;
        }

        printf("Hmm....\n");
        if (check_answer == 1) {
            score++;
        }
    }

    fclose(fp);

    float percentage = ((float)score / (float)noofq) * 100;

    if (score == noofq)
        printf("Wow, you got a perfect score\n");
    else if (percentage >= 80)
        printf("You got an amazing score, i.e., %d out of %d\n", score, noofq);
    else if (percentage >= 60)
        printf("You got a good score, i.e., %d out of %d\n", score, noofq);
    else if (percentage >= 40)
        printf("You got a satisfactory score, i.e., %d out of %d\n", score, noofq);
    else if (percentage < 40) {
        printf("You failed(%d out of %d). Would you like to try again? (Enter 'y' for yes): ", score, noofq);
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            main();
        } else {
            return 0;
        }
    } else {
        printf("Something went wrong\n");
    }

    return 0;
}
