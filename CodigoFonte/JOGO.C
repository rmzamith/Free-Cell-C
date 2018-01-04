/***************************************************************************
*  $MCI Módulo de implementação: JOG  Gerenciador do jogo FreeCell
*
*  Arquivo gerado:              JOGO.c
*  Letras identificadoras:      JOG
*
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data        Observações
*     1       rznm   26/abr/2009   início desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   <malloc.h>
#include   <string.h>

#include "CARTA.h"
#include "LISTA.h"
#include "EMBARALHAMENTO.h"
#include "SEQUENCIA_ORDENADA.h"
#include "SEQUENCIA_VISIVEL.h"
#include "ESPACO_EXTRA.h"
#include "BARALHO.h"

#define JOGO_OWN
#include "JOGO.h"
#undef JOGO_OWN

/***** Protótipos das funções encapuladas no módulo *****/

	static void DestruirCarta( tppCarta pCarta ) ;

	static JOG_tpCondRet JOG_PreencherEstrutura ( LIS_tppLista pEstrutura,
										          void( * DestruirCarta ) ( tpCarta * pCarta )) ;

	static JOG_tpCondRet JOG_DistribuirCartas ( LIS_tppLista pEstrutura, LIS_tppLista pBaralho ) ;

	static JOG_tpCondRet JOG_ImprimirMesa ( LIS_tppLista pEstrutura ) ;

	static JOG_tpCondRet JOG_ImprimirMenu ( ) ;

	static JOG_tpCondRet JOG_ImprimirLegenda ( ) ;

	static JOG_tpCondRet JOG_Salvar(LIS_tppLista pEstrutura, char * nome) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: JOG  &Main
