#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void permute(char *sorted, int *used, char *current, int depth, int len)
{
    if (depth == len)
    {
        current[depth] = '\0';
        write(1, current, depth);
        write(1, "\n", 1);
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            current[depth] = sorted[i];
            permute(sorted, used, current, depth + 1, len);
            used[i] = 0;
        }
    }
}
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void    rev_sort(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
        for(int j = i + 1; j < len; j++)
            if (str[j] < str[i])
                swap(&str[i], &str[j]);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    char *str = argv[1];
    int len = strlen(str);
    char *sorted = malloc(len + 1);
    strcpy(sorted, str);
    rev_sort(sorted);
    int *used = calloc(len, sizeof(int));
    char *current = malloc(len + 1);
    permute(sorted, used, current, 0, len);
    free(sorted);
    free(used);
    free(current);
    return 0;
}
