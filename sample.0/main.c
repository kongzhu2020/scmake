#include <stdio.h>
#include "SCMakeConfig.h"

#ifdef USE_SMATH
#include "smath/smath.h"
#endif

int main()
{
    printf("hello scmake!\n");
    printf("SCMake_VERSION_MAJOR:%d\n",SCMake_VERSION_MAJOR);

    int a, b;
    int ret;

    a = 3;
    b = 4;

#ifdef USE_SMATH
    ret = add(a, b);
    printf("smath add(%d, %d)=%d\n", a, b, ret);
#endif

    return 0;
}


