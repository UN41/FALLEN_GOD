#include "game02.h"
#include "jokalaria.h"
#include "globals.h"
#include "boss1.h"
#include "boss1b.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"


void jokoaAurkeztu(void)
{
	int ebentu = 0;

	sarreraMezuaIdatzi();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);

	pantailaGarbitu();
	pantailaBerriztu();
}

void sarreraMezuaIdatzi()
{
	pantailaGarbitu();
	textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
	pantailaBerriztu();
}


int  jokoAmaierakoa(EGOERA egoera)
{
	int ebentu = 0, id;
	int idAudioGame;

	loadTheMusic(BUKAERA_SOUND_1);
	if (egoera == IRABAZI) {
		idAudioGame = loadSound(JOKOA_SOUND_WIN);
		playSound(idAudioGame);
	}
	else {
		idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
		playSound(idAudioGame);
	}
	id = BUKAERA_irudiaBistaratu();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while ((ebentu != TECLA_RETURN) && (ebentu != SAGU_BOTOIA_ESKUMA));
	audioTerminate();
	irudiaKendu(id);
	return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int BUKAERA_irudiaBistaratu() {
	int id = -1;
	id = irudiaKargatu(BUKAERA_IMAGE);
	irudiaMugitu(id, 200, 200);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}


