#ifndef _DEVEL_H_
#define _DEVEL_H_

#include<stdio.h>

#define affiche_message(x) printf("%s, ligne %d, fonction %s\n", (x), __LINE__, __PRETTY_FUNCTION__)

#endif
