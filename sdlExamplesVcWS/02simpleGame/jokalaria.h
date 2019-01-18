#ifndef JOKALARIA_H
#define JOKALARIA_H

#include "ourTypes.h"

POSIZIOA JOKALARIAREN_TIROA(POSIZIOA posizioaJokalaria, POSIZIOA posizioaTiroa, POSIZIOA saguarenPosizioa, POSIZIOA posizioaBoss);
POSIZIOA JOKALARIAREN_MUGIMENDUA(POSIZIOA posizioaJokalaria);
int JOKALARIAREN_IRUDIA(int irudia, int zenbakiaSprite);
int JOKALARIAREN_BIZITZA(int bizitzKopurua, int bizitz1, int bizitz2, int bizitz3, int bizitz4, int bizitz5, int bizitzaKendu[]);
int JOKALARIAREN_BIZITZA_KENTZEA(int bizitzKopurua, POSIZIOA jokalaria, POSIZIOA oztopoa);
int BOSSAREN_BIZITZA(POSIZIOA posizioaTiroa, POSIZIOA posizioaBoss, int bossarenBizitzak);
int JOKALARIAREN_BIZITZA_KENTZEA_SUGEA(int bizitzKopurua, POSIZIOA jokalaria, POSIZIOA oztopoa);
int JOKALARIAREN_BIZITZA_KENTZEA_BOSS4(int bizitzKopurua, POSIZIOA posizioaJokalaria, POSIZIOA posizioaPilota);
#endif
