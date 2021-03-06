#if ! defined( EMBARALHAMENTO_ )
#define EMBARALHAMENTO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: EMB  Embaralhar baralho de 52 cartas
*
*  Arquivo gerado:              EMBARALHAMENTO.h
*  Letras identificadoras:      EMB
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   31/mar/2009 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Devolve por referencia um vetor que representa um baralho de 52 cartas desordenado.
*	   Este vetor, ser� convertido depois, na fun��o de distribui��o, para uma lista, onde
*	   cada numero representara uma carta (Exemplo, numeros de 1 a 13 representam cartas de
*	   um nipe, numeros de 14 a 26 representam cartas de outro nipe, assim por diante).
*
***************************************************************************/
 
#if defined( EMBARALHAMENTO_OWN )
   #define EMBARALHAMENTO_EXT
#else
   #define EMBARALHAMENTO_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/


/***********************************************************************
*
*  $TC Tipo de dados: EMB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de embaralhamento
*
***********************************************************************/

   typedef enum {

         EMB_CondRetOK ,
               /* Concluiu corretamente */

	     EMB_CondRetFaltouMemoria
			   /* Faltou mem�ria ao tentar criar o vetor do baralho */

   } EMB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: EMB  &Embaralhar
*
*  $ED Descri��o da fun��o
*     Mistura os elementos de um vetor de caracteres com 52 elementos aleatoriamente.
*
*  $EP Par�metros
*     pBaralho	-	ponteiro para um vetor aonde sera armazenado
*					o baralho embaralhado
*
*  $FV Valor retornado
*     EMB_CondRetOK	- se embaralho corretamente sem erros
*
*	  EMB_CondRetFaltouMemoria - caso tenha faltado memoria ao alocar o
								 vetor do baralho.
*
***********************************************************************/

   EMB_tpCondRet EMB_Embaralhar( char * pBaralho ) ;


/***********************************************************************
*
*  $FC Fun��o: EMB  &Imprimir
*
*  $ED Descri��o da fun��o
*     Imprime os elementos de um baralho representado por um vetor de caracteres.
*
*  $EP Par�metros
*     pBaralho	-	ponteiro para um vetor que se deseja imprimir
*
*  $FV Valor retornado
*     EMB_CondRetOK	- se imprimiu sem erros
*
***********************************************************************/

   EMB_tpCondRet EMB_Imprimir( char * pBaralho ) ;

#undef EMBARALHAMENTO_EXT

/********** Fim do m�dulo de defini��o: EMB Embaralhar baralho de 52 cartas ******/

#else
#endif