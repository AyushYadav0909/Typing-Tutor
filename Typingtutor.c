#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char sentence[] = "Typing practice makes you better";
    char typed[200];
    int i, correct = 0, total;
    clock_t start, end;
    double time_taken, minutes;
    int words = 1;

    printf("=== Typing Tutor ===\n");
    printf("Type the following sentence:\n\n%s\n\n", sentence);

    total = strlen(sentence);

    start = clock();

    printf("Start typing:\n");
    fgets(typed, sizeof(typed), stdin);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    for (i = 0; i < total; i++)
        if (typed[i] == sentence[i])
            correct++;

    for (i = 0; sentence[i] != '\0'; i++)
        if (sentence[i] == ' ')
            words++;

    minutes = time_taken / 60.0;
    double accuracy = ((double)correct / total) * 100;
    double wpm = words / minutes;

    printf("\n--- Results ---\n");
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Total Characters: %d\n", total);
    printf("Correct Characters: %d\n", correct);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Words Per Minute (WPM): %.2f\n", wpm);

    return 0;
}
