#ifndef LESAO_H
#define LESAO_H
#include <stdio.h>
#include "data.h"
#include <stdlib.h>
#include <string.h>

typedef struct lesao tLesao;
tLesao *CriarELerLesao();
char * RetornarLog(tLesao *lesao);
#endif