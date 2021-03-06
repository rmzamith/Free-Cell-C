#if ! defined( ESPACO_EXTRA_ )
#define ESPACO_EXTRA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: EE  Espa�o extra de um jogo de free cell
*
*  Arquivo gerado:              ESPACO_EXTRA.h
*  Letras identificadoras:      EE
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   15/abr/2009 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Manipula lista que representam 4 espa�os extra de um jogo de
*	  paciencia Free Cell
*
*	  A lista come�ara inicialmente vazia, podendo ser adicionada a ela at� 4
*	  elementos que representem as cartas. Para ser retirada uma carta, deve ser
*	  passado o indice do espa�o extra que se deseja retirar a carta. Cada espa�o
*	  extra � representado por um indice que vai de 0 a 3.
*
***************************************************************************/
 
#if defined( ESPACO_EXTRA_OWN )
   #define ESPACO_EXTRA_EXT
#else
   #define ESPACO_EXTRA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: EE Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de sequencia ordenada
*
***********************************************************************/

   typedef enum {

         EE_CondRetOK ,
               /* Concluiu corretamente */

	     EE_CondRetEspa�oOcupado ,
			  /* Espa�o Extra esta ocupado */
	     
	     EE_CondRetVazio ,
			  /* Espa�o extra n�o possui nenhuma carta */

	     EE_CondRetIndice ,
			  /* Indice de espa�o extra n�o existe */
	     
	     EE_CondRetFaltouMemoria
		      /* Faltou memoria ao tentar inserir uma carta */

   } EE_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: EE  &Inserir em espa�o extra
*
*  $ED Descri��o da fun��o
*     Insere uma carta em um espa�o extra.
*
*  $EP Par�metros
*     pEspacosExtras - ponteiro para a lista de espa�os extra
*
*     pCarta  -  ponteiro para a carta que se deseja insereir.
*
*
*  $FV Valor retornado
*     EE_CondRetOK	- se inseriu a carta corretamente sem erros, no EE desejado.
*
*	  EE_Espa�oOcupado - Caso o EE em que se deseja inserir, ja esteja ocupado por
*					     outra carta.
*
***********************************************************************/

   EE_tpCondRet EE_Insereir( LIS_tppLista pEspa�osExtras , tppCarta pCarta ) ;


/***********************************************************************
*
*  $FC Fun��o: EE  &Excluir carta de um espa�o extra
*
*  $ED Descri��o da fun��o
*     Exclui a carta de um EE, afim de move-la para outro EE, pra uma SV
*	  ou uma SO. Ela deve receber um ponteiro de uma carta, para a carta n�o sumir do
*	  jogo, garantindo sempre, na fun��o que vai move-la, que ela continuara no jogo.
*
*  $EP Par�metros
*     pEspa�osExtras - ponteiro para a lista de espacos extras	
*
*	  pCarta - ponteiro para uma carta que tera o mesmo valor da carta do EE que
*			   se deseja excluir.
*
*	  inxEE - ndice de qual espa�o extra se deseja excluir.
*
*  $FV Valor retornado
*     EE_CondRetOK	- se excluiu corretamente.
*
*	  EE_CondRetVazio - Caso o espa�o extra no qual se deseja excluir nao possua 
*				 nenhuma carta
*
*	  EE_CondRetIndice - Caso seja fornecido um indice inexistente (indice vai de 0 a 3 ).
*
*	  EE_CondRetFaltouMemoria - Caso n�o tenha conseguido copiar a carta.
*
***********************************************************************/

   EE_tpCondRet EE_Excluir( LIS_tppLista pEspa�osExtras , tppCarta pCarta , int inxEE ) ;

/***********************************************************************
*
*  $FC Fun��o: EE  &Imprimir cartas em espacos extras
*
*  $ED Descri��o da fun��o
*     Imprime as cartas de uma lista de espacos extras.
*
*  $EP Par�metros
*     pEspa�osExtras - ponteiro para lista de espa�os extras que se deseja imprimir
*
*  $FV Valor retornado
*     EE_CondRetOK	- se imprimiu corretamente.
*
***********************************************************************/

   EE_tpCondRet EE_Imprimir ( LIS_tppLista pEspa�osExtras ) ;


#undef ESPACO_EXTRA_EXT

/********** Fim do m�dulo de defini��o: EE Espa�os extras ***********/

#else
#endif