#include <stdio.h>

void sort_people(int *people)
{
    int i = 0;
    int j;
    int temp = 0;

    while(people[i])
    {
        j = i + 1;
        while(people[j])
        {
            if(people[i] > people[j])
            {
                temp = people[j];
                people[j] = people[i];
                people[i] = temp; 
            }
            j++;
        }
        i++;
    }
}

int numRescueBoats(int* people, int peopleSize, int limit) 
{
    int boats = 0;
    int i = 0;
    int weight = 0;
    (void)peopleSize;
    sort_people(people);
    while(people[i])
    {
        weight += people[i]; 
        if(weight >= limit)
        {
            boats++;
            weight = 0;
        }
        printf("weight: %d\n", weight);
        i++;
    }
    return boats;    
}


int main() {
    int people[] = {3, 2, 2, 1};
    int peopleSize = sizeof(people) / sizeof(people[0]);
    int limit = 3;

    int boats = numRescueBoats(people, peopleSize, limit);
    printf("Number of boats needed: %d\n", boats);

    return 0;
}