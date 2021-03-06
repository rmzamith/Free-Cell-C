#if ! defined( BARALHO_ )
#define BARALHO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: BAR  Criar baralho em forma de lista
*
*  Arquivo gerado:              BARALHO.h
*  Letras identificadoras:      BAR
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   26/mai/2009 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo tem por fun��o receber um vetor representando uma sequencia de um
*	  baralho, e transformar essa sequencia em uma lista, para poder ser utilizada
*	  e distribuida no jogo.
*
***************************************************************************/
 
#if defined( BARALHO_OWN )
   #define BARALHO_EXT
#else
   #define BARALHO_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de baralho
*
***********************************************************************/

   typedef enum {

         BAR_CondRetOK ,
               /* Concluiu corretamente */

	     BAR_CondRetFaltouMemoria
			   /* Faltou mem�ria ao criar a lista do baralho */

   } BAR_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: BAR  &Criar lista representando baralho
*
*  $ED Descri��o da fun��o
*     Transforma um vetor que equivale a uma sequencia de cartas, em um baralho
*	  representado por uma lista.
*
*  $EP Par�metros
*     pBaralho - ponteiro para um vetor aonde esta a sequencia a ser transformada
*	  pListaBAR - ponteiro para a lista que representar� o baralho
*
*  $FV Valor retornado
*     BAR_CondRetOK	- se criou a lista corretamente sem erros
*
*	  BAR_CondRetFaltouMemoria - caso tenha faltado memoria ao criar a lista
*
***********************************************************************/

   BAR_tpCondRet BAR_CriarBaralho( char * pBaralho, LIS_tppLista pListaBAR ) ;


#undef BARALHO_EXT

/********** Fim do m�dulo de defini��o: BAR Criar baralho em forma de lista ******/

#else
#endif