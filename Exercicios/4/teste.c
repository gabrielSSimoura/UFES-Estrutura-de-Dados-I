#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char source[] = "GeeksForGeeks";

    // 5 bytes of source are copied to a new memory
    // allocated dynamically and pointer to copied
    // memory is returned.
    char *target = strndup(source, 5);

    printf("%s", target);
    free(target);
    return 0;
}