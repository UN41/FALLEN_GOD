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
//#include "globals.h"//ebentu
int ebentu;

EGOERA boss3(void) {
	EGOERA  egoera = BOSS3;
	int spriteAukeratu = 0, bizitzKopurua = 6, bossarenBizitzak = 45;
	int bizitz1, bizitz2, bizitz3, bizitz4, bizitz5;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	JOKO_ELEMENTUA jokalaria, boss3, tiroa;//koord: ARMA_BIRAKARIA_MUGITU bueltatzen duen balioa.
	POSIZIOA koord, saguPos, armarenKokapena = { SCREEN_WIDTH / 2 - 17, SCREEN_HEIGHT / 2 - 18 };
	float rad = 400, anguloa = 0, abiaduraBoss = 0.0115;//armaBirakaria-ren erradioa eta biraketaren hasierako anguloa
	int imageIdMapa, imageIdBala;
	int kont = 0, moteldu = 1, norabidea = 1;//moteldu: Arma-ren abiadura motelago doa 'moteldu' handiagoekin.
	int hit1 = 0, hit2 = 0, inmuneKont = 0, inmune = 80;

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
	boss3.id = irudiaKargatu(JOKOA_BOSS_IMAGE_PULPO);
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);

	irudiaMugitu(imageIdMapa, 0, 0);
	irudiaMugitu(boss3.id, boss3.pos.x, boss3.pos.y);
	irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y - 20);
	srand(time(NULL));
	do {
		Sleep(2);
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		tiroa.pos = JOKALARIAREN_TIROA(jokalaria.pos, tiroa.pos, saguPos, boss3.pos);
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, boss3.pos, bossarenBizitzak);
		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		spriteAukeratu++;
		//-------------------------------------------------------------------------------------
		koord = ARMA_BIRAKARIA_MUGITU(koord, armarenKokapena, anguloa, rad);
		norabidea = norabideaRandomizatu(norabidea);
		if (norabidea == 1) anguloa -= abiaduraBoss;
		else anguloa += abiaduraBoss;
		//-------------------------------------------------------------------------------------
		pantailaGarbitu();
		if (bizitzKopurua > 0) {
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
		}
		if (inmuneKont == 0) {
			hit1 = kolisioaBoss3(jokalaria.pos, armarenKokapena, koord, anguloa, rad, bizitzKopurua);
			if (hit1 == 1) {
				inmuneKont += inmune;//Jokalariak kolpe bat jasotzen duenean denbora tarte batean inmunea izango da.
				bizitzKopurua--;
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
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}

POSIZIOA ARMA_BIRAKARIA_MUGITU(POSIZIOA posizioa, POSIZIOA pos0, float anguloa, float rad) {
	posizioa.x = rad * cos(anguloa) + pos0.x;
	posizioa.y = rad * sin(anguloa) + pos0.y;
	/*erradioa, anguloa eta zentroa-ren posizioa(pos0) emanda zirkunferentzia baten puntuak ematen ditu.
	Funtzioa askotan deitzen angulo ezberdinekin zirkunferentzia bat sortuko da pos0-ren inguruan posizioa puntuekin.*/

	return posizioa;
}

int norabideaRandomizatu(int norabidea) {
	if (rand() % 500 == 300) {//0-500 arteko zenbaki ausazkoa 300 bada norabidea aldatzen du.
		norabidea *= -1;
	}
	return norabidea;
}

void armaMarraztu(POSIZIOA kokapena, POSIZIOA koord, float anguloa, float luzera) {
	POSIZIOA posizioa;
	int zirkuloDiametro = 26, j = luzera, zirkuloKopurua = luzera / zirkuloDiametro;
	int imageIdArmaArray[20];
	for (int i = 0; i < zirkuloKopurua; i++) {
		int imageIdArma = irudiaKargatu(IMAGE_ARMA_PULPO);
		imageIdArmaArray[i] = imageIdArma;
		j -= zirkuloDiametro;
		posizioa = ARMA_BIRAKARIA_MUGITU(koord, kokapena, anguloa, luzera - j);
		irudiaMugitu(imageIdArmaArray[i], posizioa.x, posizioa.y);
	}
	irudiakMarraztu();
	for (int i = 0; i < zirkuloKopurua; i++) {
		irudiaKendu(imageIdArmaArray[i]);
	}
}

int kolisioaBoss3(POSIZIOA jokalaria, POSIZIOA Kokapena, POSIZIOA koord, float anguloa, float luzera) {
	POSIZIOA kolisioa;
	int x, y, xJokalari = (int)jokalaria.x, yJokalari = (int)jokalaria.y;
	for (int i = 0; i < luzera; i++) {
		kolisioa = ARMA_BIRAKARIA_MUGITU(koord, Kokapena, anguloa, i);
		x = (int)kolisioa.x;
		y = (int)kolisioa.y;
		if (xJokalari > x - 32 && xJokalari < x && yJokalari > y - 32 && yJokalari < y + 50) {
			return 1;
		}
	}
}

EGOERA JOKO_EGOERA_AZTERTU_BOSS3(int bizitzKopurua, int bossarenBizitzak) {
	EGOERA ret = BOSS3;
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	else if (bossarenBizitzak <= 0) {
		ret = IRABAZI;
	}
	return ret;
}