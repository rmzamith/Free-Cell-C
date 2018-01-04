#if ! defined( SEQUENCIA_ORDENADA_ )
#define SEQUENCIA_ORDENADA_
/***************************************************************************
*
*  $MCD Módulo de definição: SO  Sequencia ordenada de um jogo de free cell
*
*  Arquivo gerado:              SEQUENCIA_ORDENADA.h
*  Letras identificadoras:      SO
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   15/abr/2009 início desenvolvimento
*
*  $ED Descrição do módulo
*     Manipula listas que representam as sequencias ordenadas de um jogo de
*	  paciencia Free Cell
*
*	  Cada lista começa vazia, e o primeiro elemento a ser inserido será uma
*	  carta "Ás" de um determinado nipe, e as cartas colocadas na sequência serão 
*	  do mesmo nipe do "Ás" inserido na lista, e estarão em ordem crescente. O
*	  modulo também analisa se uma determinada SO está completa.
*
***************************************************************************/
 
#if defined( SEQUENCIA_ORDENADA_OWN )
   #define SEQUENCIA_ORDENADA_EXT
#else
   #define SEQUENCIA_ORDENADA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: SO Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de sequencia ordenada
*
***********************************************************************/

   typedef enum {

         SO_CondRetOK ,
               /* Concluiu corretamente */

	     SO_CondRetNipeDiferente ,
			  /* Carta não é do mesmo nipe do resto da SO */
	     
	     SO_CondRetForaDeSequencia ,
		      /* Carta não é a proxima na sequencia para ser inserida */

		 SO_CondRetNaoCompleta ,
			  /* Sequencia ordenada não está completa */
		 
		 SO_CondRetCompleta ,
			  /* Sequencia ordenada está completa */

		 SO_CondRetFaltouMemoria
		      /* Faltou memoria ao tentar inserir uma carta */

   } SO_tpCondRet ;


/***********************************************************************
*
*  $FC Função: SO  &Inserir em sequencia ordenada
*
*  $ED Descrição da função
*     Insere uma carta em uma sequencia ordenada, respeitando as regras do jogo.
*
*  $EP Parâmetros
*     pSequenciaOrdenada - ponteiro para sequencia ordenada a qual se deseja inserir
*                          uma carta.
*     pCarta  -  ponteiro para a carta que se deseja insereir.
*
*  $FV Valor retornado
*     SO_CondRetOK	- se inseriu a carta corretamente sem erros
*
*	  SO_CondRetNipeDiferente - Caso a carta a ser inserida na SO não seja do mesmo
*								nipe das outras.
*
*	  SO_CondRetForaDeSequencia - Caso a carta a ser inserida seja do msm nipe, mas
*                                 não seja a proxima na sequencia que deveria ser 
*								  inserida. Essa condição de retorno é valida também
*								  ao tentar inserir uma carta diferente de un "Ás" em
*								  uma sequencia ordenada vazia.
*
***********************************************************************/

   SO_tpCondRet SO_Insereir( LIS_tppLista pSequenciaOrdenada , tppCarta pCarta ) ;


/***********************************************************************
*
*  $FC Função: SO  &Verificar se SO esta completa
*
*  $ED Descrição da função
*     Verifica se uma determinada sequencia ordenada está completa.
*
*  $EP Parâmetros
*     pSequenciaOrdenada - ponteiro para sequencia ordenada a qual se deseja fazer
*                          a verificação.
*
*  $FV Valor retornado
*     SO_CondRetOK	- se SO está completa.
*
*	  SO_CondRetNaoCompleta - Caso ainda faltem cartas a serem inseridas em SO
*							  para ela ficar completa.
*
***********************************************************************/

   SO_tpCondRet SO_VerificarCompletude( LIS_tppLista pSequenciaOrdenada ) ;


/***********************************************************************
*
*  $FC Função: SO  &Imprimir sequencia ordenada
*
*  $ED Descrição da função
*     Imprime a carta do topo de uma sequencia ordenada.
*
*  $EP Parâmetros
*     pSequenciaOrdenada - ponteiro para sequencia ordenada na qual se deseja imprimir
*
*  $FV Valor retornado
*     SO_CondRetOK	- se imprimiu corretamente.
*
***********************************************************************/

   SO_tpCondRet SO_Imprimir ( LIS_tppLista pSequenciaOrdenada ) ;

#undef SEQUENCIA_ORDENADA_EXT

/********** Fim do módulo de definição: SO Sequencia ordenada *********/

#else
#endif