#ifndef BOSS3_H
#define BOSS3_H
#include "ebentoak.h"
#include "OurTypes.h"

EGOERA JOKO_EGOERA_AZTERTU_BOSS3(int bizitzKopurua, int bossarenBizitzak);
POSIZIOA ARMA_BIRAKARIA_MUGITU(POSIZIOA posizioaPilota, POSIZIOA armarenKokapena, float anguloa, float rad);
void armaMarraztu(POSIZIOA kokapena, POSIZIOA koord, float anguloa, float luzera);
int kolisioaBoss3(POSIZIOA jokalaria, POSIZIOA Kokapena, POSIZIOA koord, float anguloa, float luzera);
int norabideaRandomizatu(int norabidea);

#endif