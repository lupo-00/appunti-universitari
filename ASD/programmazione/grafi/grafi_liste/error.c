#include <stdio.h>
#include <stdlib.h>

#include "error.h"

void error(char const* errore){
    printf("%s\n", errore);
    exit(1);
}
