#include "game02.h"
#include "jokalaria.h"
#include "globals.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"

int hasierakoPosizioaTiroa = 0;
float posizioaTiroaX = 0, posizioaTiroaY = 0;

POSIZIOA JOKALARIAREN_TIROA(POSIZIOA posizioaJokalaria, POSIZIOA posizioaTiroa, POSIZIOA saguarenPosizioa, POSIZIOA posizioaBoss) {
	float angelua;
	if (hasierakoPosizioaTiroa == 0 && ebentu == SAGU_BOTOIA_EZKERRA) {
		posizioaTiroaX = posizioaJokalaria.x - saguarenPosizioa.x;
		posizioaTiroaY = posizioaJokalaria.y - saguarenPosizioa.y;
		hasierakoPosizioaTiroa = 1;
	}
	if (posizioaTiroaY != 0 && posizioaTiroaX != 0) {
		angelua = (float)atan(posizioaTiroaX / posizioaTiroaY);
	}
	if ((posizioaTiroaX < 0 && posizioaTiroaY < 0) || (posizioaTiroaX > 0 && posizioaTiroaY < 0)) {
		posizioaTiroa.x = posizioaTiroa.x + 7 * (float)sin(angelua);
		posizioaTiroa.y = posizioaTiroa.y + 7 * (float)cos(angelua);
	}
	else if ((posizioaTiroaX > 0 && posizioaTiroaY > 0) || (posizioaTiroaX < 0 && posizioaTiroaY > 0)) {
		posizioaTiroa.x = posizioaTiroa.x - 7 * (float)sin(angelua);
		posizioaTiroa.y = posizioaTiroa.y - 7 * (float)cos(angelua);
	}
	if (posizioaTiroa.x < -10 || posizioaTiroa.x > 630 || posizioaTiroa.y < 10 || posizioaTiroa.y > 470 || ((posizioaTiroa.x < posizioaBoss.x + 60 && posizioaTiroa.x > posizioaBoss.x) && (posizioaTiroa.y < posizioaBoss.y +70 && posizioaTiroa.y > posizioaBoss.y -10))) {
		posizioaTiroa.x = 1000;
		posizioaTiroa.y = 1000;
	}
	if (ebentu == SAGU_BOTOIA_EZKERRA && posizioaTiroa.x > 900) {
		hasierakoPosizioaTiroa = 0;
		posizioaTiroa.x = posizioaJokalaria.x;
		posizioaTiroa.y = posizioaJokalaria.y;
	}
	return posizioaTiroa;
}

POSIZIOA JOKALARIAREN_MUGIMENDUA(POSIZIOA posizioaJokalaria) {
	if (ebentu == TECLA_d && posizioaJokalaria.x < 580) {
		posizioaJokalaria.x = posizioaJokalaria.x + 10;
	}
	if (ebentu == TECLA_s && posizioaJokalaria.y < 440) {
		posizioaJokalaria.y = posizioaJokalaria.y + 10;
	}
	if (ebentu == TECLA_a && posizioaJokalaria.x > -5) {
		posizioaJokalaria.x = posizioaJokalaria.x - 10;
	}
	if (ebentu == TECLA_w && posizioaJokalaria.y > 20) {
		posizioaJokalaria.y = posizioaJokalaria.y - 10;
	}
	return posizioaJokalaria;
}

int JOKALARIAREN_IRUDIA(int irudia, int zenbakiaSprite) {
	if (ebentu == TECLA_d) {
		irudiaKendu(irudia);
		if (zenbakiaSprite % 2 == 0) {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_DERECHA1);
		}
		else {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_DERECHA2);
		}
	}
	if (ebentu == TECLA_s) {
		irudiaKendu(irudia);
		if (zenbakiaSprite % 2 == 0) {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);
		}
		else {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE2);
		}
	}
	if (ebentu == TECLA_a) {
		irudiaKendu(irudia);
		if (zenbakiaSprite % 2 == 0) {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_IZQUIERDA1);
		}
		else {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_IZQUIERDA2);
		}
	}
	if (ebentu == TECLA_w) {
		irudiaKendu(irudia);
		if (zenbakiaSprite % 2 == 0) {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_ATRAS1);
		}
		else {
			irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_ATRAS2);
		}
	}
	return irudia;
}

