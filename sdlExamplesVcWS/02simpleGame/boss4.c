#include "jokalaria.h"
#include "globals.h"
#include "boss4.h"
#include "boss4b.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"


int hasierakoPosizioaZirkulua4 = 0;
float posizioaZirkuluaX4 = 0, posizioaZirkuluaY4 = 0;

EGOERA boss4(void)
{

	int mugitu = 0, tiempo = 0, spriteAukeratu = 0, bizitzKopurua = 6, inmortala = 0, bossarenBizitzak = 20;
	EGOERA  egoera = BOSS4;
	int bizitz1, bizitz2, bizitz3, bizitz4, bizitz5;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	int hasierakoPosizioa = 0;
	int  imageIdBala, imageIdBalaBoss41, imageIdBalaBoss42, imageIdBalaBoss43, imageIdMapa;
	JOKO_ELEMENTUA jokalaria, bolaSua1, bolaSua2, bolaSua3, tiroa, boss4;
	POSIZIOA saguPos;

	imageIdMapa = irudiaKargatu(MAPA_BOSS4);
	irudiaMugitu(imageIdMapa, 0, 0);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);

	imageIdBalaBoss41 = irudiaKargatu(TIROA_IMG_BOSS);
	imageIdBalaBoss42 = irudiaKargatu(TIROA_IMG_BOSS);
	imageIdBalaBoss43 = irudiaKargatu(TIROA_IMG_BOSS);


	boss4.pos.x = 500;
	boss4.pos.y = 180;
	boss4.id = irudiaKargatu(JOKOA_IMG_BOSS);
	irudiaMugitu(boss4.id, (int)boss4.pos.x, (int)boss4.pos.y);
	imageIdBala = irudiaKargatu(TIROA_IMAGE);

	bolaSua1.pos.x = 600;
	bolaSua1.pos.y = 225;
	bolaSua2.pos.x = bolaSua1.pos.x + 30;
	bolaSua2.pos.y = bolaSua1.pos.y + 30;
	bolaSua3.pos.x = bolaSua1.pos.x - 30;
	bolaSua3.pos.y = bolaSua1.pos.y - 30;

	jokalaria.pos.x = 32;
	jokalaria.pos.y = 230;

	tiroa.pos.x = 1000;
	tiroa.pos.y = 1000;

	audioInit();
	loadTheMusic(JOKOA_SOUND_BOSS4A);
	playMusic();
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);
	irudiaMugitu(jokalaria.id, (int)jokalaria.pos.x, (int)jokalaria.pos.y - 20);

	do {
		Sleep(9);
		spriteAukeratu++;
		inmortala++;

		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		tiroa.pos = JOKALARIAREN_TIROA(jokalaria.pos, tiroa.pos, saguPos, boss4.pos);

		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		pantailaGarbitu();
		bolaSua1.pos = ZIRKULUA_JOKALARIARA_MUGITU_BOSS4(bolaSua1.pos, jokalaria.pos, boss4.pos);
		bolaSua2.pos.x = bolaSua1.pos.x + 30;
		bolaSua2.pos.y = bolaSua1.pos.y + 30;
		bolaSua3.pos.x = bolaSua1.pos.x + 30;
		bolaSua3.pos.y = bolaSua1.pos.y - 30;

		if (inmortala >= 10 && bizitzKopurua >= 1) {
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA_BOSS4(bizitzKopurua, jokalaria.pos, bolaSua1.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			inmortala = 0;
		}
		if (inmortala >= 10 && bizitzKopurua >= 1) {
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA_BOSS4(bizitzKopurua, jokalaria.pos, bolaSua2.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			inmortala = 0;
		}
		if (inmortala >= 10 && bizitzKopurua >= 1) {
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA_BOSS4(bizitzKopurua, jokalaria.pos, bolaSua3.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			inmortala = 0;
		}
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, boss4.pos, bossarenBizitzak);


		irudiaMugitu(jokalaria.id, (int)jokalaria.pos.x, (int)jokalaria.pos.y);
		irudiaMugitu(imageIdBala, (int)tiroa.pos.x, (int)tiroa.pos.y);
		irudiaMugitu(imageIdBalaBoss41, (int)bolaSua1.pos.x, (int)bolaSua1.pos.y);
		irudiaMugitu(imageIdBalaBoss42, (int)bolaSua2.pos.x, (int)bolaSua2.pos.y);
		irudiaMugitu(imageIdBalaBoss43, (int)bolaSua3.pos.x, (int)bolaSua3.pos.y);

		tiempo++;



		if (tiempo >= 2700)tiempo = 0;

		if (tiempo > 400 && tiempo < 600)
		{
			boss4.pos.y = boss4.pos.y + 1;
		}
		if (tiempo > 650 && tiempo < 1150)
		{
			boss4.pos.x = boss4.pos.x - 1;
		}
		if (tiempo > 1250 && tiempo < 1600)
		{
			boss4.pos.y = boss4.pos.y - 1;
		}
		if (tiempo > 1800 && tiempo < 2300)
		{
			boss4.pos.x = boss4.pos.x + 1;
		}
		if (tiempo > 2500 && tiempo < 2650)
		{
			boss4.pos.y = boss4.pos.y + 1;
		}
		if (boss4.pos.x > jokalaria.pos.x) {
			irudiaKendu(boss4.id);
			boss4.id = irudiaKargatu(JOKOA_IMG_BOSS);
			irudiaMugitu(boss4.id, (int)boss4.pos.x, (int)boss4.pos.y - 20);

		}
		else {
			irudiaKendu(boss4.id);
			boss4.id = irudiaKargatu(JOKOA_IMG_BOSSDERECHA);
			irudiaMugitu(boss4.id, (int)boss4.pos.x, (int)boss4.pos.y - 20);
		}

		irudiakMarraztu();
		pantailaBerriztu();

		egoera = JOKO_EGOERA_AZTERTU_BOSS4(bizitzKopurua, bossarenBizitzak);
	} while (egoera == BOSS4);
	irudiaKendu(imageIdBalaBoss41);
	irudiaKendu(imageIdBalaBoss42);
	irudiaKendu(imageIdBalaBoss43);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}

EGOERA JOKO_EGOERA_AZTERTU_BOSS4(int bizitzKopurua, int bossarenBizitzak) {
	EGOERA ret = BOSS4;
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	else if (bossarenBizitzak <= 0) {
		ret = IRABAZI;
	}
	return ret;
}

POSIZIOA ZIRKULUA_JOKALARIARA_MUGITU_BOSS4(POSIZIOA posizioaPilota, POSIZIOA posizioaJokalaria, POSIZIOA boss4) {
	float angelua;

	if (hasierakoPosizioaZirkulua4 == 0 || posizioaZirkuluaY4 == 0) {
		posizioaZirkuluaX4 = posizioaJokalaria.x - posizioaPilota.x;
		posizioaZirkuluaY4 = posizioaJokalaria.y - posizioaPilota.y;
		hasierakoPosizioaZirkulua4 = 1;
	}

	if (posizioaZirkuluaY4 != 0 && posizioaZirkuluaX4 != 0) {
		angelua = (float)atan(posizioaZirkuluaX4 / posizioaZirkuluaY4);
	}

	if ((posizioaZirkuluaX4 < 0 && posizioaZirkuluaY4 < 0) || (posizioaZirkuluaX4 > 0 && posizioaZirkuluaY4 < 0)) {
		posizioaPilota.x = posizioaPilota.x - 5 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y - 5 * (float)cos(angelua);
	}
	else if ((posizioaZirkuluaX4 > 0 && posizioaZirkuluaY4 > 0) || (posizioaZirkuluaX4 < 0 && posizioaZirkuluaY4 > 0)) {
		posizioaPilota.x = posizioaPilota.x + 5 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y + 5 * (float)cos(angelua);
	}

	if (posizioaPilota.x < 0 || posizioaPilota.x > 640 || posizioaPilota.y < 0 || posizioaPilota.y > 480 || ((posizioaPilota.x < posizioaJokalaria.x + 10 && posizioaPilota.x > posizioaJokalaria.x - 10) && (posizioaPilota.y < posizioaJokalaria.y + 20 && posizioaPilota.y > posizioaJokalaria.y - 10))) {

		posizioaPilota.x = boss4.x + 50;
		posizioaPilota.y = boss4.y + 30;
		hasierakoPosizioaZirkulua4 = 0;
	}


	return posizioaPilota;
}
