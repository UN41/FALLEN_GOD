#include "jokalaria.h"
#include "globals.h"
#include "boss1.h"
#include "boss1b.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"

int hasierakoPosizioaZirkuluaB1 = 0, hasierakoPosizioaZirkuluaB2 = 0;
float posizioaZirkuluaXBoss1b1 = 0, posizioaZirkuluaYBoss1b1 = 0, posizioaZirkuluaXBoss1b2 = 0, posizioaZirkuluaYBoss1b2 = 0;

EGOERA boss1b(void)
{
	EGOERA  egoera = BOSS1B;
	int imageIdArbol, imageIdBala, imageIdMapa, imageIdBolaArbola1, imageIdBolaArbola2;
	int spriteAukeratu = 0, bizitzKopurua =6 , bossarenBizitzak = 30;
	int bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, inmortala = 0;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	JOKO_ELEMENTUA bolaArbola1, bolaArbola2, jokalaria, tiroa, boss1;
	POSIZIOA saguPos;

	imageIdMapa = irudiaKargatu(MAPA_BOSS1);
	irudiaMugitu(imageIdMapa, 0, 0);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);

	imageIdArbol = irudiaKargatu(JOKOA_PLAYER_IMAGE_ARBOL2);
	imageIdBala = irudiaKargatu(TIROA_IMAGE);
	imageIdBolaArbola1 = irudiaKargatu(TIROA_BOSS1);
	imageIdBolaArbola2 = irudiaKargatu(TIROA_BOSS1);
	boss1.pos.x = 275;
	boss1.pos.y = 180;
	bolaArbola1.pos.x = 300;
	bolaArbola1.pos.y = 205;
	bolaArbola2.pos.x = 300;
	bolaArbola2.pos.y = 200;
	jokalaria.pos.x = 32;
	jokalaria.pos.y = 230;
	tiroa.pos.x = 1000;
	tiroa.pos.y = 1000;

	audioInit();
	loadTheMusic(JOKOA_SOUND_BOSS1);
	playMusic();
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);
	irudiaMugitu(jokalaria.id, (int)jokalaria.pos.x, (int)jokalaria.pos.y - 20);

	do {
		Sleep(10);
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		spriteAukeratu++;
		inmortala++;
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, boss1.pos, bossarenBizitzak);
		tiroa.pos = JOKALARIAREN_TIROA(jokalaria.pos, tiroa.pos, saguPos, boss1.pos);
		bolaArbola1.pos = ZIRKULUA_JOKALARIARA_MUGITU1(bolaArbola1.pos, jokalaria.pos);
		bolaArbola2.pos = ZIRKULUA_JOKALARIARA_MUGITU2(bolaArbola2.pos, jokalaria.pos);
		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		pantailaGarbitu();
		if (inmortala >= 6 && bizitzKopurua >= 1) {
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA(bizitzKopurua, jokalaria.pos, bolaArbola1.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA(bizitzKopurua, jokalaria.pos, bolaArbola2.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			inmortala = 0;
		}
		irudiaMugitu(imageIdBolaArbola1, (int)bolaArbola1.pos.x, (int)bolaArbola1.pos.y);
		irudiaMugitu(imageIdBolaArbola2, (int)bolaArbola2.pos.x, (int)bolaArbola2.pos.y);
		irudiaMugitu(jokalaria.id, (int)jokalaria.pos.x, (int)jokalaria.pos.y - 20);
		irudiaMugitu(imageIdBala, (int)tiroa.pos.x, (int)tiroa.pos.y);
		irudiaMugitu(imageIdArbol, (int)boss1.pos.x, (int)boss1.pos.y);

		irudiakMarraztu();
		pantailaBerriztu();

		egoera = JOKO_EGOERA_AZTERTU_BOSS1B(bizitzKopurua, bossarenBizitzak);
		egoera = JOKO_EGOERA_AZTERTU_BOSS1B(bizitzKopurua, bossarenBizitzak);
	} while (egoera == BOSS1B);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}

EGOERA JOKOA_egoera_boss1b(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa) {
	EGOERA  ret = BOSS1B;
	if (jokalaria.pos.x > oztopoa.pos.x - 32 && jokalaria.pos.x <oztopoa.pos.x - 10 && jokalaria.pos.y >oztopoa.pos.y - 20 && jokalaria.pos.y < oztopoa.pos.y + 20) {
		//ret = GALDU;
	}
	else if (jokalaria.pos.x > 900) {
		ret = IRABAZI;
	}
	return ret;
}


