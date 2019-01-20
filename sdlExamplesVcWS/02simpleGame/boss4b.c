#include "jokalaria.h"
#include "globals.h"
#include "boss4b.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"

int hasierakoPosizioaZirkuluaBoss4 = 0;
float posizioaZirkuluaXBoss4 = 0, posizioaZirkuluaYBoss4 = 0;

EGOERA boss4b(void) {
	int mugitu = 0, tiempo = 0, spriteAukeratu = 0, bizitzKopurua = 6, inmortala = 0, inmortalakont = 0, bossarenBizitzak = 10;
	EGOERA  egoera = BOSS4B;
	int inmune = 80, inmuneKont = 0, hit = 0;
	int bizitz1, bizitz2, bizitz3, bizitz4, bizitz5;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	int hasierakoPosizioa = 0;
	int  imageIdBala, imageIdBalaBoss41, imageIdBalaBoss42, imageIdBalaBoss43, imageIdMapa;
	JOKO_ELEMENTUA jokalaria, bolaSua1, bolaSua2, bolaSua3, tiroa, boss4;
	POSIZIOA saguPos;

	imageIdMapa = irudiaKargatu(MAPA_BOSS4_2);
	irudiaMugitu(imageIdMapa, 0, 0);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);


	boss4.pos.x = 500;
	boss4.pos.y = 180;
	boss4.id = irudiaKargatu(JOKOA_IMG_BOSS);
	irudiaMugitu(boss4.id, (int)boss4.pos.x, (int)boss4.pos.y);
	imageIdBala = irudiaKargatu(TIROA_IMAGE);
	imageIdBalaBoss41 = irudiaKargatu(TIROA_IMG_BOSS);
	imageIdBalaBoss42 = irudiaKargatu(TIROA_IMG_BOSS);
	imageIdBalaBoss43 = irudiaKargatu(TIROA_IMG_BOSS);
	bolaSua1.pos.x = 600;
	bolaSua1.pos.y = 225;

	bolaSua2.pos.x = bolaSua1.pos.x + 30;
	bolaSua2.pos.y = bolaSua1.pos.y + 30;
	bolaSua3.pos.x = bolaSua1.pos.x - 30;
	bolaSua3.pos.y = bolaSua1.pos.y - 30;

	jokalaria.pos.x = 22;
	jokalaria.pos.y = 230;

	tiroa.pos.x = 1000;
	tiroa.pos.y = 1000;
	float x[10] = { 92, 72, 72, 212, 325, 402, 462, 462, 92, 200 };
	float y[10] = { 230, 50, 400, 100, 330, 310, 100, 240, 320, 300 };

	int minaId[10];
	for (int i = 0; i < 10; i++) {
		minaId[i] = irudiaKargatu(IMAGE_ARMA_PULPO2);
		irudiaMugitu(minaId[i], (int)x[i], (int)y[i]);
	}

	audioInit();
	loadTheMusic(JOKOA_SOUND_BOSS4B);
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

		
		if (inmuneKont == 0) {
			hit = JOKALARIAREN_BIZITZA_KENTZEA_BOSS4MINA(jokalaria.pos, bolaSua1.pos);
			hit += JOKALARIAREN_BIZITZA_KENTZEA_BOSS4MINA(jokalaria.pos, bolaSua2.pos);
			hit += JOKALARIAREN_BIZITZA_KENTZEA_BOSS4MINA(jokalaria.pos, bolaSua3.pos);
			if (hit > 0) {
				if (hit == 1) bizitzKopurua--;
				if (hit == 2) bizitzKopurua -= 2;
				if (hit == 3) bizitzKopurua -= 3;
				inmuneKont += inmune;
			}
			for (int i = 0; i < 10; i++) {
				if (jokalaria.pos.x > x[i] - 32 && jokalaria.pos.x < x[i] && jokalaria.pos.y > y[i] - 32 && jokalaria.pos.y < y[i]) {
					inmuneKont += inmune;//OBSTACULOS BOSS3B
					bizitzKopurua--;
				}
			}
		}
		else inmuneKont--;

		if (bizitzKopurua > 0) {
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
		}

		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, boss4.pos, bossarenBizitzak);

		bolaSua1.pos = ZIRKULUA_JOKALARIARA_MUGITU_BOSS4B(bolaSua1.pos, jokalaria.pos, boss4.pos);
		bolaSua2.pos.x = bolaSua1.pos.x + 30;
		bolaSua2.pos.y = bolaSua1.pos.y + 30;
		bolaSua3.pos.x = bolaSua1.pos.x + 30;
		bolaSua3.pos.y = bolaSua1.pos.y - 30;

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
			boss4.id = irudiaKargatu(JOKOA_IMG_BOSS2);
			irudiaMugitu(boss4.id, (int)boss4.pos.x, (int)boss4.pos.y - 20);
		}
		else {
			irudiaKendu(boss4.id);
			boss4.id = irudiaKargatu(JOKOA_IMG_BOSSDERECHA2);
			irudiaMugitu(boss4.id, (int)boss4.pos.x, (int)boss4.pos.y - 20);
		}

		irudiakMarraztu();
		pantailaBerriztu();

		egoera = JOKO_EGOERA_AZTERTU_BOSS4B(bizitzKopurua, bossarenBizitzak);


	} while (egoera == BOSS4B);
	
	for (int i = 0; i < 8; i++) {
		irudiaKendu(minaId[i]);
	}
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


