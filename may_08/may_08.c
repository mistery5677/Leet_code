#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    
    // Malloc all the array of strings
    *returnSize = scoreSize;
    char **result = (char **)malloc(scoreSize * sizeof(char*));
    if(!result)
        return NULL;
    for (int i = 0; i < scoreSize; i++)
    {
        result[i] = (char *)malloc(13 * sizeof(char));
        if (!result[i])
            return NULL;
    }

    // Rank the scores
    for(int i = 0; i < scoreSize; i++)
    {
        int rank = 1;
        for(int j = 0; j < scoreSize; j++)
            if (score[i] < score [j])
                rank++;
        if (rank == 1)
            result[i] = "Gold medal";
        else if (rank == 2)
            result[i] = "silver medal";
        else if(rank == 3)
            result[i] = "Bronze medal";
        else 
            result[i] = rank + '0';
    }
    return result;
}

char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
  // Rank every element of score array
  int rank[scoreSize];
  for (int i = 0; i < scoreSize; i++)
  {
    int el_rank = 1;

    for (int j = 0; j < scoreSize; j++)
      if (score[j] > score[i])
        el_rank++;

    rank[i] = el_rank;
  }

  // malloc
  *returnSize = scoreSize;
  char **res = (char **)malloc((*returnSize) * sizeof(char *));
  for (int i = 0; i < (*returnSize); i++)
    res[i] = (char *)malloc(13 * sizeof(char));

  // Fill res based on rank
  for (int i = 0; i < scoreSize; i++)
  {
    if (rank[i] > 3)
      sprintf(res[i], "%d", rank[i]);
    else if (rank[i] == 3)
      res[i] = "Bronze Medal";
    else if (rank[i] == 2)
      res[i] = "Silver Medal";
    else if (rank[i] == 1)
      res[i] = "Gold Medal";
  }

  return res;
}