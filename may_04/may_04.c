#include <stdio.h>

int compare(const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int numRescueBoats(int* people, int peopleSize, int limit) 
{
    int right = peopleSize - 1;
    int left = 0;
    int boats = 0;

    qsort(people, peopleSize, sizeof(int), compare); 
    while(left <= right)
    {
        if(people[left] + people[right] <= limit)
            right--;
        left++;
        boats++;
    }
    return boats;    
}


/* int main() {
    int people[] = {3, 2, 2, 1};
    int peopleSize = sizeof(people) / sizeof(people[0]);
    int limit = 3;

    printf("people size: %d\n", peopleSize);
    int boats = numRescueBoats(people, peopleSize, limit);
    printf("Number of boats needed: %d\n", boats);

    return 0;
} */