*  ****/

	int main (void)
	{
		/* Declarações de variaveis */
		
		LIS_tppLista pEstrutura ;
		
		LIS_tppLista pLIS_Baralho ;
		char vetBaralho[52] ;

		LIS_tppLista pLIS_Fonte, pLIS_Destino ;
		tppCarta pCartaMover ;
		int CondRet ;

		LIS_tppLista pLIS_VerificadoraCompletude ;

		int opcao ;
		int opcaoMover ;

		SO_tpCondRet SO1_CondRet, SO2_CondRet, SO3_CondRet, SO4_CondRet ;
		
		int inxSV, inxSV_Dest, inxSO, inxEE ;

		JOG_tpCondRet JOG_CondRet ;

		JOG_tpCondRet CondRetARQ ;
		char nomeJogo[21] ;
		
		/* Fim das declarações de variaveis */

		/* Inicialização do jogo */

		SO1_CondRet = -1;
		SO2_CondRet = -1; 
		SO3_CondRet = -1; 
		SO4_CondRet = -1; 

		pEstrutura = LIS_CriarLista ( LIS_DestruirLista ) ;
		if( pEstrutura == NULL )
		{
			printf("---------------Faltou memoria ao criar estrutura necessaria do jogo");
			return 1 ;
		}

		pLIS_Baralho = LIS_CriarLista ( DestruirCarta ) ;
		if( pLIS_Baralho == NULL )
		{
			printf("---------------Faltou memoria ao criar estrutura necessaria do jogo");
			return 1 ;
		}

		JOG_CondRet = JOG_PreencherEstrutura ( pEstrutura, DestruirCarta ) ;
		if( JOG_CondRet == JOG_CondRetFaltouMemoria )
		{
			printf("---------------Faltou memoria ao criar estrutura necessaria do jogo");
			return 1 ;
		}

		printf ("\n\n------------BEM VINDO AO JOGO DE PACIENCIA FREE CELL!!------------\n\n\n");

		/* Fim da inicialização do jogo */

		/* Loop */

		while ( SO1_CondRet != SO_CondRetCompleta || 
			    SO2_CondRet != SO_CondRetCompleta ||
				SO3_CondRet != SO_CondRetCompleta || 
				SO4_CondRet != SO_CondRetCompleta )
		{
			
			JOG_ImprimirMesa ( pEstrutura ) ;
			JOG_ImprimirMenu ( ) ;

			printf("Opcao : ");
			scanf_s("%d", &opcao);

			/* Ativa Opcao invalida */
			/* Fim da ativa opcao invalida */

			switch (opcao)
			{
				/* Ativa Novo Jogo */
				case 1:

					LIS_EsvaziarLista ( pLIS_Baralho );
					LIS_EsvaziarLista ( pEstrutura );

					JOG_CondRet = JOG_PreencherEstrutura ( pEstrutura, DestruirCarta ) ;
					if( JOG_CondRet == JOG_CondRetFaltouMemoria )
					{
						printf("---------------Faltou memoria ao criar estrutura necessaria do jogo");
						return 1 ;
					}

					EMB_Embaralhar ( vetBaralho ) ;
					BAR_CriarBaralho ( vetBaralho, pLIS_Baralho ) ;

					JOG_DistribuirCartas ( pEstrutura, pLIS_Baralho ) ;

				break;
				/* Fim da ativa Novo Jogo */
				
				/* Ativa Sair do Jogo */
				case 2:

					LIS_DestruirLista( pEstrutura );
					LIS_DestruirLista( pLIS_Baralho );

					return 0;

				break;
				/* Fim da ativa Sair do Jogo */

				/* Ativa Salvar Jogo */
				case 3:

					puts("\nEscreva o nome do arquivo que vai guardar o jogo corrente:\n");
					scanf(" %20[^\n]", nomeJogo );
					strcat(nomeJogo, ".txt");
					CondRetARQ = JOG_Salvar( pEstrutura, nomeJogo );
					if(CondRetARQ == JOG_CondRetArquivoExistente )
					{
						puts("-----------------------Jogo nao foi salvo!!\n");
						break;
					}
					if(CondRetARQ == JOG_CondRetNaoConseguiuAbrir )
						puts("------------------Erro ao tentar gravar arquivo!! \n");

				break;
				/* Fim da ativa Salvar Jogo */

				/* Ativa Carregar Jogo */
				case 4:

					puts("\nEscreva o nome do arquivo que deseja carregar para continuar jogo:\n");
					scanf(" %20[^\n]", nomeJogo );
					strcat(nomeJogo, ".txt");
					CondRetARQ = JOG_Recuperar( pEstrutura, nomeJogo );
					if( CondRetARQ == JOG_CondRetFaltouMemoria )
					{
						printf("-------------------Faltou memoria ao carregar jogo!!");
					}
					if( CondRetARQ == JOG_CondRetNaoExiste || JOG_CondRetArquivoVazio )
					{
						puts("-----------Arquivo nao esta no diretorio, ou esta em branco\n");
					}

				break;
				/*Fim da ativa Carregar Jogo*/

				/* Ativa Mover Carta */
				case 5:

					printf("Mover de :\n\n");
					printf("1. Sequencia Visivel para Sequencia Ordenada.\n");
					printf("2. Sequencia Visivel para Espaco Extra.\n");
					printf("3. Espaco Extra para Sequencia Ordenada.\n");
					printf("4. Espaco Extra para Sequencia Visivel.\n");
					printf("5. Sequencia Visivel para Sequencia Visivel.\n");
					printf("6. Voltar ao menu anterior.\n\n");

					scanf("%d", &opcaoMover);

					switch ( opcaoMover )
					{
						/* Inicio da ativa Mover de SV para SO */
						case 1:
							printf("Escolha o indice da SV de qual deseja mover a carta:\n");
							scanf("%d", &inxSV );
							if( inxSV < 0 || inxSV > 7 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}
							printf("Escolha o indice da SO para qual deseja mover a carta:\n");
							scanf("%d", &inxSO );
							if( inxSO < 0 || inxSO > 3 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}

							IrInicioLista(pEstrutura);
							LIS_AvancarElementoCorrente( pEstrutura, inxSV );
							pLIS_Fonte = LIS_ObterValor( pEstrutura );
							pCartaMover = ( tpCarta * ) malloc ( sizeof (tpCarta));
							
							CondRet = SV_Excluir( pLIS_Fonte, pCartaMover );
							if( CondRet == SV_CondRetVazia )
							{
								printf("\n\n---------------Sequencia Visivel esta vazia!!\n\n");
								free( pCartaMover ) ;
								break ;
							}

							IrInicioLista(pEstrutura);
							LIS_AvancarElementoCorrente( pEstrutura, 8 + inxSO );
							pLIS_Destino = LIS_ObterValor( pEstrutura );

							CondRet = SO_Inserir ( pLIS_Destino, pCartaMover ) ;
							if( CondRet == SO_CondRetNipeDiferente ||
								CondRet == SO_CondRetForaDeSequencia )
							{
								printf("\n\n---------------Movimento Invalido!!\n\n");
								LIS_InserirElementoApos( pLIS_Fonte, pCartaMover ) ;
								break ;
							}

						break;
						/* Fim da ativa Mover de SV para SO */

						/* Inicio da ativa Mover de SV para EE */
						case 2:
							printf("Escolha o indice da SV de qual deseja mover a carta para um EE:\n");
							scanf("%d", &inxSV );
							if( inxSV < 0 || inxSV > 7 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}

							IrInicioLista(pEstrutura);
							LIS_AvancarElementoCorrente( pEstrutura, inxSV );
							pLIS_Fonte = LIS_ObterValor( pEstrutura );
							pCartaMover = ( tpCarta * ) malloc ( sizeof (tpCarta));

							CondRet = SV_Excluir( pLIS_Fonte, pCartaMover );
							if( CondRet == SV_CondRetVazia )
							{
								printf("\n\n---------------Sequencia Visivel esta vazia!!\n\n");
								free( pCartaMover ) ;
								break ;
							}

							IrFinalLista( pEstrutura );
							pLIS_Destino = LIS_ObterValor( pEstrutura );

							CondRet = EE_Inserir ( pLIS_Destino, pCartaMover ) ;
							if( CondRet ==  EE_CondRetEspaçoOcupado )
							{
								printf("\n\n---------------Espacos Extras Ocupados!!\n\n");
								LIS_InserirElementoApos( pLIS_Fonte, pCartaMover ) ;
								break ;
							}

						break;
						/* Fim da ativa Mover de SV para EE */

						/* Inicio da ativa Mover de EE para SO */
						case 3:
							printf("Escolha o indice da EE de qual deseja mover:\n");
							scanf("%d", &inxEE );
							if( inxEE < 0 || inxEE > 3 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}
							printf("Escolha o indice da SO para qual deseja mover:\n");
							scanf("%d", &inxSO );
							if( inxSO < 0 || inxSO > 3 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}

							IrFinalLista( pEstrutura );
							pLIS_Fonte = LIS_ObterValor( pEstrutura );
							pCartaMover = ( tpCarta * ) malloc ( sizeof (tpCarta));
							CondRet = EE_Excluir( pLIS_Fonte, pCartaMover, inxEE ) ;
							if ( CondRet == EE_CondRetVazio )
							{
								printf("\n\n---------------Espaco Extra esta vazio!!\n\n");
								free( pCartaMover ) ;
								break ;
							}

							IrInicioLista(pEstrutura);
							LIS_AvancarElementoCorrente( pEstrutura, 8 + inxSO );
							pLIS_Destino = LIS_ObterValor( pEstrutura );

							CondRet = SO_Inserir ( pLIS_Destino, pCartaMover ) ;
							if( CondRet == SO_CondRetNipeDiferente ||
								CondRet == SO_CondRetForaDeSequencia )
							{
								printf("\n\n---------------Movimento Invalido!!\n\n");
								LIS_InserirElementoApos( pLIS_Fonte, pCartaMover ) ;
								break ;
							}

						break;
						/* Fim da ativa Mover de EE para SO */

						/* Inicio da ativa Mover de EE para SV */
						case 4:

							printf("Escolha o indice da EE de qual deseja mover:\n");
							scanf("%d", &inxEE );
							if( inxEE < 0 || inxEE > 3 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}
							printf("Escolha o indice da SV para qual deseja mover:\n");
							scanf("%d", &inxSV );
							if( inxSV < 0 || inxSV > 7 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}

							IrFinalLista( pEstrutura );
							pLIS_Fonte = LIS_ObterValor( pEstrutura );
							pCartaMover = ( tpCarta * ) malloc ( sizeof (tpCarta));
							CondRet = EE_Excluir( pLIS_Fonte, pCartaMover, inxEE ) ;
							if ( CondRet == EE_CondRetVazio )
							{
								printf("\n\n---------------Espaco Extra esta vazio!!\n\n");
								free( pCartaMover ) ;
								break ;
							}

							IrInicioLista(pEstrutura);
							LIS_AvancarElementoCorrente( pEstrutura, inxSV );
							pLIS_Destino = LIS_ObterValor( pEstrutura );

							CondRet = SV_Inserir ( pLIS_Destino, pCartaMover ) ;
							if( CondRet == SV_CondRetCorIgual ||
								CondRet == SV_CondRetForaDeSequencia )
							{
								printf("\n\n---------------Movimento Invalido!!\n\n");
								LIS_InserirElementoApos( pLIS_Fonte, pCartaMover ) ;
								break ;
							} 

						break;
						/* Fim da ativa Mover de EE para SV */

						/* Inicio da ativa Mover de SV para SV */
						case 5:
							printf("Escolha o indice da SV de qual deseja mover a carta:\n");
							scanf("%d", &inxSV );
							if( inxSV < 0 || inxSV > 7 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}
							printf("Escolha o indice da SV para qual deseja mover a carta:\n");
							scanf("%d", &inxSV_Dest );
							if( inxSV_Dest < 0 || inxSV_Dest > 7 )
							{
								printf("---------------Indice invalido!!\n");
								break ;
							}

							IrInicioLista(pEstrutura);
							LIS_AvancarElementoCorrente( pEstrutura, inxSV );
							pLIS_Fonte = LIS_ObterValor( pEstrutura );
							pCartaMover = ( tpCarta * ) malloc ( sizeof (tpCarta));
							
							CondRet = SV_Excluir( pLIS_Fonte, pCartaMover );
							if( CondRet == SV_CondRetVazia )
							{
								printf("\n\n---------------Sequencia Visivel esta vazia!!\n\n");
								free( pCartaMover ) ;
								break ;
							}

							IrInicioLista(pEstrutura);
							LIS_AvancarElementoCorrente( pEstrutura, inxSV_Dest );
							pLIS_Destino = LIS_ObterValor( pEstrutura );

							CondRet = SV_Inserir ( pLIS_Destino, pCartaMover ) ;
							if( CondRet == SV_CondRetCorIgual ||
								CondRet == SV_CondRetForaDeSequencia )
							{
								printf("\n\n---------------Movimento Invalido!!\n\n");
								LIS_InserirElementoApos( pLIS_Fonte, pCartaMover ) ;
								break ;
							}

						break ;
						/* Fim da ativa Mover de SV para SV */

						/* Ativa Voltar */
						case 6:

						break ;
						/* Fim do ativa Voltar */

						/* Ativa Opcao invalida */
						default:
							printf("\n\n---------------Opcao invalida!\n\n");
						
						break ;
						/* Fim do ativa opcao invalida */

					}

				break;
				/* Fim da ativa Mover Carta */

				/* Ativa Legenda*/
				case 6:
					
					JOG_ImprimirLegenda ( ) ;

				break ;
				/* Fim do ativa Legenda */
				
				/* Ativa Opcao invalida */
				default:
					printf("\n\n---------------Opcao invalida!\n\n");
				break ;
				/* Fim do ativa opcao invalida */
			}

			/* Verificar fim de jogo */

			IrInicioLista( pEstrutura );
			
			LIS_AvancarElementoCorrente( pEstrutura, 8 );
			pLIS_VerificadoraCompletude = LIS_ObterValor( pEstrutura );
			SO1_CondRet = SO_VerificarCompletude( pLIS_VerificadoraCompletude ) ;

			LIS_AvancarElementoCorrente( pEstrutura, 1 );
			pLIS_VerificadoraCompletude = LIS_ObterValor( pEstrutura );
			SO2_CondRet = SO_VerificarCompletude( pLIS_VerificadoraCompletude ) ;

			LIS_AvancarElementoCorrente( pEstrutura, 1 );
			pLIS_VerificadoraCompletude = LIS_ObterValor( pEstrutura );
			SO3_CondRet = SO_VerificarCompletude( pLIS_VerificadoraCompletude ) ;

			LIS_AvancarElementoCorrente( pEstrutura, 1 );
			pLIS_VerificadoraCompletude = LIS_ObterValor( pEstrutura );
			SO4_CondRet = SO_VerificarCompletude( pLIS_VerificadoraCompletude ) ;

			/*Fim da ativa Verificar fim de jogo */

		}

		printf ("\n\n\n\n\n\n\n>>>>>>>>>>>PARABENS!! VOCE E UM CAMPEAO!!<<<<<<<<<<<<\n\n\n\n\n\n\n");
		return 0 ;

	} /* Fim função: JOG -Main */
	

