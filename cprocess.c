#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"
struct compile_process *compile_process_create(const char *filename, const char *out_filename, int flags)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }
    FILE *out_file = NULL;
    if (out_filename != NULL)
    {
        out_file = fopen(out_filename, "w");
        if (out_file == NULL)
        {
            perror("Error opening output file");
            return NULL;
        }
    }
    struct compile_process *process = calloc(1,sizeof(struct compile_process));
    process->flags = flags;
    process->cfile.fp = file;
    process->ofile = out_file;
    return process;
}
