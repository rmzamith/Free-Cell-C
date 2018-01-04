#if ! defined( EMBARALHAMENTO_ )
#define EMBARALHAMENTO_
/***************************************************************************
*
*  $MCD Módulo de definição: EMB  Embaralhar baralho de 52 cartas
*
*  Arquivo gerado:              EMBARALHAMENTO.h
*  Letras identificadoras:      EMB
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   31/mar/2009 início desenvolvimento
*
*  $ED Descrição do módulo
*     Devolve por referencia um vetor que representa um baralho de 52 cartas desordenado.
*	   Este vetor, será convertido depois, na função de distribuição, para uma lista, onde
*	   cada numero representara uma carta (Exemplo, numeros de 1 a 13 representam cartas de
*	   um nipe, numeros de 14 a 26 representam cartas de outro nipe, assim por diante).
*
***************************************************************************/
 
#if defined( EMBARALHAMENTO_OWN )
   #define EMBARALHAMENTO_EXT
#else
   #define EMBARALHAMENTO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/


/***********************************************************************
*
*  $TC Tipo de dados: EMB Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de embaralhamento
*
***********************************************************************/

   typedef enum {

         EMB_CondRetOK ,
               /* Concluiu corretamente */

	     EMB_CondRetFaltouMemoria
			   /* Faltou memória ao tentar criar o vetor do baralho */

   } EMB_tpCondRet ;


/***********************************************************************
*
*  $FC Função: EMB  &Embaralhar
*
*  $ED Descrição da função
*     Mistura os elementos de um vetor de caracteres com 52 elementos aleatoriamente.
*
*  $EP Parâmetros
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
*  $FC Função: EMB  &Imprimir
*
*  $ED Descrição da função
*     Imprime os elementos de um baralho representado por um vetor de caracteres.
*
*  $EP Parâmetros
*     pBaralho	-	ponteiro para um vetor que se deseja imprimir
*
*  $FV Valor retornado
*     EMB_CondRetOK	- se imprimiu sem erros
*
***********************************************************************/

   EMB_tpCondRet EMB_Imprimir( char * pBaralho ) ;

#undef EMBARALHAMENTO_EXT

/********** Fim do módulo de definição: EMB Embaralhar baralho de 52 cartas ******/

#else
#endif