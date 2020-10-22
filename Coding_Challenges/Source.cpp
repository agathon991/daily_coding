#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "../include/dirent.h"
#include "sys/stat.h"
#include <time.h>


void get_input(char input[], uint32_t size)
{
    char ch;
    unsigned int idx = 0;
    printf("Enter directory path: ");
    while (((ch = getchar()) != '\n') && (idx < (size - 1)))
    {
        input[idx++] = ch;
    }
    input[idx++] = '\0';
}

 int main()
 {

     /*
     * ask user for an input path
     * get file information for the files/directories in the path
     * output the information to a file in the current directory
     */

     DIR* dir_info;
     dirent* dir_entry;
     char input_dir[256];
     struct stat file_stats;
     FILE* f;

     get_input(input_dir, sizeof(input_dir));

     f = fopen("filelist.txt", "w");

     if (!f)
     {
         printf("Unable to create output file. Bye!");
         exit(1);
     }

     dir_info = opendir(input_dir);
     if (dir_info)
     {
         fprintf(f, " Opened folder: %s\n", input_dir);

         while ((dir_entry = readdir(dir_info)) != NULL)
         {
             stat(dir_entry->d_name, &file_stats);
             if (S_ISDIR(file_stats.st_mode))
             {
                 fprintf(f, " DIR ");
             }
             else
             {
                 fprintf(f, "FILE ");
             }
             fprintf(f, "%48.48s %10d %48.48s", dir_entry->d_name, file_stats.st_size, ctime(&file_stats.st_ctime));
         }

     }
     else
     {
         fprintf(f, " Unable to open folder: %s", input_dir);
     }

     if (f)
     {
         fflush(f);
         fclose(f);
     }
 }