/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: JOG -Destruir carta
*
***********************************************************************/

   void DestruirCarta( tppCarta pCarta )
   {

      free( pCarta ) ;

   } /* Fim função: JOG -Destruir carta */

/***************************************************************************
*
*  Função: JOG  &Preencher Estrutura
*  ****/
	
	JOG_tpCondRet JOG_PreencherEstrutura ( LIS_tppLista pEstrutura,
										    void( * DestruirCarta ) ( tpCarta * pCarta ))
	{
		int i;

		for ( i = 0; i < 13; i++ )
		{
			LIS_tpCondRet condRetLis;

			condRetLis = LIS_InserirElementoApos( pEstrutura, LIS_CriarLista( DestruirCarta ));
			
			if ( condRetLis == LIS_CondRetFaltouMemoria )
			{
				return JOG_CondRetFaltouMemoria;
			}

		}

		return JOG_CondRetOK ;
	}

/***************************************************************************
*
*  Função: JOG  &Distribuir Cartas
*  ****/

	JOG_tpCondRet JOG_DistribuirCartas ( LIS_tppLista pEstrutura, LIS_tppLista pBaralho )
	{
		LIS_tpCondRet LISCondRet = -1 ;
		int inxEstrutura ;
		tppCarta pCartaBaralho, pCartaInserir ;
		LIS_tppLista pSVcorrente ;

		IrInicioLista( pBaralho );

		while( LISCondRet !=  LIS_CondRetFimLista )
		{
			
			for ( inxEstrutura = 0 ; inxEstrutura < 8 ; inxEstrutura++ )
			{
				IrInicioLista( pEstrutura ) ;
				LIS_AvancarElementoCorrente( pEstrutura , inxEstrutura ) ;
				
				pCartaInserir = ( tpCarta * ) malloc ( sizeof (tpCarta)) ;
				if( pCartaInserir == NULL )
				{
					return JOG_CondRetFaltouMemoria ;
				}

				pCartaBaralho = LIS_ObterValor( pBaralho ) ;

				pCartaInserir->nipe = pCartaBaralho->nipe ;
				pCartaInserir->num = pCartaBaralho->num ;

				pSVcorrente = LIS_ObterValor( pEstrutura ) ;
				LIS_InserirElementoApos( pSVcorrente, pCartaInserir ) ;

				LISCondRet = LIS_AvancarElementoCorrente( pBaralho , 1 ) ;
				if ( LISCondRet == LIS_CondRetFimLista )
				{
					break ;
				}

			}
		}
		return JOG_CondRetOK ;
	}

