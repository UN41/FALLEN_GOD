#include "jokalaria.h"
//#include "globals.h"
#include "boss2b.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"

int hasierakoPosizioaSugeaA = 0, hasierakoPosizioaSugeaB = 0, ebentu;
float posizioaSugeaAX = 0, posizioaSugeaAY = 0, posizioaSugeaBX = 0, posizioaSugeaBY = 0;
int paretenKontraKontA = 0, paretenKontraKontB = 0;


POSIZIOA BOSSA_JOKALARIARA_JARRAITU(POSIZIOA posizioaBossA, POSIZIOA posizioaJokalaria) {
	float angelua;

	if (paretenKontraKontA < 5) {
		if (hasierakoPosizioaSugeaA == 0) {
			posizioaSugeaAX = posizioaJokalaria.x - posizioaBossA.x;
			posizioaSugeaAY = posizioaJokalaria.y - posizioaBossA.y;
			hasierakoPosizioaSugeaA = 1;
		}
		if (posizioaSugeaAY != 0 && posizioaSugeaAX != 0) {
			angelua = (float)atan(posizioaSugeaAX / posizioaSugeaAY);
		}
		if ((posizioaSugeaAX < 0 && posizioaSugeaAY < 0) || (posizioaSugeaAX > 0 && posizioaSugeaAY < 0)) {
			posizioaBossA.x = posizioaBossA.x - (float)4 * sin(angelua);
			posizioaBossA.y = posizioaBossA.y - (float)4 * cos(angelua);
		}
		else if ((posizioaSugeaAX > 0 && posizioaSugeaAY > 0) || (posizioaSugeaAX < 0 && posizioaSugeaAY > 0)) {
			posizioaBossA.x = posizioaBossA.x + (float)4 * sin(angelua);
			posizioaBossA.y = posizioaBossA.y + (float)4 * cos(angelua);
		}
		if (posizioaBossA.x < -15 || posizioaBossA.x > 560 || posizioaBossA.y < -12 || posizioaBossA.y > 390) {
			hasierakoPosizioaSugeaA = 0;
			paretenKontraKontA++;
		}
	}
	return posizioaBossA;
}

POSIZIOA BOSSB_JOKALARIARA_JARRAITU(POSIZIOA posizioaBossB, POSIZIOA posizioaJokalaria) {
	float angelua;

	if (paretenKontraKontB < 5) {
		if (hasierakoPosizioaSugeaB == 0) {
			posizioaSugeaBX = posizioaJokalaria.x - posizioaBossB.x;
			posizioaSugeaBY = posizioaJokalaria.y - posizioaBossB.y;
			hasierakoPosizioaSugeaB = 1;
		}
		if (posizioaSugeaBY != 0 && posizioaSugeaBX != 0) {
			angelua = (float)atan(posizioaSugeaBX / posizioaSugeaBY);
		}
		if ((posizioaSugeaBX < 0 && posizioaSugeaBY < 0) || (posizioaSugeaBX > 0 && posizioaSugeaBY < 0)) {
			posizioaBossB.x = posizioaBossB.x - (float)3 * sin(angelua);
			posizioaBossB.y = posizioaBossB.y - (float)3 * cos(angelua);
		}
		else if ((posizioaSugeaBX > 0 && posizioaSugeaBY > 0) || (posizioaSugeaBX < 0 && posizioaSugeaBY > 0)) {
			posizioaBossB.x = posizioaBossB.x + (float)3 * sin(angelua);
			posizioaBossB.y = posizioaBossB.y + (float)3 * cos(angelua);
		}
		if (posizioaBossB.x < -15 || posizioaBossB.x > 560 || posizioaBossB.y < -12 || posizioaBossB.y > 390) {
			hasierakoPosizioaSugeaB = 0;
			paretenKontraKontB++;
		}
	}
	return posizioaBossB;
}

