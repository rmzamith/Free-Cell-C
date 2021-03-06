#if ! defined( SEQUENCIA_ORDENADA_ )
#define SEQUENCIA_ORDENADA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: SO  Sequencia ordenada de um jogo de free cell
*
*  Arquivo gerado:              SEQUENCIA_ORDENADA.h
*  Letras identificadoras:      SO
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   15/abr/2009 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Manipula listas que representam as sequencias ordenadas de um jogo de
*	  paciencia Free Cell
*
*	  Cada lista come�a vazia, e o primeiro elemento a ser inserido ser� uma
*	  carta "�s" de um determinado nipe, e as cartas colocadas na sequ�ncia ser�o 
*	  do mesmo nipe do "�s" inserido na lista, e estar�o em ordem crescente. O
*	  modulo tamb�m analisa se uma determinada SO est� completa.
*
***************************************************************************/
 
#if defined( SEQUENCIA_ORDENADA_OWN )
   #define SEQUENCIA_ORDENADA_EXT
#else
   #define SEQUENCIA_ORDENADA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: SO Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de sequencia ordenada
*
***********************************************************************/

   typedef enum {

         SO_CondRetOK ,
               /* Concluiu corretamente */

	     SO_CondRetNipeDiferente ,
			  /* Carta n�o � do mesmo nipe do resto da SO */
	     
	     SO_CondRetForaDeSequencia ,
		      /* Carta n�o � a proxima na sequencia para ser inserida */

		 SO_CondRetNaoCompleta ,
			  /* Sequencia ordenada n�o est� completa */
		 
		 SO_CondRetCompleta ,
			  /* Sequencia ordenada est� completa */

		 SO_CondRetFaltouMemoria
		      /* Faltou memoria ao tentar inserir uma carta */

   } SO_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: SO  &Inserir em sequencia ordenada
*
*  $ED Descri��o da fun��o
*     Insere uma carta em uma sequencia ordenada, respeitando as regras do jogo.
*
*  $EP Par�metros
*     pSequenciaOrdenada - ponteiro para sequencia ordenada a qual se deseja inserir
*                          uma carta.
*     pCarta  -  ponteiro para a carta que se deseja insereir.
*
*  $FV Valor retornado
*     SO_CondRetOK	- se inseriu a carta corretamente sem erros
*
*	  SO_CondRetNipeDiferente - Caso a carta a ser inserida na SO n�o seja do mesmo
*								nipe das outras.
*
*	  SO_CondRetForaDeSequencia - Caso a carta a ser inserida seja do msm nipe, mas
*                                 n�o seja a proxima na sequencia que deveria ser 
*								  inserida. Essa condi��o de retorno � valida tamb�m
*								  ao tentar inserir uma carta diferente de un "�s" em
*								  uma sequencia ordenada vazia.
*
***********************************************************************/

   SO_tpCondRet SO_Insereir( LIS_tppLista pSequenciaOrdenada , tppCarta pCarta ) ;


/***********************************************************************
*
*  $FC Fun��o: SO  &Verificar se SO esta completa
*
*  $ED Descri��o da fun��o
*     Verifica se uma determinada sequencia ordenada est� completa.
*
*  $EP Par�metros
*     pSequenciaOrdenada - ponteiro para sequencia ordenada a qual se deseja fazer
*                          a verifica��o.
*
*  $FV Valor retornado
*     SO_CondRetOK	- se SO est� completa.
*
*	  SO_CondRetNaoCompleta - Caso ainda faltem cartas a serem inseridas em SO
*							  para ela ficar completa.
*
***********************************************************************/

   SO_tpCondRet SO_VerificarCompletude( LIS_tppLista pSequenciaOrdenada ) ;


/***********************************************************************
*
*  $FC Fun��o: SO  &Imprimir sequencia ordenada
*
*  $ED Descri��o da fun��o
*     Imprime a carta do topo de uma sequencia ordenada.
*
*  $EP Par�metros
*     pSequenciaOrdenada - ponteiro para sequencia ordenada na qual se deseja imprimir
*
*  $FV Valor retornado
*     SO_CondRetOK	- se imprimiu corretamente.
*
***********************************************************************/

   SO_tpCondRet SO_Imprimir ( LIS_tppLista pSequenciaOrdenada ) ;

#undef SEQUENCIA_ORDENADA_EXT

/********** Fim do m�dulo de defini��o: SO Sequencia ordenada *********/

#else
#endif