/***************************************************************************
*
*  Função: JOG  &Imprimir Mesa
*  ****/
	
	JOG_tpCondRet JOG_ImprimirMesa ( LIS_tppLista pEstrutura )
	{
		int inxEstrutura ;
		LIS_tppLista pListaCorr ;

		for ( inxEstrutura = 0; inxEstrutura < 8; inxEstrutura++ )
		{
			IrInicioLista ( pEstrutura );
			LIS_AvancarElementoCorrente ( pEstrutura, inxEstrutura );
			printf("Sequencia Visivel %d:\n", inxEstrutura );
			pListaCorr = LIS_ObterValor( pEstrutura ) ;
			SV_Imprimir ( pListaCorr ) ;
		}
		printf("\n");

		for ( inxEstrutura = 8; inxEstrutura < 12; inxEstrutura++ )
		{
			IrInicioLista ( pEstrutura );
			LIS_AvancarElementoCorrente ( pEstrutura, inxEstrutura );
			printf("Sequencia Ordenada %d:\n", inxEstrutura - 8 );
			pListaCorr = LIS_ObterValor( pEstrutura ) ;
			SO_Imprimir ( pListaCorr ) ;
		}
		printf("\n");

		IrInicioLista ( pEstrutura );
		LIS_AvancarElementoCorrente ( pEstrutura, 12 );
		printf("Espacos Extras:\n" );
		pListaCorr = LIS_ObterValor( pEstrutura ) ;
		EE_Imprimir ( pListaCorr ) ;

		return JOG_CondRetOK ;

	}

