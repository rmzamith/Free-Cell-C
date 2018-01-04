#if ! defined( BARALHO_ )
#define BARALHO_
/***************************************************************************
*
*  $MCD Módulo de definição: BAR  Criar baralho em forma de lista
*
*  Arquivo gerado:              BARALHO.h
*  Letras identificadoras:      BAR
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   26/mai/2009 início desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo tem por função receber um vetor representando uma sequencia de um
*	  baralho, e transformar essa sequencia em uma lista, para poder ser utilizada
*	  e distribuida no jogo.
*
***************************************************************************/
 
#if defined( BARALHO_OWN )
   #define BARALHO_EXT
#else
   #define BARALHO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de baralho
*
***********************************************************************/

   typedef enum {

         BAR_CondRetOK ,
               /* Concluiu corretamente */

	     BAR_CondRetFaltouMemoria
			   /* Faltou memória ao criar a lista do baralho */

   } BAR_tpCondRet ;


/***********************************************************************
*
*  $FC Função: BAR  &Criar lista representando baralho
*
*  $ED Descrição da função
*     Transforma um vetor que equivale a uma sequencia de cartas, em um baralho
*	  representado por uma lista.
*
*  $EP Parâmetros
*     pBaralho - ponteiro para um vetor aonde esta a sequencia a ser transformada
*	  pListaBAR - ponteiro para a lista que representará o baralho
*
*  $FV Valor retornado
*     BAR_CondRetOK	- se criou a lista corretamente sem erros
*
*	  BAR_CondRetFaltouMemoria - caso tenha faltado memoria ao criar a lista
*
***********************************************************************/

   BAR_tpCondRet BAR_CriarBaralho( char * pBaralho, LIS_tppLista pListaBAR ) ;


#undef BARALHO_EXT

/********** Fim do módulo de definição: BAR Criar baralho em forma de lista ******/

#else
#endif