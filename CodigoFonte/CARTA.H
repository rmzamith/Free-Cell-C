#if ! defined( CARTA_ )
#define CARTA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: Valor para uma carta
*
*  Autores: rmnm
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1		  rmnm  05/abr/2009 Cria��o da estrutura para cartas.
*
*  $ED Descri��o do m�dulo
*      Estrutura que representa uma carta
*      A esrtutura contem um valor para o naipe e um valor para o seu simbolo.
*
***************************************************************************/

#if defined( CARTA_OWN )
   #define CARTA_EXT
#else
   #define CARTA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um valor */

typedef struct tagCarta * tppCarta ;

/***********************************************************************
*
*  $TC Tipo de dados: Valor de uma Carta
*
* 
***********************************************************************/

	typedef struct	tagCarta {

		int  nipe ;
				/* Valor do nipe da carta */

		int  num ;
				/* Valor do simbolo da carta */

	}tpCarta;

#undef CARTA_EXT

/********** Fim do m�dulo de defini��o: valor para uma carta **********/

#else
#endif