/***************************************************************************
*
*  Função: JOG  &Imprimir Menu
*  ****/

	JOG_tpCondRet JOG_ImprimirMenu ( )
	{
		printf("\n\n Escolha uma das opcoes abaixo: \n\n");
		printf("1. Novo jogo.\n2. Sair do jogo.\n3. Gravar jogo.\n4. Recuperar jogo.\n5. Mover Carta.\n6. Legenda\n\n" );

		return JOG_CondRetOK ;

	}

/***************************************************************************
*
*  Função: JOG  &Imprimir Legenda
*  ****/

	JOG_tpCondRet JOG_ImprimirLegenda ( )
	{
		printf("\n\n -----------------------------Legenda dos nipes------------------------\n\n");
		printf("Nipe C = Copas\nNipe P = Paus\nNipe O = Ouros\nNipe E = Espadas\n\n" );
		printf("---------------------------------------------------------------------------\n\n");

		return JOG_CondRetOK ;

	}

/***********************************************************************
*
*  $FC Função: JOG - Arquivo Existe
*
*  $ED Descrição da função
*     Verifica se o arquivo a ser aberto ja existe
*
***********************************************************************/

	int ArquivoExiste( const char *filename )
	{
	  FILE * arquivo;

		arquivo = fopen(filename, "rt") ;

		if( arquivo != NULL )
		{
			fclose(arquivo);
			return 1;
		}

		return 0;

	}


