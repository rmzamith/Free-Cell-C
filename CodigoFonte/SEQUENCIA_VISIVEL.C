/***************************************************************************
*  $MCI M�dulo de implementa��o: SV  Sequencia Visivel de Free Cell
*
*  Arquivo gerado:              SEQUENCIA_VISIVEL.c
*  Letras identificadoras:      SV
*
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   16/abr/2009 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   <malloc.h>

#include "CARTA.h"
#include "LISTA.h"

#define SEQUENCIA_VISIVEL_OWN
#include "SEQUENCIA_VISIVEL.h"
#undef SEQUENCIA_VISIVEL_OWN

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: SV  &Inserir em sequencia ordenada
*  ****/

	SV_tpCondRet SV_Inserir( LIS_tppLista pSequenciaVisivel , tppCarta pCarta )
	{

		tpCarta * pCartaSV ;
		LIS_tpCondRet SV_CondRet ;

		IrFinalLista( pSequenciaVisivel ) ;
		pCartaSV = LIS_ObterValor( pSequenciaVisivel ) ;

		if ( pCartaSV == NULL )
		{
			SV_CondRet = LIS_InserirElementoApos( pSequenciaVisivel, pCarta );
			
			if( SV_CondRet == LIS_CondRetOK )
			{
				return SV_CondRetOK ;
			}

			else
			{
				return SV_CondRetFaltouMemoria ;
			}
		}
		else if ( (( pCartaSV->nipe == 1 ) ||  ( pCartaSV->nipe == 2 ) ) &&
				  (( pCarta->nipe == 3 )   ||  ( pCarta->nipe == 4 )) )
		{
			if ( (pCartaSV->num - 1) == pCarta->num )
			{
				SV_CondRet = LIS_InserirElementoApos( pSequenciaVisivel, pCarta );
				
				if( SV_CondRet == LIS_CondRetOK )
				{
					return SV_CondRetOK ;
				}

				else
				{
					return SV_CondRetFaltouMemoria ;
				}
			}
			
			else
			{
				return SV_CondRetForaDeSequencia ;
			}
		}
		else if ( (( pCartaSV->nipe == 3 ) ||  ( pCartaSV->nipe == 4 ) ) &&
				  (( pCarta->nipe == 1 )   ||  ( pCarta->nipe == 2 )) )
		{
			if ( (pCartaSV->num - 1) == pCarta->num )
			{
				SV_CondRet = LIS_InserirElementoApos( pSequenciaVisivel, pCarta );
				
				if( SV_CondRet == LIS_CondRetOK )
				{
					return SV_CondRetOK ;
				}

				else
				{
					return SV_CondRetFaltouMemoria ;
				}
			}
			
			else
			{
				return SV_CondRetForaDeSequencia ;
			}
		}
		else
		{
			return SV_CondRetCorIgual ;
		}
	} /* Fim fun��o: SV  &Inserir em sequencia visivel */

/***************************************************************************
*
*  Fun��o: SV  &Excluir em sequencia visivel
*******/

	SV_tpCondRet SV_Excluir( LIS_tppLista pSequenciaVisivel , tppCarta pCarta )
	{

		tppCarta pCartaSV ;

		IrFinalLista( pSequenciaVisivel ) ;
		pCartaSV = LIS_ObterValor( pSequenciaVisivel ) ;

		if( pCartaSV != NULL)
		{

			pCarta->num = pCartaSV->num ;
			pCarta->nipe = pCartaSV->nipe ;

			LIS_ExcluirElemento(pSequenciaVisivel);

			return SV_CondRetOK  ;
		}

		else
		{
			free (pCarta);
			return SV_CondRetVazia ;
		}

	} /* Fim fun��o: SV  &Excluir em sequencia visivel */

/***************************************************************************
*
*  Fun��o: SV  &Imprimir SV
*******/

	SV_tpCondRet SV_Imprimir ( LIS_tppLista pSequenciaVisivel )
	{
		LIS_tpCondRet CondRet = -1;
		tppCarta pCarta ;

		IrInicioLista( pSequenciaVisivel ) ;

		while ( CondRet != LIS_CondRetFimLista )
		{
			pCarta = LIS_ObterValor ( pSequenciaVisivel ) ;
			if ( pCarta == NULL )
			{	
				printf("Vazia.\n\n") ;
				return SV_CondRetOK ;
			}
			printf(" | Carta: ");
			if ( pCarta->num == 1 )
			{
				printf(" %c " , 'A');
			}
			else if ( pCarta->num == 11 )
			{
				printf(" %c ", 'J');
			}
			else if ( pCarta->num == 12 )
			{
				printf(" %c ", 'Q');
			}
			else if ( pCarta->num == 13 )
			{
				printf(" %c ", 'K');
			}
			else
			{
				printf(" %d ", pCarta->num );
			}

			printf( " Nipe: ");
			
			if ( pCarta->nipe == 1 )
			{
				printf (" %c ", 'O' );
			}
			else if ( pCarta->nipe == 2 )
			{
				printf (" %c ", 'C' );
			}
			else if ( pCarta->nipe == 3 )
			{
				printf (" %c ", 'P' );
			}
			else
			{
				printf (" %c ", 'E' );
			}
			printf ("|\n");

			CondRet = LIS_AvancarElementoCorrente( pSequenciaVisivel, 1 );
		}
		printf("\n");

		return SV_CondRetOK ;

	} /* Fim fun��o: SV  &Imprimir sequencia visivel */

/********** Fim do m�dulo de implementa��o: SV Sequencia visivel de Free Cell **********/