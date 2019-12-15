#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the matchingStrings function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int min(int a,int b)
{
    return (a<b)?b:a;
}
int* matchingStrings(int scount, char** str, int qcount, char** que, int* rcount) 
{
    int i,j,k=0;
    int *a = (int*)malloc(1000*sizeof(int));
    int count=0,m=0;
    while(k<qcount)
    {
        count=0;
        for(i=0;i<scount;i++)
        {
            //count=0;
            for(j=0;j<min(strlen(que[k]),strlen(str[i]));j++)
            {
               /* if(strcmp(str[i],que[k])==0)
                count++;*/
                if(str[i][j] != que[k][j])
                break;
                if(j==strlen(str[i])-1)
                count++;
            }
        }
         a[m++]=count;
        k++;
    }
    *rcount=m;
    return a;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* strings_count_endptr;
    char* strings_count_str = readline();
    int strings_count = strtol(strings_count_str, &strings_count_endptr, 10);

    if (strings_count_endptr == strings_count_str || *strings_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** strings = malloc(strings_count * sizeof(char*));

    for (int i = 0; i < strings_count; i++) {
        char* strings_item = readline();

        *(strings + i) = strings_item;
    }

    char* queries_count_endptr;
    char* queries_count_str = readline();
    int queries_count = strtol(queries_count_str, &queries_count_endptr, 10);

    if (queries_count_endptr == queries_count_str || *queries_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** queries = malloc(queries_count * sizeof(char*));

    for (int i = 0; i < queries_count; i++) {
        char* queries_item = readline();

        *(queries + i) = queries_item;
    }

    int res_count;
    int* res = matchingStrings(strings_count, strings, queries_count, queries, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%d", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

