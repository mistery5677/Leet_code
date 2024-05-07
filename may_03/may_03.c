int finish(char *str, int start)
{
    while(str[start])
    {
        if (str[start] >= '1' && str[start] <= '9')
            return 1;
        start++;
    }
    return 0;
}

int clear_zero(char *version, int start)
{
    if(version[start] == '.')
        start++;
    while(version[start] == '0')
        start++;
    if (version[start] == '.')
        start--;
    return start;
}

int value(char *version, int start)
{
    long int value = 0;
    while(version[start] != '.' && version[start])
    {
        value = ((value * 10) + version[start]) - '0';
        start++;  
    }
    return value;
}

int compareVersion(char* version1, char* version2)
{
    size_t i = clear_zero(version1, 0);
    size_t j = clear_zero(version2, 0);
    long int v1_value = 0;
    long int v2_value = 0;

    while(i < strlen(version1) && j < strlen(version2))
    {
        v1_value = value(version1, i);
        v2_value = value(version2, j);
        if(v1_value > v2_value)
            return 1;
        else if(v1_value < v2_value)
            return -1;
        while(version1[i] != '.' && version1[i] != '\0')
            i++;
        while(version2[j] != '.' && version2[j] != '\0')
            j++;    
        i = clear_zero(version1, i);
        j = clear_zero(version2, j);
    }
    if (finish(version1, i) == 1)
        return 1;
    else if (finish(version2, j) == 1)
        return -1;
    return 0;
}