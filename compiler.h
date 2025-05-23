#ifndef COMPILER_H
#define COMPILER_H
#include <stdio.h>
enum{
    COMPILER_FAILED_WITH_ERROR,
    COMPILER_FILE_COMPILED_OK
};
struct compile_process {
    struct compile_process_input_file
    {
        FILE* fp;
        const char* abs_path;
    }cfile;
    FILE* ofile;
    //like -o -g
    int flags;
};


int compile_file(const char* filename, const char* out_filename, int flags);
struct compile_process *compile_process_create(const char *filename, const char *out_filename, int flags);

#endif