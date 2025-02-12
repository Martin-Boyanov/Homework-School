#include "transformation.h"
#include <stdlib.h>
#include <string.h>

struct transformation string_to_long(char input[]) {
    struct transformation t;
    char *endptr;

    t.result = strtol(input, &endptr, 10);

    if (*endptr != '\0') {
        t.result = 0;
        strcpy(t.error, "Invalid input string");
    } else {
        t.error[0] = '\0';
    }

    return t;
}