#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    // Malloc all the array of strings
    *returnSize = scoreSize;
    char **result = (char **)malloc(scoreSize * sizeof(char*));
    if (!result)
        return NULL;
    for (int i = 0; i < scoreSize; i++) {
        result[i] = (char *)malloc(13 * sizeof(char));
        if (!result[i]) {
            // Handle memory allocation failure
            for (int j = 0; j < i; j++)
                free(result[j]);
            free(result);
            return NULL;
        }
    }

    // Rank the scores
    for (int i = 0; i < scoreSize; i++) {
        int rank = 1;
        for (int j = 0; j < scoreSize; j++)
            if (score[i] < score[j])
                rank++;
        if (rank == 1) {
            strcpy(result[i], "Gold medal");
        } else if (rank == 2) {
            strcpy(result[i], "Silver medal");
        } else if (rank == 3) {
            strcpy(result[i], "Bronze medal");
        } else {
            sprintf(result[i], "%d", rank);
        }
    }
    return result;
}

int main() {
		int scores[] = {5, 8, 2, 6, 9};
		int size = sizeof(scores) / sizeof(scores[0]);

		int returnSize;
		char **result = findRelativeRanks(scores, size, &returnSize);

		printf("Relative Ranks:\n");
		for (int i = 0; i < returnSize; i++) {
				printf("%s\n", result[i]);
		}

		// Free memory
		for (int i = 0; i < returnSize; i++) {
				free(result[i]);
		}
		free(result);

		return 0;
}