POSIZIOA ZIRKULUA_JOKALARIARA_MUGITU2(POSIZIOA posizioaPilota, POSIZIOA posizioaJokalaria) {
	float angelua;

	if (hasierakoPosizioaZirkuluaB2 == 0 || posizioaZirkuluaYBoss1b2 == 0) {
		posizioaZirkuluaXBoss1b2 = posizioaJokalaria.x - posizioaPilota.x;
		posizioaZirkuluaYBoss1b2 = posizioaJokalaria.y - posizioaPilota.y;
		hasierakoPosizioaZirkuluaB2 = 1;
	}

	if (posizioaZirkuluaYBoss1b2 != 0 && posizioaZirkuluaXBoss1b2 != 0) {
		angelua = (float)atan(posizioaZirkuluaXBoss1b2 / posizioaZirkuluaYBoss1b2);
	}

	if ((posizioaZirkuluaXBoss1b2 < 0 && posizioaZirkuluaYBoss1b2 < 0) || (posizioaZirkuluaXBoss1b2 > 0 && posizioaZirkuluaYBoss1b2 < 0)) {
		posizioaPilota.x = posizioaPilota.x - 2 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y - 2 * (float)cos(angelua);
	}
	else if ((posizioaZirkuluaXBoss1b2 > 0 && posizioaZirkuluaYBoss1b2 > 0) || (posizioaZirkuluaXBoss1b2 < 0 && posizioaZirkuluaYBoss1b2 > 0)) {
		posizioaPilota.x = posizioaPilota.x + 2 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y + 2 * (float)cos(angelua);
	}

	if (posizioaPilota.x < 10 || posizioaPilota.x > 630 || posizioaPilota.y < 10 || posizioaPilota.y > 470) {
		posizioaPilota.x = 300;
		posizioaPilota.y = 200;
		hasierakoPosizioaZirkuluaB2 = 0;
	}

	return posizioaPilota;
}

POSIZIOA ZIRKULUA_JOKALARIARA_MUGITU1(POSIZIOA posizioaPilota, POSIZIOA posizioaJokalaria) {
	float angelua;

	if (hasierakoPosizioaZirkuluaB1 == 0 || posizioaZirkuluaYBoss1b1 == 0) {
		posizioaZirkuluaXBoss1b1 = posizioaJokalaria.x - posizioaPilota.x;
		posizioaZirkuluaYBoss1b1 = posizioaJokalaria.y - posizioaPilota.y;
		hasierakoPosizioaZirkuluaB1 = 1;
	}

	if (posizioaZirkuluaYBoss1b1 != 0 && posizioaZirkuluaXBoss1b1 != 0) {
		angelua = (float)atan(posizioaZirkuluaXBoss1b1 / posizioaZirkuluaYBoss1b1);
	}

	if ((posizioaZirkuluaXBoss1b1 < 0 && posizioaZirkuluaYBoss1b1 < 0) || (posizioaZirkuluaXBoss1b1 > 0 && posizioaZirkuluaYBoss1b1 < 0)) {
		posizioaPilota.x = posizioaPilota.x - (float)4 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y - (float)4 * (float)cos(angelua);
	}
	else if ((posizioaZirkuluaXBoss1b1 > 0 && posizioaZirkuluaYBoss1b1 > 0) || (posizioaZirkuluaXBoss1b1 < 0 && posizioaZirkuluaYBoss1b1 > 0)) {
		posizioaPilota.x = posizioaPilota.x + (float)4 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y + (float)4 * (float)cos(angelua);
	}

	if (posizioaPilota.x < 10 || posizioaPilota.x > 630 || posizioaPilota.y < 10 || posizioaPilota.y > 470) {
		posizioaPilota.x = 300;
		posizioaPilota.y = 200;
		hasierakoPosizioaZirkuluaB1 = 0;
	}


	return posizioaPilota;
}

EGOERA JOKO_EGOERA_AZTERTU_BOSS1B(int bizitzKopurua, int bossarenBizitzak) {
	EGOERA ret = BOSS1B;
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	else if (bossarenBizitzak <= 0) {
		ret = IRABAZI;
	}
	return ret;
}
