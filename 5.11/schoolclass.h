#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

typedef struct {
    Person students[26];
    char section; 
    int grade; 
    Person teacher; 
} SchoolClass;

#endif 