int JOKALARIAREN_BIZITZA(int bizitzKopurua, int bizitz1, int bizitz2, int bizitz3, int bizitz4, int bizitz5, int bizitzaKendu[]) {
	if (bizitzKopurua == 6) {
		irudiaMugitu(bizitz1, 0, 0);
		irudiaMugitu(bizitz2, 40, 0);
		irudiaMugitu(bizitz3, 80, 0);
		irudiaMugitu(bizitz4, 120, 0);
		irudiaMugitu(bizitz5, 160, 0);
		bizitzKopurua--;
	}
	if (bizitzKopurua == 4 && bizitzaKendu[0]==1) {
		irudiaKendu(bizitz5);
		bizitzaKendu[0] = 0;
	} else if (bizitzKopurua == 3 && bizitzaKendu[1] == 1) {
		irudiaKendu(bizitz4);
		bizitzaKendu[1] = 0;
	} else if (bizitzKopurua == 2 && bizitzaKendu[2] == 1) {
		irudiaKendu(bizitz3);
		bizitzaKendu[2] = 0;
	} else if (bizitzKopurua == 1 && bizitzaKendu[3] == 1) {
		irudiaKendu(bizitz2);
		bizitzaKendu[3] = 0;
	} else if (bizitzKopurua == 0 && bizitzaKendu[4] == 1) {
		irudiaKendu(bizitz1);
		bizitzaKendu[0] = 0;
	}
	return bizitzKopurua;
}

int JOKALARIAREN_BIZITZA_KENTZEA(int bizitzKopurua, POSIZIOA jokalaria, POSIZIOA oztopoa) {
	int soinua;
	if (jokalaria.x > oztopoa.x - 32 && jokalaria.x <oztopoa.x - 10 && jokalaria.y >oztopoa.y - 20 && jokalaria.y < oztopoa.y + 50) {
		bizitzKopurua--;
		soinua = loadSound(JOKOA_SOUND_GOLPE);
		playSound(soinua);
	}
	return bizitzKopurua;
}

int JOKALARIAREN_BIZITZA_KENTZEA_SUGEA(int bizitzKopurua, POSIZIOA jokalaria, POSIZIOA oztopoa) {
	int soinua;
	if (jokalaria.x > oztopoa.x - 10 && jokalaria.x <oztopoa.x + 40 && jokalaria.y >oztopoa.y - 10 && jokalaria.y < oztopoa.y + 80) {
		bizitzKopurua--;
		soinua = loadSound(JOKOA_SOUND_GOLPE);
		playSound(soinua);
	}
	return bizitzKopurua;
}

int BOSSAREN_BIZITZA(POSIZIOA posizioaTiroa, POSIZIOA posizioaBoss, int bossarenBizitzak) {
	if (posizioaTiroa.x < posizioaBoss.x + 65 && posizioaTiroa.x + 5 > posizioaBoss.x && posizioaTiroa.y < posizioaBoss.y + 75 && posizioaTiroa.y + 5> posizioaBoss.y) {
	bossarenBizitzak--;
	}
	return bossarenBizitzak;
}

int JOKALARIAREN_BIZITZA_KENTZEA_BOSS4(int bizitzKopurua, POSIZIOA posizioaJokalaria, POSIZIOA posizioaPilota) {
	int soinua;
	if ((posizioaPilota.x - 45 < posizioaJokalaria.x  && posizioaPilota.x + 60 > posizioaJokalaria.x) && (posizioaPilota.y - 40 < posizioaJokalaria.y  && posizioaPilota.y + 80 > posizioaJokalaria.y)) {
		bizitzKopurua--;
		soinua = loadSound(JOKOA_SOUND_GOLPE);
		playSound(soinua);
	}
	return bizitzKopurua;
}

int JOKALARIAREN_BIZITZA_KENTZEA_BOSS4MINA(POSIZIOA posizioaJokalaria, POSIZIOA posizioaPilota) {
	int soinua;
	if ((posizioaPilota.x - 10 < posizioaJokalaria.x  && posizioaPilota.x + 40 > posizioaJokalaria.x) && (posizioaPilota.y - 10 < posizioaJokalaria.y  && posizioaPilota.y + 80 > posizioaJokalaria.y)) {
		return 1;
		soinua = loadSound(JOKOA_SOUND_GOLPE);
		playSound(soinua);
	}
	else return 0;
}
