#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 500
#define NUM_SENTENCES 10

int countWords(char str[]) {
    int count = 0;
    int inWord = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            if(!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}

int main() {
    char *sentences[NUM_SENTENCES] = {
        "C programming is very powerful and flexible.",
        "Practice makes a man perfect in coding.",
        "Typing speed is important for programmers.",
        "Learning algorithms improves problem solving skills.",
        "Debugging is an essential skill for developers.",
        "Data structures help in organizing information efficiently.",
        "Consistency is the key to becoming a good coder.",
        "Errors are opportunities to learn and improve.",
        "Patience and practice lead to mastery.",
        "Time management is crucial for software development."
    };

    srand(time(0));
    int index = rand() % NUM_SENTENCES;

    char userInput[MAX_LEN];
    char original[MAX_LEN];
    strcpy(original, sentences[index]);

    printf("Type the following sentence:\n\n%s\n\n", sentences[index]);

    // Use time() instead of clock() for wall-clock time
    time_t start = time(NULL);
    fgets(userInput, MAX_LEN, stdin);
    time_t end = time(NULL);

    // Time taken in seconds
    double timeTaken = difftime(end, start);

    // Calculate words
    int totalWords = countWords(original);
    int typedWords = countWords(userInput);

    // Count correct words - FIXED LOGIC
    char tempOriginal[MAX_LEN], tempUser[MAX_LEN];
    strcpy(tempOriginal, original);
    strcpy(tempUser, userInput);

    // Create arrays to store individual words
    char *originalWords[MAX_LEN];
    char *userWords[MAX_LEN];
    int origCount = 0, userCount = 0;

    // Tokenize original sentence
    char *token = strtok(tempOriginal, " \n\t");
    while(token != NULL) {
        originalWords[origCount++] = token;
        token = strtok(NULL, " \n\t");
    }

    // Tokenize user input
    token = strtok(tempUser, " \n\t");
    while(token != NULL) {
        userWords[userCount++] = token;
        token = strtok(NULL, " \n\t");
    }

    // Compare word by word
    int correctWords = 0;
    int minWords = (origCount < userCount) ? origCount : userCount;
    
    for(int i = 0; i < minWords; i++) {
        if(strcmp(originalWords[i], userWords[i]) == 0) {
            correctWords++;
        }
    }

    // Calculate metrics
    double accuracy = (totalWords > 0) ? ((double)correctWords / totalWords) * 100 : 0;
    double wpm = (timeTaken > 0) ? ((double)typedWords / timeTaken) * 60 : 0;

    printf("\n--- Results ---\n");
    printf("Time Taken: %.0lf seconds\n", timeTaken);
    printf("Total Words: %d\n", totalWords);
    printf("Typed Words: %d\n", typedWords);
    printf("Correct Words: %d\n", correctWords);
    printf("Accuracy: %.2lf%%\n", accuracy);
    printf("Words Per Minute (WPM): %.2lf\n", wpm);

    return 0;
}
