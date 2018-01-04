#if ! defined( CARTA_ )
#define CARTA_
/***************************************************************************
*
*  $MCD Módulo de definição: Valor para uma carta
*
*  Autores: rmnm
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1		  rmnm  05/abr/2009 Criação da estrutura para cartas.
*
*  $ED Descrição do módulo
*      Estrutura que representa uma carta
*      A esrtutura contem um valor para o naipe e um valor para o seu simbolo.
*
***************************************************************************/

#if defined( CARTA_OWN )
   #define CARTA_EXT
#else
   #define CARTA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um valor */

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

/********** Fim do módulo de definição: valor para uma carta **********/

#else
#endif