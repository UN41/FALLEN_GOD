#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum { BOSS1, BOSS1B, BOSS2, BOSS2B, BOSS3, BOSS3B, BOSS4, BOSS4B, GALDU, IRABAZI}EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
  POSIZIOA pos;
  int id;
  MOTA mota;
}JOKO_ELEMENTUA;

#endif