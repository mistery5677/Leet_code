#include <stdio.h>

int start_version(char *version, int start)
{
    while (version[start] == '0')
        start++;
    if (version[start] == '.')
        start--;
    return start;
}

int compareVersion(char* version1, char* version2) {
    int start1 = start_version(version1, 0);
    int start2 = start_version(version2, 0);

    while(version1[start1] || version2[start2])
    {
        if (version1[start1] > version2[start2])
            return 1;
        if (version1[start1] < version2[start2])
            return -1;
        start1++;
        start2++;
        if (version1[start1] == '.' && version2[start2] == '.')
        {
            start1++;
            start2++;
            start1 = start_version(version1, start1);
            start2 = start_version(version2, start2);
        }
    }
    return 0;
}

int main()
{
    char *version1 = "0012";
    char *version2 = "00.12";

    int start1 = start_version(version1);
    int start2 = start_version(version2);

    printf("start1: %d\nstart2: %d\n", start1, start2);
}