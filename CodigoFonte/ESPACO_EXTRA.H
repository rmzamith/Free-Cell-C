#if ! defined( ESPACO_EXTRA_ )
#define ESPACO_EXTRA_
/***************************************************************************
*
*  $MCD Módulo de definição: EE  Espaço extra de um jogo de free cell
*
*  Arquivo gerado:              ESPACO_EXTRA.h
*  Letras identificadoras:      EE
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   15/abr/2009 início desenvolvimento
*
*  $ED Descrição do módulo
*     Manipula lista que representam 4 espaços extra de um jogo de
*	  paciencia Free Cell
*
*	  A lista começara inicialmente vazia, podendo ser adicionada a ela até 4
*	  elementos que representem as cartas. Para ser retirada uma carta, deve ser
*	  passado o indice do espaço extra que se deseja retirar a carta. Cada espaço
*	  extra é representado por um indice que vai de 0 a 3.
*
***************************************************************************/
 
#if defined( ESPACO_EXTRA_OWN )
   #define ESPACO_EXTRA_EXT
#else
   #define ESPACO_EXTRA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: EE Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de sequencia ordenada
*
***********************************************************************/

   typedef enum {

         EE_CondRetOK ,
               /* Concluiu corretamente */

	     EE_CondRetEspaçoOcupado ,
			  /* Espaço Extra esta ocupado */
	     
	     EE_CondRetVazio ,
			  /* Espaço extra não possui nenhuma carta */

	     EE_CondRetIndice ,
			  /* Indice de espaço extra não existe */
	     
	     EE_CondRetFaltouMemoria
		      /* Faltou memoria ao tentar inserir uma carta */

   } EE_tpCondRet ;


/***********************************************************************
*
*  $FC Função: EE  &Inserir em espaço extra
*
*  $ED Descrição da função
*     Insere uma carta em um espaço extra.
*
*  $EP Parâmetros
*     pEspacosExtras - ponteiro para a lista de espaços extra
*
*     pCarta  -  ponteiro para a carta que se deseja insereir.
*
*
*  $FV Valor retornado
*     EE_CondRetOK	- se inseriu a carta corretamente sem erros, no EE desejado.
*
*	  EE_EspaçoOcupado - Caso o EE em que se deseja inserir, ja esteja ocupado por
*					     outra carta.
*
***********************************************************************/

   EE_tpCondRet EE_Insereir( LIS_tppLista pEspaçosExtras , tppCarta pCarta ) ;


/***********************************************************************
*
*  $FC Função: EE  &Excluir carta de um espaço extra
*
*  $ED Descrição da função
*     Exclui a carta de um EE, afim de move-la para outro EE, pra uma SV
*	  ou uma SO. Ela deve receber um ponteiro de uma carta, para a carta não sumir do
*	  jogo, garantindo sempre, na função que vai move-la, que ela continuara no jogo.
*
*  $EP Parâmetros
*     pEspaçosExtras - ponteiro para a lista de espacos extras	
*
*	  pCarta - ponteiro para uma carta que tera o mesmo valor da carta do EE que
*			   se deseja excluir.
*
*	  inxEE - ndice de qual espaço extra se deseja excluir.
*
*  $FV Valor retornado
*     EE_CondRetOK	- se excluiu corretamente.
*
*	  EE_CondRetVazio - Caso o espaço extra no qual se deseja excluir nao possua 
*				 nenhuma carta
*
*	  EE_CondRetIndice - Caso seja fornecido um indice inexistente (indice vai de 0 a 3 ).
*
*	  EE_CondRetFaltouMemoria - Caso não tenha conseguido copiar a carta.
*
***********************************************************************/

   EE_tpCondRet EE_Excluir( LIS_tppLista pEspaçosExtras , tppCarta pCarta , int inxEE ) ;

/***********************************************************************
*
*  $FC Função: EE  &Imprimir cartas em espacos extras
*
*  $ED Descrição da função
*     Imprime as cartas de uma lista de espacos extras.
*
*  $EP Parâmetros
*     pEspaçosExtras - ponteiro para lista de espaços extras que se deseja imprimir
*
*  $FV Valor retornado
*     EE_CondRetOK	- se imprimiu corretamente.
*
***********************************************************************/

   EE_tpCondRet EE_Imprimir ( LIS_tppLista pEspaçosExtras ) ;


#undef ESPACO_EXTRA_EXT

/********** Fim do módulo de definição: EE Espaços extras ***********/

#else
#endif