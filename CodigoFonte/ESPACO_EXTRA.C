/***************************************************************************
*  $MCI M�dulo de implementa��o: EE  Espacos extras de Free Cell
*
*  Arquivo gerado:              ESPACO_EXTRA.c
*  Letras identificadoras:      EE
*
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   18/abr/2009 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <malloc.h>

#include "CARTA.h"
#include "LISTA.h"

#define ESPACO_EXTRA_OWN
#include "ESPACO_EXTRA.h"
#undef ESPACO_EXTRA_OWN

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: EE  &Inserir em espa�o extra
*  ****/

	EE_tpCondRet EE_Inserir( LIS_tppLista pEspa�osExtras , tppCarta pCarta )
	{
		LIS_tpCondRet CondRetEE ;
		int numElem ;

		IrFinalLista( pEspa�osExtras ) ;
		numElem = LIS_ObterNumElem( pEspa�osExtras );
		if ( numElem >= 4 )
		{
			return EE_CondRetEspa�oOcupado ;
		}
		else
		{
			CondRetEE = LIS_InserirElementoApos( pEspa�osExtras, pCarta );
			if( CondRetEE == LIS_CondRetOK )
			{
				return EE_CondRetOK ;
			}

			else
			{
				return EE_CondRetFaltouMemoria ;
			}
		}

	} /* Fim fun��o: EE  &Inserir em espaco extra */

/***************************************************************************
*
*  Fun��o: EE  &Excluir carta em espa�o extra
*  ****/

	EE_tpCondRet EE_Excluir( LIS_tppLista pEspa�osExtras , tppCarta pCarta , int inxEE )
	{

		LIS_tpCondRet CondRetEE ;
		tppCarta pCartaEE ;

		IrInicioLista( pEspa�osExtras );

		if ( (inxEE > 3) || (inxEE < 0) )
		{
			return EE_CondRetIndice ;
		}

		CondRetEE = LIS_AvancarElementoCorrente ( pEspa�osExtras, inxEE );

		if ( CondRetEE == ( LIS_CondRetFimLista || LIS_CondRetListaVazia ))
		{
			return EE_CondRetVazio ;
		}
		
		pCartaEE = LIS_ObterValor( pEspa�osExtras );

		if ( ( inxEE == 0) && ( pCartaEE == NULL ) )
		{
			return EE_CondRetVazio ;
		}
		
		pCarta->num = pCartaEE->num ;
		pCarta->nipe = pCartaEE->nipe ;

		LIS_ExcluirElemento( pEspa�osExtras ) ;
			
		return EE_CondRetOK ;

	} /* Fim fun��o: EE  &Excluir carta em espaco extra */

/***************************************************************************
*
*  Fun��o: EE  &Imprimir espa�os extras
*  ****/

	EE_tpCondRet EE_Imprimir ( LIS_tppLista pEspa�osExtras )
	{
		LIS_tpCondRet CondRet = -1;
		tppCarta pCarta ;
		int EE_Corr = 0;

		IrInicioLista( pEspa�osExtras ) ;

		while ( CondRet != LIS_CondRetFimLista )
		{
			pCarta = LIS_ObterValor ( pEspa�osExtras ) ;
			if ( pCarta == NULL )
			{	
				printf("Espacos Extras Vazios.\n ") ;
				return EE_CondRetOK ;
			}
			printf("Espaco Extra %d | Carta: ", EE_Corr);
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

			CondRet = LIS_AvancarElementoCorrente( pEspa�osExtras, 1 );
			EE_Corr++ ;
		}
		printf("\n");

		return EE_CondRetOK ;

	} /* Fim fun��o: EE  &Imprimir espacos extras */



/********** Fim do m�dulo de implementa��o: EE Espa�os extras de Free Cell **********/