/***************************************************************************
*  $MCI Módulo de implementação: BAR Cria lista representando baralho
*
*  Arquivo gerado:              BARALHO.c
*  Letras identificadoras:      BAR
*
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   26/abr/2009 início desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   <malloc.h>

#include "CARTA.h"
#include "LISTA.h"

#define    MAX_BARALHO	52

#define BARALHO_OWN
#include "BARALHO.h"
#undef BARALHO_OWN

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR  &Criar lista representando baralho
*  ****/

	 BAR_tpCondRet BAR_CriarBaralho( char * pBaralho, LIS_tppLista pListaBAR )
	 {
		 tpCarta vtCarta[52];
		 int nipe;
		 int carta;
		 int inxBAR = 0;
		 int inxCopia;
		 LIS_tpCondRet CondRet;

		 for ( nipe = 1; nipe <= 4; nipe++ )
		 {
			 for ( carta = 1; carta <= 13; carta++)
			 {
				 
				 vtCarta[inxBAR].nipe = nipe ;
				 vtCarta[inxBAR].num = carta ;

				 inxBAR++;
			 }
		 }

		 for ( inxCopia = 0; inxCopia < MAX_BARALHO; inxCopia++ )
		 {
			 tppCarta CopiaCarta ;
			 char i ; 
			 
			 CopiaCarta = ( tpCarta * ) malloc ( sizeof( tpCarta ) );
			 i = pBaralho[inxCopia] ;
			 CopiaCarta->nipe = vtCarta[i - 1].nipe ;
			 CopiaCarta->num = vtCarta[i - 1].num ;
			 
			 CondRet = LIS_InserirElementoApos(pListaBAR, CopiaCarta);

			 if( CondRet == LIS_CondRetFaltouMemoria)
			 {
				 return BAR_CondRetFaltouMemoria ;
			 }
		 }

		 return BAR_CondRetOK ;

	 }

 /***************************************************************************
*
*  Função: BAR  &Imprimir
*  ****/

	BAR_tpCondRet BAR_Imprimir ( LIS_tppLista pListaBAR )
	{
		tppCarta pCarta ;

		IrInicioLista( pListaBAR ) ;
		pCarta = LIS_ObterValor( pListaBAR );
		printf("\nnipe = ");
		
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
		printf ("\ncarta = ");
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

		printf("\n\n");

		while( LIS_AvancarElementoCorrente ( pListaBAR , 1 ) != LIS_CondRetFimLista )
		{
			pCarta = LIS_ObterValor( pListaBAR );
			
			printf("\nnipe = ");
		
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
			printf ("\ncarta = ");
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

			printf("\n\n");
		}

		return BAR_CondRetOK ;
	}

 /********** Fim do módulo de implementação: BAR Cria lista representando baralho **********/

