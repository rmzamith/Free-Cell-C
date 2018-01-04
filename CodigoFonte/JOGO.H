#if ! defined( JOGO_ )
#define JOGO_
/***************************************************************************
*
*  $MCD Módulo de definição: JOG  Gerenciador jogo FreeCell
*
*  Arquivo gerado:              JOGO.h
*  Letras identificadoras:      JOG
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       rz   27/mai/2009 início desenvolvimento
*
*  $ED Descrição do módulo
*	  Esse modulo gerencia a execução de um jogo de freecell. Ao ser iniciado o jogo,
*	  uma estrutura aonde as cartas serão armazenadas é criada, e em seguida é chamada
*	  uma função que ira embaralhar e distribuir as cartas nas sequencias visiveis do
*	  jogo.
*
*	  A Estrutura do jogo funciona da seguinte maneira. As 8 primeiras listas da
*	  estrutura são as SV, as 4 seguintes são as SO e a ultima lista é a de EE.
*
*	  O jogo tem inicio, mostrando a mesa do jogo vazia, e um
*	  menu, com as opcoes de acao para o jogador como, novo jogo, sair do jogo, 
*     salvar jogo, carregar jogo e mover carta.
*
*	  Ao selecionar a opcao de mover uma carta, sera apresentado outro menu, em que
*	  o jogador selecionara o tipo de movimento que ele quer realizar.
*
*	  A cada jogada que o jogador executar, a mesa do jogo será impressa, mesmo que a
*	  jogada não seja permitida, nesse caso sera impressa também uma mensagem, no topo
*	  do prompt , alertando o jogador que tal movimento não esta de acordo com as 
*	  regras do jogo.
*
*	  Ao salvar o jogo, será criado um arquivo texto na pasta local do jogo, com o
*	  nome que o jogador quiser dar para o jogo salvo. É importante, que o jogador
*	  ao tentar carregar o jogo, esteja com o arquivo texto a ser carregado no
*	  diretório local do jogo, caso o contrário o jogo não será carregado.
*
***************************************************************************/

#if defined( JOGO_OWN )
   #define JOGO_EXT
#else
   #define JOGO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

#include "CARTA.h"
#include "LISTA.h"

/***********************************************************************
*
*  $TC Tipo de dados: JOG Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de jogo
*
***********************************************************************/

   typedef enum {

         JOG_CondRetOK ,
               /* Concluiu corretamente */

	     JOG_CondRetNaoConseguiuAbrir,
		       /* Não conseguiu abrir arquivo ao tentar salvar ou abrir */
	     
	     JOG_CondRetArquivoExistente ,
			  /* Nome de arquivo esta sendo utilizado por outro save*/

		 JOG_CondRetNaoExiste ,
			  /* Nao encontrou arquivo salvo */
		 
		 JOG_CondRetArquivoVazio,
			  /* Arquivo não contem dados */

	     JOG_CondRetFaltouMemoria
		      /* Faltou memoria ao tentar inserir uma carta */

   } JOG_tpCondRet ;

#undef JOGO_EXT

/********** Fim do módulo de definição: JOG  gerenciador jogo FreeCell **********/

#else
#endif