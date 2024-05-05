#include <stdio.h>
#include <string.h>



int clear_zero(char *version, int start)
{
    if(version[start] == '.')
        start++;
    while(version[start] == '0')
        start++;
    if (version[start] == '.' || version[start] == '\0')
        start--;
    return start;
}

int value(char *version, int start)
{
    int value = 0;
    while(version[start] != '.' && version[start])
    {
        value = (value * 10) + version[start];
        start++;  
    }
    return value;
}

int compareVersion(char* version1, char* version2)
{
    size_t i = clear_zero(version1, 0);
    size_t j = clear_zero(version2, 0);
    int v1_value = 0;
    int v2_value = 0;

    while(version1[i] && version2[j])
    {
        v1_value = value(version1, i);
        printf("v1_value %d\n", v1_value);
        v2_value = value(version2, j);
        printf("v2_value %d\n", v2_value);
        if(v1_value > v2_value)
            return 1;
        else if(v1_value < v2_value)
            return -1;
        while(version1[i] != '.' && i <= strlen(version1))
            i++;
        while(version2[j] != '.' && j <= strlen(version2))
            j++;
        i = clear_zero(version1, i);
        j = clear_zero(version2, j);
    }
    return 0;
}

int main()
{
    char *version1 = "1202.01";
    char *version2 = "1202.001";
    int compare = compareVersion(version1, version2);

    printf("result= %d\n", compare);
}