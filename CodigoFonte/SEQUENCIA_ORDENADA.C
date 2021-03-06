/***************************************************************************
*  $MCI M�dulo de implementa��o: SO  Sequencia Ordenada de Free Cell
*
*  Arquivo gerado:              SEQUENCIA_ORDENADA.c
*  Letras identificadoras:      SO
*
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   15/abr/2009 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>

#include "CARTA.h"
#include "LISTA.h"

#define SEQUENCIA_ORDENADA_OWN
#include "SEQUENCIA_ORDENADA.h"
#undef SEQUENCIA_ORDENADA_OWN

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: SO  &Inserir em sequencia ordenada
*  ****/

	SO_tpCondRet SO_Inserir( LIS_tppLista pSequenciaOrdenada , tppCarta pCarta )
	{

		tpCarta * pCartaSO ;
		LIS_tpCondRet SO_CondRet ;

		IrFinalLista( pSequenciaOrdenada ) ;
		pCartaSO = LIS_ObterValor( pSequenciaOrdenada ) ;

		if( ( pCartaSO == NULL ) && ( pCarta->num != 1 ) )
		{
			return SO_CondRetForaDeSequencia ;
		}

		else if ( ( pCartaSO == NULL ) && ( pCarta->num == 1 ) )
		{
			SO_CondRet = LIS_InserirElementoApos( pSequenciaOrdenada, pCarta );
			if( SO_CondRet == LIS_CondRetOK )
			{
				return SO_CondRetOK ;
			}

			else
			{
				return SO_CondRetFaltouMemoria ;
			}
		}

		if ( pCartaSO->nipe != pCarta->nipe )
		{
			return SO_CondRetNipeDiferente ;
		}

		else if ( pCartaSO->num != ( pCarta->num - 1) )
		{
			return SO_CondRetForaDeSequencia ;
		}

		else
		{
			SO_CondRet = LIS_InserirElementoApos( pSequenciaOrdenada, pCarta );
			if( SO_CondRet == LIS_CondRetOK )
			{
				return SO_CondRetOK ;
			}

			else
			{
				return SO_CondRetFaltouMemoria ;
			}
		}
	} /* Fim fun��o: SO  &Inserir em sequencia ordenada */


/***************************************************************************
*
*  Fun��o: SO  &Verificar se SO esta completa
*  ****/

	SO_tpCondRet SO_VerificarCompletude( LIS_tppLista pSequenciaOrdenada )
	{
		
		tpCarta * pCartaSO ;
		
		IrFinalLista( pSequenciaOrdenada ) ;
		pCartaSO = LIS_ObterValor( pSequenciaOrdenada ) ;

		if ( pCartaSO == NULL )
		{
			return SO_CondRetNaoCompleta;
		}
		else if ( pCartaSO->num == 13 )
		{
			return SO_CondRetCompleta ;
		}
		else
		{
			return SO_CondRetNaoCompleta;
		}
	} /* Fim fun��o: SO  &Verificar se SO esta completa */

/***************************************************************************
*
*  Fun��o: SO &Imprimir SO
*******/

	SO_tpCondRet SO_Imprimir ( LIS_tppLista pSequenciaOrdenada )
	{
		tppCarta pCarta;

		IrFinalLista( pSequenciaOrdenada ) ;
		pCarta = LIS_ObterValor( pSequenciaOrdenada ) ;

		if ( pCarta == NULL )
		{
			printf("Vazia.\n\n") ;
			return SO_CondRetOK ;
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

		printf ("|\n\n");
		return SO_CondRetOK ;
	}

/********** Fim do m�dulo de implementa��o: SO Sequencia Ordenada de Free Cell **********/