#include <stdlib.h>
#include <stdio.h>

#include "error.h"

void error(char const* errore) {

	printf("%s\n",errore);
	exit(0);

}
