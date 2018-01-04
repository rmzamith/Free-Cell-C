#if ! defined( SEQUENCIA_VISIVEL_ )
#define SEQUENCIA_VISIVEL_
/***************************************************************************
*
*  $MCD Módulo de definição: SV  Sequencia visivel de um jogo de free cell
*
*  Arquivo gerado:              SEQUENCIA_VISIVEL.h
*  Letras identificadoras:      SV
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   15/abr/2009 início desenvolvimento
*
*  $ED Descrição do módulo
*     Manipula listas que representam as sequencias visiveis de um jogo de
*	  paciencia Free Cell
*
*	  Cada lista tem o estado inicial com uma sequencia embaralhada de cartas.
*	  As sequencias visiveis podem ficar vazias no decorrer do jogo. Nesse caso qlqr carta pode
*	  inserida em SV. Ao ser inserida uma carta ela deve ser sucessora, e ter cor 
*	  contraria a do topo de SV. So se pode inserir uma carta no topo de SV.
*
*	  Este modulo é capaz de inserir ou retirar uma carta do topo de uma SV.
*
***************************************************************************/
 
#if defined( SEQUENCIA_VISIVEL_OWN )
   #define SEQUENCIA_VISIVEL_EXT
#else
   #define SEQUENCIA_VISIVEL_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: SV Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de sequencia ordenada
*
***********************************************************************/

   typedef enum {

         SV_CondRetOK ,
               /* Concluiu corretamente */

	     SV_CondRetCorIgual ,
			  /* Carta não é de cor diferente da carta do topo da SV */
	     
	     SV_CondRetForaDeSequencia ,
		      /* Carta não é a proxima na sequencia para ser inserida */
	     
	     SV_CondRetVazia ,
			  /* Sequencia visivel esta vazia */
	     
	     SV_CondRetFaltouMemoria
			 /* Faltou memoria ao tentar inserir uma carta */

   } SV_tpCondRet ;

/***********************************************************************
*
*  $FC Função: SV  &Inserir em sequencia visivel
*
*  $ED Descrição da função
*     Insere uma carta em uma sequencia visivel, respeitando as regras do jogo.
*
*  $EP Parâmetros
*     pSequenciaVisivel - ponteiro para sequencia ordenada a qual se deseja inserir
*                          uma carta.
*     pCarta  -  ponteiro para a carta que se deseja insereir.
*
*  $FV Valor retornado
*     SV_CondRetOK	- se inseriu a carta corretamente sem erros
*
*	  SV_CondRetCorIgual - Caso a carta a ser inserida na SO não seja de cor contraria
*						   da do topo.
*
*	  SV_CondRetForaDeSequencia - Caso a carta a ser inserida seja de cor diferente, mas
*                                 não seja a proxima na sequencia que deveria ser 
*								  inserida.
*
***********************************************************************/

   SV_tpCondRet SV_Insereir( LIS_tppLista pSequenciaVisivel , tppCarta pCarta ) ;


/***********************************************************************
*
*  $FC Função: SV  &Excluir carta do topo em sequencia visivel
*
*  $ED Descrição da função
*     Exclui a carta do topo da SV, afim de move-la para outra SV, pra um espaço extra
*	  ou uma SO. Ela deve receber um ponteiro de uma carta, para a carta não sumir do
*	  jogo, garantindo sempre, na função que vai move-la, que ela continuara no jogo.
*
*  $EP Parâmetros
*     pSequenciaVisivel - ponteiro para sequencia visivel na qual se deseja tirar a
*						  carta do topo.
*
*	  pCarta - ponteiro para uma carta, que na função terá o mesmo valor da carta que
*			   está no topo da SV.
*
*  $FV Valor retornado
*     SV_CondRetOK	- se excluiu corretamente.
*
*	  SV_Vazia - Caso a sequencia visivel não possua nenhuma carta
*
*	  SV_CondRetFaltouMemoria - Caso não tenha conseguido copiar a carta.
*
***********************************************************************/

   SV_tpCondRet SV_Excluir( LIS_tppLista pSequenciaVisivel , tppCarta pCarta ) ;


/***********************************************************************
*
*  $FC Função: SV  &Imprimir sequencia visivel
*
*  $ED Descrição da função
*     Imprime todas as cartas de uma dada sequencia visivel.
*
*  $EP Parâmetros
*     pSequenciaVisivel - ponteiro para sequencia visivel na qual se deseja imprimir
*
*  $FV Valor retornado
*     SV_CondRetOK	- se imprimiu corretamente.
*
***********************************************************************/

   SV_tpCondRet SV_Imprimir ( LIS_tppLista pSequenciaVisivel ) ;


#undef SEQUENCIA_VISIVEL_EXT

/********** Fim do módulo de definição: SV Sequencia visivel ******/

#else
#endif