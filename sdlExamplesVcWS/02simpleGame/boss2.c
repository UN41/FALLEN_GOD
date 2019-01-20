#include "jokalaria.h"
#include "globals.h"
#include "boss2.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"

int hasierakoPosizioaSugea = 0;
float posizioaSugeaX = 0, posizioaSugeaY = 0;
int paretenKontraKont = 0;


POSIZIOA BOSS_JOKALARIARA_JARRAITU(POSIZIOA posizioaBoss, POSIZIOA posizioaJokalaria) {
	float angelua;

	if (paretenKontraKont < 5) {
		if (hasierakoPosizioaSugea == 0) {
			posizioaSugeaX = posizioaJokalaria.x - posizioaBoss.x;
			posizioaSugeaY = posizioaJokalaria.y - posizioaBoss.y;
			hasierakoPosizioaSugea = 1;
		}
		if (posizioaSugeaY != 0 && posizioaSugeaX != 0) {
			angelua = (float)atan(posizioaSugeaX / posizioaSugeaY);
		}
		if ((posizioaSugeaX < 0 && posizioaSugeaY < 0) || (posizioaSugeaX > 0 && posizioaSugeaY < 0)) {
			posizioaBoss.x = posizioaBoss.x - (float)4 * (float)sin(angelua);
			posizioaBoss.y = posizioaBoss.y - (float)4 * (float)cos(angelua);
		}
		else if ((posizioaSugeaX > 0 && posizioaSugeaY > 0) || (posizioaSugeaX < 0 && posizioaSugeaY > 0)) {
			posizioaBoss.x = posizioaBoss.x + (float)4 * (float)sin(angelua);
			posizioaBoss.y = posizioaBoss.y + (float)4 * (float)cos(angelua);
		}
		if (posizioaBoss.x < -15 || posizioaBoss.x > 560 || posizioaBoss.y < -12 || posizioaBoss.y > 390) {
			hasierakoPosizioaSugea = 0;
			paretenKontraKont++;
		}
	}
	return posizioaBoss;
}


EGOERA boss2(void)
{
	EGOERA  egoera = BOSS2;
	int spriteAukeratu = 0, bizitzKopurua = 6;
	int hasierakoPosizioa = 0;
	int imageIdSerpiente1, imageIdBala, imageIdMapa, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, inmortala = 0;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	JOKO_ELEMENTUA boss, jokalaria, tiroa;
	POSIZIOA saguPos;
	int denbora = 0;
	int bossarenBizitzak = 20;

	imageIdMapa = irudiaKargatu(MAPA_BOSS2);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);

	imageIdSerpiente1 = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE1BOLA);
	irudiaMugitu(imageIdSerpiente1, 275, 180);
	imageIdBala = irudiaKargatu(TIROA_IMAGE);
	boss.pos.x = 500;
	boss.pos.y = 225;
	jokalaria.pos.x = 32;
	jokalaria.pos.y = 230;

	tiroa.pos.x = 1000;
	tiroa.pos.y = 1000;

	audioInit();
	loadTheMusic(JOKOA_SOUND_BOSS2);
	playMusic();
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);
	irudiaMugitu(jokalaria.id, (int)jokalaria.pos.x, (int)jokalaria.pos.y - 20);

	do {
		Sleep(10);
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		spriteAukeratu++;
		inmortala++;
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, boss.pos, bossarenBizitzak);
		tiroa.pos = JOKALARIAREN_TIROA(jokalaria.pos, tiroa.pos, saguPos, boss.pos);
		boss.pos = BOSS_JOKALARIARA_JARRAITU(boss.pos, jokalaria.pos);
		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		imageIdSerpiente1 = SUGEAREN_IRUDIA(imageIdSerpiente1);

		if (inmortala >= 10 && bizitzKopurua > 0) {
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA_SUGEA(bizitzKopurua, jokalaria.pos, boss.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			inmortala = 0;
		}

		if (denbora >= 800) {
			imageIdSerpiente1 = SUGEA_GELDIRIK(imageIdSerpiente1);
			denbora = 0;
			paretenKontraKont = 0;
		}
		pantailaGarbitu();

		irudiaMugitu(jokalaria.id, (int)jokalaria.pos.x, (int)jokalaria.pos.y - 20);
		irudiaMugitu(imageIdBala, (int)tiroa.pos.x, (int)tiroa.pos.y);
		irudiaMugitu(imageIdSerpiente1, (int)boss.pos.x, (int)boss.pos.y);

		irudiakMarraztu();
		pantailaBerriztu();
		denbora++;
		egoera = JOKO_EGOERA_AZTERTU_BOSS2(bizitzKopurua, bossarenBizitzak);

	} while (egoera == BOSS2);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}

int SUGEAREN_IRUDIA(int irudia) {
	if (paretenKontraKont >= 5) {
		irudiaKendu(irudia);
		irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE1);
		paretenKontraKont = 6;
	}
	return irudia;
}

int SUGEA_GELDIRIK(int irudia) {

	if (paretenKontraKont == 6) {
		irudiaKendu(irudia);
		irudia = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE1BOLA);
	}
	return irudia;
}

EGOERA JOKO_EGOERA_AZTERTU_BOSS2(int bizitzKopurua, int bossarenBizitzak) {
	EGOERA ret = BOSS2;
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	else if (bossarenBizitzak <= 0) {
		ret = IRABAZI;
	}
	return ret;
}
