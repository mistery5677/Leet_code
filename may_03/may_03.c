#include <stdio.h>
#include <string.h>

int clear_zero(char *version, int start)
{
    if(version[start] == '.')
        start++;
    while(version[start] == '0')
        start++;
    if (version[start] == '.' || version[start] == NULL)
        start--;
    return start;
}

int value(char *version, int start)
{
    int value = 0;
    while(version[start] && version[start] != '.')
    {
        value += (value * 10) + version[start];
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
        v2_value = value(version2, j);
        if(v1_value > v2_value)
            return 1;
        else if(v1_value < v2_value)
            return -1;
        while(version1[i] != '.' && version1[i])
            i++;
        while(version2[j] != '.' && version2[j])
            j++;
        i = clear_zero(version1, i);
        j = clear_zero(version2, j);
    }
    return 0;
}

// proxima tentativa tentar juntar o numero num = num * version * 10
int main()
{
    char *version1 = "1.2";
    char *version2 = "1.10";
    int compare = compareVersion(version1, version2);

    printf("result= %d\n", compare);
}