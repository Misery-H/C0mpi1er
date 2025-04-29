#include <stdio.h>
#include "helpers/vector.h"
int main(){

    struct vector* v;
    v = vector_create(sizeof(int));
    int x =50;
    vector_push(v, &x);
    x=20;
    vector_push(v, &x);

    vector_set_peek_pointer(v, 0);
    int* p = vector_peek(v);
    while (p)
    {
        printf("%i\n", *p);
        p = vector_peek(v);
    }
    
    
    return 0;
}