/***************************************************************************
*
*  Função: JOG  &Salvar Jogo
*  ****/
	
	JOG_tpCondRet JOG_Salvar( LIS_tppLista pEstrutura, char * nome )
	{
		FILE * arquivo;

		LIS_tpCondRet SEQCondRet = -1 ;
		LIS_tppLista pSEcorrente ;

		tppCarta pCarta;

		int inxEstrutura;
		int opcao;

		if( ArquivoExiste( nome ))
		{
			printf("Arquivo com esse nome ja existe, deseja sobrescreve-lo?\n\n");
			printf("1-Sim\n");
			printf("2-Nao\n");
			scanf("%d", &opcao);
			switch(opcao)
			{
				case 1:
					
					arquivo = fopen( nome ,"wt");
					if( arquivo == NULL )
					{
						return JOG_CondRetNaoConseguiuAbrir;
					}
				
				break ;

				case 2:

					return JOG_CondRetArquivoExistente ;

				default:
					printf("\n\n---------------Opcao invalida!\n\n");
				break;
			}
		}
		else
		{
			arquivo = fopen( nome ,"wt");
			if(arquivo == NULL)
			{
				return JOG_CondRetNaoConseguiuAbrir;
			}
		}
		for(inxEstrutura=0 ; inxEstrutura < 13 ; inxEstrutura++ )
		{
			IrInicioLista( pEstrutura ) ;
			LIS_AvancarElementoCorrente( pEstrutura , inxEstrutura ) ;
			pSEcorrente = LIS_ObterValor( pEstrutura ) ;
			IrInicioLista( pSEcorrente );
			SEQCondRet = -1;
			
			if( LIS_ObterNumElem( pSEcorrente )== 0)
			{
				fprintf(arquivo, "V\n");
				SEQCondRet = LIS_CondRetFimLista;
			}
			while( SEQCondRet != LIS_CondRetFimLista )
			{
				pCarta = LIS_ObterValor( pSEcorrente );
				
				fprintf(arquivo, "(");
				if ( pCarta->num == 10 )
				{
					fprintf(arquivo,"%c" , 'D');
				}
				else if ( pCarta->num == 11 )
				{
					fprintf(arquivo,"%c", 'J');
				}
				else if ( pCarta->num == 12 )
				{
					fprintf(arquivo,"%c", 'Q');
				}
				else if ( pCarta->num == 13 )
				{
					fprintf(arquivo, "%c", 'K');
				}
				else
				{
					fprintf(arquivo,"%d", pCarta->num );
				}

				fprintf(arquivo,"%d", pCarta->nipe );
				fprintf(arquivo, ")");

				SEQCondRet = LIS_AvancarElementoCorrente( pSEcorrente , 1 ) ;
				if(SEQCondRet == LIS_CondRetFimLista)
				{
					fprintf(arquivo, "\n");
				}
			}
		}
		fclose(arquivo);
		printf("--------------------------Jogo salvo com sucesso!!\n\n" );
		return JOG_CondRetOK;
	}

