#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "boss3.h"
#include "irudiakEtaSoinuak.h"
#include "jokalaria.h"
#include "globals.h"//ebentu
int ebentu;

EGOERA boss3b(void) {
	EGOERA  egoera = BOSS3;
	int spriteAukeratu = 0, bizitzKopurua = 6, bossarenBizitzak = 35;
	int bizitz1, bizitz2, bizitz3, bizitz4, bizitz5;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	JOKO_ELEMENTUA jokalaria, boss3, tiroa;//koord: ARMA_BIRAKARIA_MUGITU bueltatzen duen balioa.
	POSIZIOA koord, saguPos, armarenKokapena = { SCREEN_WIDTH / 2 - 17, SCREEN_HEIGHT / 2 - 18 };
	float rad = 400, anguloa = 0, abiaduraBoss = 0.01;//armaBirakaria-ren erradioa eta biraketaren hasierako anguloa
	int imageIdMapa, imageIdBala;
	int kont = 0, norabidea = 1;
	int hit1 = 0, inmuneKont = 0, inmune = 80;

	boss3.pos.x = SCREEN_WIDTH / 2 - 48;
	boss3.pos.y = SCREEN_HEIGHT / 2 - 48;
	jokalaria.pos.x = 32;
	jokalaria.pos.y = 230;
	tiroa.pos.x = 1000;
	tiroa.pos.y = 1000;
	koord.x = 0;
	koord.y = 0;

	audioInit();
	loadTheMusic(JOKOA_SOUND_BOSS3);
	playMusic();

	imageIdMapa = irudiaKargatu(MAPA_BOSS3);
	imageIdBala = irudiaKargatu(TIROA_IMAGE);
	boss3.id = irudiaKargatu(JOKOA_BOSS_IMAGE_PULPO2);
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);

	float x[8] = { 92, 72, 72, 212, 325, 402, 462, 462 };
	float y[8] = { 230, 50, 400, 100, 330, 310, 100, 240 };
	int minaId[8];
	for (int i = 0; i < 8; i++) {
		minaId[i] = irudiaKargatu(IMAGE_ARMA_PULPO2);
		irudiaMugitu(minaId[i], x[i], y[i]);
	}

	irudiaMugitu(imageIdMapa, 0, 0);
	irudiaMugitu(boss3.id, boss3.pos.x, boss3.pos.y);
	irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y - 20);

	srand(time(NULL));
	do {
		Sleep(2);
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		spriteAukeratu++;
		tiroa.pos = JOKALARIAREN_TIROA(jokalaria.pos, tiroa.pos, saguPos, boss3.pos);
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, boss3.pos, bossarenBizitzak);
		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		koord = ARMA_BIRAKARIA_MUGITU(koord, armarenKokapena, anguloa, rad);
		norabidea = norabideaRandomizatu(norabidea);
		if (norabidea == 1) anguloa -= abiaduraBoss;
		else anguloa += abiaduraBoss;

		if (bizitzKopurua > 0) {
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
		}
		if (inmuneKont == 0) {
			hit1 = kolisioaBoss3(jokalaria.pos, armarenKokapena, koord, anguloa, rad, bizitzKopurua);
			if (hit1 == 1) {
				inmuneKont += inmune;//Jokalariak kolpe bat jasotzen duenean denbora tarte batean inmunea izango da.
				bizitzKopurua--;
			}
			for (int i = 0; i < 8; i++) {//Minak
				if (jokalaria.pos.x > x[i] - 32 && jokalaria.pos.x < x[i] && jokalaria.pos.y > y[i] - 32 && jokalaria.pos.y < y[i]) {
					inmuneKont += inmune;
					bizitzKopurua--;
				}
			}
		}
		else inmuneKont--;
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y - 20);
		irudiaMugitu(imageIdBala, tiroa.pos.x, tiroa.pos.y);
		armaMarraztu(armarenKokapena, koord, anguloa, rad);
		pantailaBerriztu();
		egoera = JOKO_EGOERA_AZTERTU_BOSS3(bizitzKopurua, bossarenBizitzak);
	} while (egoera == BOSS3);
	irudiaKendu(jokalaria.id);
	
	for (int i = 0; i < 8; i++) {
		irudiaKendu(minaId[i]);
	}

	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}