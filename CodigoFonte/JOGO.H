#if ! defined( JOGO_ )
#define JOGO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: JOG  Gerenciador jogo FreeCell
*
*  Arquivo gerado:              JOGO.h
*  Letras identificadoras:      JOG
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rz   27/mai/2009 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*	  Esse modulo gerencia a execu��o de um jogo de freecell. Ao ser iniciado o jogo,
*	  uma estrutura aonde as cartas ser�o armazenadas � criada, e em seguida � chamada
*	  uma fun��o que ira embaralhar e distribuir as cartas nas sequencias visiveis do
*	  jogo.
*
*	  A Estrutura do jogo funciona da seguinte maneira. As 8 primeiras listas da
*	  estrutura s�o as SV, as 4 seguintes s�o as SO e a ultima lista � a de EE.
*
*	  O jogo tem inicio, mostrando a mesa do jogo vazia, e um
*	  menu, com as opcoes de acao para o jogador como, novo jogo, sair do jogo, 
*     salvar jogo, carregar jogo e mover carta.
*
*	  Ao selecionar a opcao de mover uma carta, sera apresentado outro menu, em que
*	  o jogador selecionara o tipo de movimento que ele quer realizar.
*
*	  A cada jogada que o jogador executar, a mesa do jogo ser� impressa, mesmo que a
*	  jogada n�o seja permitida, nesse caso sera impressa tamb�m uma mensagem, no topo
*	  do prompt , alertando o jogador que tal movimento n�o esta de acordo com as 
*	  regras do jogo.
*
*	  Ao salvar o jogo, ser� criado um arquivo texto na pasta local do jogo, com o
*	  nome que o jogador quiser dar para o jogo salvo. � importante, que o jogador
*	  ao tentar carregar o jogo, esteja com o arquivo texto a ser carregado no
*	  diret�rio local do jogo, caso o contr�rio o jogo n�o ser� carregado.
*
***************************************************************************/

#if defined( JOGO_OWN )
   #define JOGO_EXT
#else
   #define JOGO_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: JOG Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de jogo
*
***********************************************************************/

   typedef enum {

         JOG_CondRetOK ,
               /* Concluiu corretamente */

	     JOG_CondRetNaoConseguiuAbrir,
		       /* N�o conseguiu abrir arquivo ao tentar salvar ou abrir */
	     
	     JOG_CondRetArquivoExistente ,
			  /* Nome de arquivo esta sendo utilizado por outro save*/

		 JOG_CondRetNaoExiste ,
			  /* Nao encontrou arquivo salvo */
		 
		 JOG_CondRetArquivoVazio,
			  /* Arquivo n�o contem dados */

	     JOG_CondRetFaltouMemoria
		      /* Faltou memoria ao tentar inserir uma carta */

   } JOG_tpCondRet ;

#undef JOGO_EXT

/********** Fim do m�dulo de defini��o: JOG  gerenciador jogo FreeCell **********/

#else
#endif