/***************************************************************************
*
*  Função: JOG  &Recuperar Jogo
*  ****/

	JOG_tpCondRet JOG_Recuperar(LIS_tppLista pEstrutura, char * NomeArquivo )
	{
		FILE * arquivo;

		LIS_tpCondRet LISCondRet = -1 ;
		LIS_tppLista pSEcorrente ;

		JOG_tpCondRet JOG_CondRet ;
		
		int num ;
		char Caracter ;
		int inxEstrutura ;
		int FlagBreak = 0;

		if(ArquivoExiste( NomeArquivo ))
		{

			LIS_EsvaziarLista ( pEstrutura );

			JOG_CondRet = JOG_PreencherEstrutura ( pEstrutura, DestruirCarta ) ;
			if( JOG_CondRet == JOG_CondRetFaltouMemoria )
			{
				return JOG_CondRetFaltouMemoria ;
			}

			arquivo = fopen( NomeArquivo,"rt" );

			for(inxEstrutura=0; inxEstrutura<13; inxEstrutura++)
			{
				FlagBreak = 0 ;
				IrInicioLista( pEstrutura ) ;
				LIS_AvancarElementoCorrente( pEstrutura , inxEstrutura ) ;
				pSEcorrente = LIS_ObterValor( pEstrutura ) ;

				IrInicioLista( pSEcorrente );

				while( FlagBreak == 0 )
				{
					tppCarta pCarta;
					Caracter = fgetc( arquivo ) ;
					
					if( Caracter == 'V' )
					{
						fgetc( arquivo ) ;
						break ;
					}
					else if( Caracter == ' ' )
					{
						return JOG_CondRetArquivoVazio ;
					}
					else if ( Caracter == '(' )
					{
						pCarta = (tppCarta) malloc (sizeof(tpCarta));
						if(pCarta == NULL)
						{
							return JOG_CondRetFaltouMemoria ;
						}
						
						Caracter = fgetc( arquivo );
						if ( Caracter == 'D' )
						{
							pCarta->num = 10 ;
						}
						else if ( Caracter == 'J' )
						{
							pCarta->num = 11 ;
						}
						else if ( Caracter == 'Q' )
						{
							pCarta->num = 12 ;
						}
						else if ( Caracter == 'K' )
						{
							pCarta->num = 13 ;
						}
						else
						{
							pCarta->num = Caracter - '0';
						}

						Caracter = fgetc( arquivo );
						pCarta->nipe = Caracter - '0' ;

						LISCondRet = LIS_InserirElementoApos( pSEcorrente, pCarta );
						if ( LISCondRet == LIS_CondRetFaltouMemoria )
						{
							return JOG_CondRetFaltouMemoria ;
						}

						Caracter = fgetc ( arquivo );

					}
					else
					{
						FlagBreak = 1;
					}
				}
			}

			fclose( arquivo );
		}

		else
		{
			return JOG_CondRetNaoExiste ;
		}

		return JOG_CondRetOK ;
	}


/********** Fim do módulo de implementação: JOG Gerenciador do jogo FreeCell **********/
			
			