EGOERA JOKO_EGOERA_AZTERTU_BOSS4B(int bizitzKopurua, int bossarenBizitzak) {
	EGOERA ret = BOSS4B;
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	else if (bossarenBizitzak <= 0) {
		ret = IRABAZI;
	}
	return ret;
}

POSIZIOA ZIRKULUA_JOKALARIARA_MUGITU_BOSS4B(POSIZIOA posizioaPilota, POSIZIOA posizioaJokalaria, POSIZIOA boss4) {
	float angelua;

	if (hasierakoPosizioaZirkuluaBoss4 == 0 || posizioaZirkuluaYBoss4 == 0) {
		posizioaZirkuluaXBoss4 = posizioaJokalaria.x - posizioaPilota.x;
		posizioaZirkuluaYBoss4 = posizioaJokalaria.y - posizioaPilota.y;
		hasierakoPosizioaZirkuluaBoss4 = 1;
	}
	if (posizioaZirkuluaYBoss4 != 0 && posizioaZirkuluaXBoss4 != 0) {
		angelua = (float)atan(posizioaZirkuluaXBoss4 / posizioaZirkuluaYBoss4);
	}
	if ((posizioaZirkuluaXBoss4 < 0 && posizioaZirkuluaYBoss4 < 0) || (posizioaZirkuluaXBoss4 > 0 && posizioaZirkuluaYBoss4 < 0)) {
		posizioaPilota.x = posizioaPilota.x - (float)5 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y - (float)5 * (float)cos(angelua);
	}
	else if ((posizioaZirkuluaXBoss4 > 0 && posizioaZirkuluaYBoss4 > 0) || (posizioaZirkuluaXBoss4 < 0 && posizioaZirkuluaYBoss4 > 0)) {
		posizioaPilota.x = posizioaPilota.x + (float)5 * (float)sin(angelua);
		posizioaPilota.y = posizioaPilota.y + (float)5 * (float)cos(angelua);
	}
	if (posizioaPilota.x < 0 || posizioaPilota.x > 640 || posizioaPilota.y < 0 || posizioaPilota.y > 480) {
		posizioaPilota.x = boss4.x + 50;
		posizioaPilota.y = boss4.y + 30;
		hasierakoPosizioaZirkuluaBoss4 = 0;
	}

	return posizioaPilota;
}
