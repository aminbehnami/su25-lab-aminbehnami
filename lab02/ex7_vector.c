#include <stdlib.h>
#include <stdio.h>
#include "ex7_vector.h"

struct vector_t {
    size_t size;
    int *data;
};

static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

vector_t *bad_vector_new() {
    vector_t *retval, v;
    retval = &v;
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }
    retval->data[0] = 0;
    return retval;
}

vector_t *vector_new() {
    vector_t *retval = (vector_t *)malloc(sizeof(vector_t));
    if (retval == NULL) {
        allocation_failed();
    }

    retval->size = 1;
    retval->data = (int *)malloc(sizeof(int));
    if (retval->data == NULL) {
        free(retval);
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

int vector_get(vector_t *v, size_t loc) {
    if (v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    if (loc >= v->size) return 0;
    return v->data[loc];
}

void vector_delete(vector_t *v) {
    if (v == NULL) return;
    free(v->data);
    free(v);
}

void vector_set(vector_t *v, size_t loc, int value) {
    if (loc >= v->size) {
        v->data = realloc(v->data, (loc + 1) * sizeof(int));
        if (v->data == NULL) {
            allocation_failed();
        }
        for (int i = v->size; i < loc; i++) {
            v->data[i] = 0;
        }
        v->size = loc + 1;
    }
    v->data[loc] = value;
}