EGOERA boss2b(void)
{
	EGOERA  egoera = BOSS2B;
	int spriteAukeratu = 0, bizitzKopurua = 6;
	int hasierakoPosizioa = 0;
	int imageIdSerpiente1, imageIdSerpiente2, imageIdBala, imageIdMapa, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, inmortala = 0;
	int bizitzaKendu[5] = { 1,1,1,1,1 };
	JOKO_ELEMENTUA bossA, bossB, jokalaria, tiroa;
	POSIZIOA saguPos;
	int denboraA = 0, denboraB = 0;
	int bossarenBizitzak = 15;

	imageIdMapa = irudiaKargatu(MAPA_BOSS2);

	bizitz1 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz2 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz3 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz4 = irudiaKargatu(PLAYER_HEART_IMAGE);
	bizitz5 = irudiaKargatu(PLAYER_HEART_IMAGE);

	imageIdSerpiente1 = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE1BOLA);
	imageIdSerpiente2 = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE2BOLA);
	irudiaMugitu(imageIdSerpiente1, 275, 180);
	irudiaMugitu(imageIdSerpiente2, 275, 180);
	imageIdBala = irudiaKargatu(TIROA_IMAGE);
	bossA.pos.x = 500;
	bossA.pos.y = 225;
	bossB.pos.x = 500;
	bossB.pos.y = 125;
	jokalaria.pos.x = 20;
	jokalaria.pos.y = 350;

	tiroa.pos.x = 1000;
	tiroa.pos.y = 1000;

	audioInit();
	loadTheMusic(JOKOA_SOUND_BOSS2);
	playMusic();
	jokalaria.id = irudiaKargatu(JOKOA_PLAYER_IMAGE_DELANTE1);
	irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y - 20);

	do {
		Sleep(8);
		saguPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		spriteAukeratu++;
		inmortala++;

		tiroa.pos = JOKALARIAREN_TIROA(jokalaria.pos, tiroa.pos, saguPos, bossA.pos);

		bossA.pos = BOSSA_JOKALARIARA_JARRAITU(bossA.pos, jokalaria.pos);
		bossB.pos = BOSSB_JOKALARIARA_JARRAITU(bossB.pos, jokalaria.pos);
		bossarenBizitzak = BOSSAREN_BIZITZA(tiroa.pos, bossA.pos, bossarenBizitzak);
		jokalaria.pos = JOKALARIAREN_MUGIMENDUA(jokalaria.pos);
		jokalaria.id = JOKALARIAREN_IRUDIA(jokalaria.id, spriteAukeratu);
		imageIdSerpiente1 = SUGEAREN_IRUDIAA(imageIdSerpiente1);
		imageIdSerpiente2 = SUGEAREN_IRUDIAB(imageIdSerpiente2);

		if (inmortala >= 20 && bizitzKopurua >= 1) {
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA_SUGEA(bizitzKopurua, jokalaria.pos, bossA.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			bizitzKopurua = JOKALARIAREN_BIZITZA_KENTZEA_SUGEA(bizitzKopurua, jokalaria.pos, bossB.pos);
			bizitzKopurua = JOKALARIAREN_BIZITZA(bizitzKopurua, bizitz1, bizitz2, bizitz3, bizitz4, bizitz5, bizitzaKendu);
			inmortala = 0;
		}
		if (denboraA >= 800) {
			imageIdSerpiente1 = SUGEA_GELDIRIKA(imageIdSerpiente1);
			denboraA = 0;
			paretenKontraKontA = 0;
		}
		if (denboraB >= 200) {
			imageIdSerpiente2 = SUGEA_GELDIRIKB(imageIdSerpiente2);
			denboraB = 0;
			paretenKontraKontB = 0;
		}

		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y - 20);
		irudiaMugitu(imageIdBala, tiroa.pos.x, tiroa.pos.y);
		irudiaMugitu(imageIdSerpiente1, bossA.pos.x, bossA.pos.y);
		irudiaMugitu(imageIdSerpiente2, bossB.pos.x, bossB.pos.y);

		irudiakMarraztu();
		pantailaBerriztu();
		denboraA++;
		denboraB++;
		egoera = JOKO_EGOERA_AZTERTU_BOSS2B(bizitzKopurua, bossarenBizitzak);
	} while (egoera == BOSS2B);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}


int SUGEAREN_IRUDIAA(int irudiaA) {
	if (paretenKontraKontA >= 5) {
		irudiaKendu(irudiaA);
		irudiaA = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE1);
		paretenKontraKontA = 6;
	}
	return irudiaA;
}

int SUGEAREN_IRUDIAB(int irudiaB) {
	if (paretenKontraKontB >= 5) {
		irudiaKendu(irudiaB);
		irudiaB = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE2);
		paretenKontraKontB = 6;
	}
	return irudiaB;
}

int SUGEA_GELDIRIKA(int irudiaA) {
	int denboraGeldirik;

	if (paretenKontraKontA == 6) {
		irudiaKendu(irudiaA);
		irudiaA = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE1BOLA);
	}
	return irudiaA;
}
int SUGEA_GELDIRIKB(int irudiaB) {
	int denboraGeldirik;

	if (paretenKontraKontA == 6) {
		irudiaKendu(irudiaB);
		irudiaB = irudiaKargatu(JOKOA_PLAYER_IMAGE_SERPIENTE2BOLA);
	}
	return irudiaB;
}


EGOERA JOKO_EGOERA_AZTERTU_BOSS2B(int bizitzKopurua, int bossarenBizitzak) {
	EGOERA ret = BOSS2B;
	if (bizitzKopurua <= 0) {
		ret = GALDU;
	}
	else if (bossarenBizitzak <= 0) {
		ret = IRABAZI;
	}
	return ret;
}
