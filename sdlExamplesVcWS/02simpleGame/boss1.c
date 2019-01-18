#include "jokalaria.h"
//#include "globals.h"
#include "boss1.h"
#include "boss1b.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"

int hasierakoPosizioaZirkulua = 0, ebentu;
float posizioaZirkuluaX = 0, posizioaZirkuluaY = 0;

EGOERA boss1(void) {
	EGOERA  egoera = BOSS1;
	int spriteAukeratu = 0, bizitzKopurua = 6, bossarenBizitzak = 20;
	int bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, inmortala = 0;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	int imageIdArbol, imageIdBala, imageIdBolaArbola, imageIdMapa;
	JOKO_ELEMENTUA jokalaria, tiroa, bolaArbola, boss1;
	POSIZIOA saguPos;

	imageIdMapa = irudiaKargatu(MAPA_BOSS1);
	irudiaMugitu(imageIdMapa, 0, 0);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);

	imageIdArbol = irudiaKargatu(JOKOA_PLAYER_IMAGE_ARBOL);
	imageIdBala = irudiaKargatu(TIROA_IMAGE);
	imageIdBolaArbola = irudiaKargatu(TIROA_BOSS1);
	boss1.pos.x = 275;
	boss1.pos.y = 195;
	bolaArbola.pos.x = 300;
	bolaArbola.pos.y = 200;
	jokalaria.pos.x = 32;
	jokalaria.pos.y = 230;
	tiroa.pos.x = 1000;
	tiroa.pos.y = 1000;

	audioInit();
	loadTheMusic(JOKOA_SOUND_BOSS1);
	playMusic();
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);
	irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y - 20);

	do {
		Sleep(10);
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		spriteAukeratu++;
		inmortala++;
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, boss1.pos, bossarenBizitzak);
		tiroa.pos = JOKALARIAREN_TIROA(jokalaria.pos, tiroa.pos, saguPos, boss1.pos);
		bolaArbola.pos = ZIRKULUA_JOKALARIARA_MUGITU(bolaArbola.pos, jokalaria.pos);
		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		pantailaGarbitu();
		if (inmortala >= 6 && bizitzKopurua >= 1) {
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA(bizitzKopurua, jokalaria.pos, bolaArbola.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			inmortala = 0;
		}	
		irudiaMugitu(imageIdBolaArbola, bolaArbola.pos.x, bolaArbola.pos.y);
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y - 20);
		irudiaMugitu(imageIdBala, tiroa.pos.x, tiroa.pos.y);
		irudiaMugitu(imageIdArbol, boss1.pos.x, boss1.pos.y);
		
		irudiakMarraztu();
		pantailaBerriztu();

		//egoera = JOKOA_egoera(jokalaria, bolaArbola, bizitzKopurua);
		egoera = JOKO_EGOERA_AZTERTU_BOSS1(bizitzKopurua, bossarenBizitzak);
	} while (egoera == BOSS1);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int bizitzKopurua) {
	EGOERA  ret = BOSS1;
	if (jokalaria.pos.x > oztopoa.pos.x - 32 && jokalaria.pos.x <oztopoa.pos.x - 10 && jokalaria.pos.y >oztopoa.pos.y - 20 && jokalaria.pos.y < oztopoa.pos.y + 20) {
		//ret = GALDU;
	}
	else if (jokalaria.pos.x > 900) {
		ret = IRABAZI;
	}
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	return ret;
}

EGOERA JOKO_EGOERA_AZTERTU_BOSS1(int bizitzKopurua, int bossarenBizitzak) {
	EGOERA ret = BOSS1;
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	else if (bossarenBizitzak <= 0) {
		ret = IRABAZI;
	}
	return ret;
}

POSIZIOA ZIRKULUA_JOKALARIARA_MUGITU(POSIZIOA posizioaPilota, POSIZIOA posizioaJokalaria) {
	float angelua;

	if (hasierakoPosizioaZirkulua == 0 || posizioaZirkuluaY == 0) {
		posizioaZirkuluaX = posizioaJokalaria.x - posizioaPilota.x + 10;
		posizioaZirkuluaY = posizioaJokalaria.y - posizioaPilota.y -10;
		hasierakoPosizioaZirkulua = 1;
	}
	if (posizioaZirkuluaY != 0 && posizioaZirkuluaX != 0) {
		angelua = (float)atan(posizioaZirkuluaX / posizioaZirkuluaY);
	}
	if ((posizioaZirkuluaX < 0 && posizioaZirkuluaY < 0) || (posizioaZirkuluaX > 0 && posizioaZirkuluaY < 0)) {
		posizioaPilota.x = posizioaPilota.x - 5 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y - 5 * (float)cos(angelua);
	}
	else if ((posizioaZirkuluaX > 0 && posizioaZirkuluaY > 0) || (posizioaZirkuluaX < 0 && posizioaZirkuluaY > 0)) {
		posizioaPilota.x = posizioaPilota.x + 5 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y + 5 * (float)cos(angelua);
	}
	if (posizioaPilota.x < -50 || posizioaPilota.x > 630 || posizioaPilota.y < -50 || posizioaPilota.y > 470) {
		posizioaPilota.x = 300;
		posizioaPilota.y = 200;
		hasierakoPosizioaZirkulua = 0;
	}
	return posizioaPilota;
}
