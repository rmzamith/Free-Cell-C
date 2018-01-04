@ECHO  OFF
REM  Gera script de make
REM    Sintaxe   GeraMake <NomeArquivoComposicao>

pushd  .

if ""=="%1" goto erro

if /I "CriaLib"=="%1"   set _var="CriaLib"
if /I "Paciencia"=="%1"   set _var="Paciencia"
if /I "tudo"=="%1" goto tudo

gmake /bComposicao\ /c%_var% /pgmake
goto sai

:tudo
gmake /bComposicao\ /cCriaLib /pgmake
gmake /bComposicao\ /cPaciencia /pgmake
goto sai

:erro
echo Falta nome do arquivo de diretivas de composicao

:sai
popd
