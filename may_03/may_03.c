#include <stdio.h>
#include <string.h>

/* int finish1(char *version1, int start)
{
    if(version1[start - 1] == '0')
    {
        while(version1[start])
        {
            if(version1[start] != '0' && version1[start] != '.')
                return 1;
            start++;
        }
    }
    else
        return 1;
    return 0;
}

int finish2(char *version2, int start)
{
    if(version2[start - 1] == '0')
    {
        while(version2[start])
        {
            if(version2[start] != '0' && version2[start] != '.')
                return -1;
            start++;
        }
    }
    else
        return -1;
    return 0;
}

int compareVersion(char* version1, char* version2) {
    size_t i = 0;
    size_t j = 0;

    while(version1[i] == '0')
        i++;
    while(version2[j] == '0')
        j++;
    if(version1[i] > version2[j])
        return 1;
    if(version1[i] < version2[j])
        return -1;
    while (version1[i] && version2[j])
    {
        while(version1[i] == '0')
            i++;
        while(version2[j] == '0')
            j++;
        if(i == strlen(version1) || j == strlen(version2))
            break;
        if(version1[i] > version2[j])
        {
            printf("len %zu\n i: %zu\n", strlen(version1), i);
            return 1;
        }
        if(version1[i] < version2[j])
            return -1;
        i++;
        j++;
    }
    printf("len %zu\n i: %zu\n", strlen(version1), i);
    if (i < strlen(version1))
        return finish1(version1, i);
    if (j < strlen(version2))
        return finish2(version2, j);
    return 0;
} */

int compareVersion(char* version1, char* version2)
{
    size_t i = 0;
    size_t j = 0;

    while(version1[i] && version2[j])
    {
        while(version1[i] == '0')
            i++;
        while(version2[j] == '0')
            j++;
        while(version1[i] != '.' && version1[i])
        {
            if(version1[i] > version2[j])
                return 1;
            else if(version1[i] < version2[j])
                return -1;
            i++;
            j++;
        }
        i++;
        j++;
    }
    return 0;
}

int main()
{
    char *version1 = "1.2";
    char *version2 = "1.10";
    int compare = compareVersion(version1, version2);

    printf("result= %d\n", compare);
}