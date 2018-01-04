/***************************************************************************
*  $MCI Módulo de implementação: EMB  Embaralhar baralho de 52 cartas
*
*  Arquivo gerado:              EMBARALHAMENTO.c
*  Letras identificadoras:      EMB
*
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   04/abr/2009 início desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   <time.h>
#include   <malloc.h>

#define    MAX_BARALHO	52

#define EMBARALHAMENTO_OWN
#include "EMBARALHAMENTO.h"
#undef EMBARALHAMENTO_OWN

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: EMB  &Embaralhar
*  ****/

	EMB_tpCondRet EMB_Embaralhar ( char * pBaralho )
	
	{

		int indBaralho ;
		int indIncluir = 0 ;
		int	FlagCartaIgual ;
		char cCarta ;
		char * pBaralhoAUX ;

		srand(time(NULL));

		pBaralhoAUX = ( char * ) malloc ( MAX_BARALHO * sizeof( char ) ) ;
		
		if ( pBaralhoAUX == NULL )
		{
			return EMB_CondRetFaltouMemoria;
		}

		for ( indBaralho = 0 ; indBaralho < MAX_BARALHO ; indBaralho++ )
		{
			pBaralhoAUX[indBaralho] = 0 ;
		}

		while ( indIncluir < MAX_BARALHO )
		{

			FlagCartaIgual = 0 ;
			cCarta = (rand()%( MAX_BARALHO + 1 )) ;

			for ( indBaralho = 0 ; indBaralho < MAX_BARALHO ; indBaralho++ )
			{
				if ( cCarta == pBaralhoAUX[indBaralho] )
				{
					FlagCartaIgual = 1;
					break ;
				}
			}

			if ( FlagCartaIgual == 0 )
			{
				pBaralhoAUX[indIncluir] = cCarta ;
				indIncluir++ ;
			}
		}

		for ( indBaralho = 0; indBaralho < MAX_BARALHO ; indBaralho++ )
		{
			pBaralho[indBaralho] = pBaralhoAUX[indBaralho] ;
		}

		return EMB_CondRetOK ;

	} /* Fim função: EMB  &Embaralhar */

/***************************************************************************
*
*  Função: EMB  &Imprimir
*  ****/

	EMB_tpCondRet EMB_Imprimir ( char * pBaralho )
	{

		int inx;

		for( inx = 0; inx < MAX_BARALHO; inx++ )
		{
			printf("%d, ", pBaralho[inx]);
		}
		printf("\n");

		return EMB_CondRetOK;

	}

/********** Fim do módulo de implementação: EMB Embaralhar baralho de 52 cartas **********/
