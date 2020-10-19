#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <dirent.h>


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

 int main()
 {
     char input_dir[256];

     get_input(input_dir, sizeof(input_dir));


 }

