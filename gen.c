#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    char filename[100];

    printf("Numbers to generate: ");
    scanf("%d", &n);

    printf("File name: ");
    scanf("%s", filename);

    srand(time(NULL));

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Wrong file name. \n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        int random_nr = rand();
        fprintf(fp, "%d\n", random_nr);
    }

    fclose(fp);
    printf("Created file: %s.", filename);

    return 0;
}
