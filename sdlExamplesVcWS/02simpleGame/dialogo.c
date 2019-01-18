#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "ourTypes.h"
#include <stdio.h>
#include <windows.h>
#include "irudiakEtaSoinuak.h"
#include "dialogo.h"

//Menu//
void menu(void) {
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_MENU);
	playMusic();

	imageIdDialogo = irudiaKargatu(MENU_IMAGE_START);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);

	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Game Over//

void gameOver(void) {
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_GAMEOVER);
	playMusic();

	imageIdDialogo = irudiaKargatu(GAMEOVER_IMAGE);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);

	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Intro//

void dialogoIntro(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_1);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_5);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_6);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_7);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_8);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_9);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_10);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_11);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_INTRO_12);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Arbol1//

void dialogoArbol1(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL1_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL1_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL1_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL1_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL1_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL1_5);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL1_6);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	
	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);

	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Sugea1//

void dialogoSugea1(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA1_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA1_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA1_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA1_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA1_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA1_5);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);

	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Pulpo1//

void dialogoPulpo1(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_5);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_6);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_7);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO1_8);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);

	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Titan1//

void dialogoTitan1(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_5);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_6);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_7);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN1_8);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);

	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);
	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Arbol2//

void dialogoArbol2(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL2_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL2_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL2_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_ARBOL2_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);

	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Sugea2//

void dialogoSugea2(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA2_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA2_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA2_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA2_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_SUGEA2_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);

	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Pulpo2A//

void dialogoPulpo2A(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_5);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);

	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Pulpo2B//

void dialogoPulpo2B(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_6);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_PULPO2_7);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);

	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}


//Dialogo Titan2A//

void dialogoTitan2A(void)
{
	int ebentuDialogo = 0, imageIdDialogo;
	
	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_0);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_1);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_2);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_3);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_4);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_5);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_6);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_7);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_8);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_9);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);

	imageIdDialogo = irudiaKargatu(IMAGE_PRESSW);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_w);
	irudiaKendu(imageIdDialogo);
	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}

//Dialogo Titan2B//

void dialogoTitan2B(void)
{
	int ebentuDialogo = 0, imageIdDialogo;

	audioInit();
	loadTheMusic(JOKOA_SOUND_DIALOGO);
	playMusic();

	pantailaGarbitu();
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_10);
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_11);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_12);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_13);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_14);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_15);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);
	imageIdDialogo = irudiaKargatu(DIALOGO_TITAN2_16);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentuDialogo = ebentuaJasoGertatuBada();
	} while (ebentuDialogo != TECLA_RETURN);
	irudiaKendu(imageIdDialogo);


	audioTerminate();

	pantailaGarbitu();
	pantailaBerriztu();
}