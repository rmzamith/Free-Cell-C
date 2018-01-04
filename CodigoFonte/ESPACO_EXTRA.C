/***************************************************************************
*  $MCI Módulo de implementação: EE  Espacos extras de Free Cell
*
*  Arquivo gerado:              ESPACO_EXTRA.c
*  Letras identificadoras:      EE
*
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   18/abr/2009 início desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <malloc.h>

#include "CARTA.h"
#include "LISTA.h"

#define ESPACO_EXTRA_OWN
#include "ESPACO_EXTRA.h"
#undef ESPACO_EXTRA_OWN

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: EE  &Inserir em espaço extra
*  ****/

	EE_tpCondRet EE_Inserir( LIS_tppLista pEspaçosExtras , tppCarta pCarta )
	{
		LIS_tpCondRet CondRetEE ;
		int numElem ;

		IrFinalLista( pEspaçosExtras ) ;
		numElem = LIS_ObterNumElem( pEspaçosExtras );
		if ( numElem >= 4 )
		{
			return EE_CondRetEspaçoOcupado ;
		}
		else
		{
			CondRetEE = LIS_InserirElementoApos( pEspaçosExtras, pCarta );
			if( CondRetEE == LIS_CondRetOK )
			{
				return EE_CondRetOK ;
			}

			else
			{
				return EE_CondRetFaltouMemoria ;
			}
		}

	} /* Fim função: EE  &Inserir em espaco extra */

/***************************************************************************
*
*  Função: EE  &Excluir carta em espaço extra
*  ****/

	EE_tpCondRet EE_Excluir( LIS_tppLista pEspaçosExtras , tppCarta pCarta , int inxEE )
	{

		LIS_tpCondRet CondRetEE ;
		tppCarta pCartaEE ;

		IrInicioLista( pEspaçosExtras );

		if ( (inxEE > 3) || (inxEE < 0) )
		{
			return EE_CondRetIndice ;
		}

		CondRetEE = LIS_AvancarElementoCorrente ( pEspaçosExtras, inxEE );

		if ( CondRetEE == ( LIS_CondRetFimLista || LIS_CondRetListaVazia ))
		{
			return EE_CondRetVazio ;
		}
		
		pCartaEE = LIS_ObterValor( pEspaçosExtras );

		if ( ( inxEE == 0) && ( pCartaEE == NULL ) )
		{
			return EE_CondRetVazio ;
		}
		
		pCarta->num = pCartaEE->num ;
		pCarta->nipe = pCartaEE->nipe ;

		LIS_ExcluirElemento( pEspaçosExtras ) ;
			
		return EE_CondRetOK ;

	} /* Fim função: EE  &Excluir carta em espaco extra */

/***************************************************************************
*
*  Função: EE  &Imprimir espaços extras
*  ****/

	EE_tpCondRet EE_Imprimir ( LIS_tppLista pEspaçosExtras )
	{
		LIS_tpCondRet CondRet = -1;
		tppCarta pCarta ;
		int EE_Corr = 0;

		IrInicioLista( pEspaçosExtras ) ;

		while ( CondRet != LIS_CondRetFimLista )
		{
			pCarta = LIS_ObterValor ( pEspaçosExtras ) ;
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

			CondRet = LIS_AvancarElementoCorrente( pEspaçosExtras, 1 );
			EE_Corr++ ;
		}
		printf("\n");

		return EE_CondRetOK ;

	} /* Fim função: EE  &Imprimir espacos extras */



/********** Fim do módulo de implementação: EE Espaços extras de Free Cell **********/