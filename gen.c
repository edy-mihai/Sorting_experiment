#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, choice, datatype;
    char filename[100];

    printf("Numbers to generate: ");
    scanf("%d", &n);

    printf("Select data format:\n");
    printf("1. Integers\n");
    printf("2. Floats\n");
    printf("Choice (1 or 2): ");
    scanf("%d", &datatype);

    printf("Select data type:\n");
    printf("1. Fully Random\n");
    printf("2. Partially Sorted\n");
    printf("3. Fully Sorted\n");
    printf("4. Reversed\n");
    printf("Choice (1-4): ");
    scanf("%d", &choice);

    printf("File name: ");
    scanf("%s", filename);

    srand(time(NULL));

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Wrong file name. \n");
        return 1;
    }

    if (datatype == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int rndm_prct = rand() % 100;
            if (choice == 1)
            {
                fprintf(fp, "%d\n", rand());
            }
            else if (choice == 2)
            {
                if (rndm_prct < 5)
                {
                    fprintf(fp, "%d\n", rand());
                }
                else
                {
                    fprintf(fp, "%d\n", i);
                }
            }
            else if (choice == 3)
            {
                fprintf(fp, "%d\n", i + 1);
            }
            else if (choice == 4)
            {
                fprintf(fp, "%d\n", n - i);
            }
        }
    }
    else if (datatype == 2)
    {
        for (int i = 0; i < n; i++)
        {
            float rnd_float = ((float)rand() / (float)(RAND_MAX)) * 100000.0;

            if (choice == 1)
            {
                fprintf(fp, "%f\n", rnd_float);
            }
            else if (choice == 2)
            {
                int rndm_prct = rand() % 100;
                if (rndm_prct < 5)
                {
                    fprintf(fp, "%f\n", rnd_float);
                }
                else
                {
                    fprintf(fp, "%f\n", (float)(i + 1));
                }
            }
            else if (choice == 3)
            {
                fprintf(fp, "%f\n", (float)(i + 1));
            }
            else if (choice == 4)
            {
                fprintf(fp, "%f\n", (float)(n - i));
            }
        }
    }

    fclose(fp);
    printf("Created file: %s.", filename);

    return 0;
}
