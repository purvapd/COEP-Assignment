#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000  // Maximum number of rows in the text file
#define MAX_COLS 100   // Maximum number of columns in the text file
#define MAX_LENGTH 256 // Maximum length of each field

// Function to compare two strings for alphabetical sorting
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to compare two numbers for numeric sorting
int compareNumbers(const void *a, const void *b) {
    int num1 = atoi(*(const char **)a);
    int num2 = atoi(*(const char **)b);
    return num1 - num2;
}

int main() {
    char filename[256];
    int sortColumn = 0;
    char sortOrder[15] = "alphabetical";
    char *data[MAX_ROWS][MAX_COLS];
    int numRows = 0;
    int numCols = 0;

    // Read input filename from user
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    // Read input sort column from user
    printf("Enter the column number to sort (starting from 1): ");
    scanf("%d", &sortColumn);

    // Read input sort order from user
    printf("Enter the sort order (alphabetical/numeric): ");
    scanf("%s", sortOrder);

    // Open the text file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read data from the text file
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char *token;
        token = strtok(line, " \t\n");
        int col = 0;
        while (token != NULL) {
            data[numRows][col] = strdup(token);
            token = strtok(NULL, " \t\n");
            col++;
        }
        numCols = col;
        numRows++;
    }
    fclose(file);

    // Sort the data based on the specified column and sort order
    if (strcmp(sortOrder, "numeric") == 0) {
        qsort(data, numRows, sizeof(char *[MAX_COLS]), compareNumbers);
    } else {
        qsort(data, numRows, sizeof(char *[MAX_COLS]), compareStrings);
    }

    // Print the sorted data
    printf("\nSorted Data:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%s\t", data[i][j]);
            free(data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
