#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "time.h"

void get_input(char input[], uint32_t size)
{
    char ch;
    unsigned int idx = 0;
    printf("Enter name: ");
    while (((ch = getchar()) != '\n') && (idx < (size - 1)))
    {
        input[idx++] = ch;
    }
    input[idx++] = '\0';
}

uint32_t get_rand(uint32_t max)
{
    static bool is_seeded = false;
    if (!is_seeded) srand((uint32_t)time(NULL));

    return ((rand() % max) + 1);
}

int main(int argc, char* argv[])
{




    return 0; // all is well that ends well!
}

