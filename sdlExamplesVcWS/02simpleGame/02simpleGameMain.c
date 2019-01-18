/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "game02.h"


int main(int argc, char * str[]) {
  int jarraitu = 0;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }
  textuaGaitu(); 
  do
  {
	menu();
	dialogoIntro();
	do {
		dialogoArbol1();
		egoera = boss1();
		if (egoera == GALDU) {
			gameOver();
		}
	} while (egoera == GALDU);
	do {
		dialogoSugea1();
		egoera = boss2();
		if (egoera == GALDU) {
			gameOver();
		}
	} while (egoera == GALDU);
	do {
		dialogoPulpo1();
		egoera = boss3();
		if (egoera == GALDU) {
			gameOver();
		}
	} while (egoera == GALDU);
	do {
		dialogoTitan1();
		egoera = boss4();
		if (egoera == GALDU) {
			gameOver();
		}
	} while (egoera == GALDU);
	do {
		dialogoArbol2();
		egoera = boss1b();
		if (egoera == GALDU) {
			gameOver();
		}
	} while (egoera == GALDU);
	do {
		dialogoSugea2();
		egoera = boss2b();
	} while (egoera == GALDU);
	do {
		dialogoPulpo2A();
		egoera = boss3b();
		if (egoera == GALDU) {
			gameOver();
		}
	} while (egoera == GALDU);
	dialogoPulpo2B();
	do {
		dialogoTitan2A();
		egoera = boss4b();
		if (egoera == GALDU) {
			gameOver();
		}
	} while (egoera == GALDU);
	dialogoTitan2B();
  //  jarraitu = jokoAmaierakoa(egoera);
  } while (jarraitu);
  sgItxi();
  return 0;
}

