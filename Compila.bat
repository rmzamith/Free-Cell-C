@ECHO  OFF
REM  Compila programa C usando nmake %1.mak  do conjunto MS Visual c/c++
REM  Sintaxe:  faz  nome-do-arquivo.mak  [o]
REM                    opção  o : compila otimizado. Todos os obj devem 
REM                               ter sido destruidos antes
REM  Necessita o "environment" corretamente inicializado para usar o compilador
REM       c/c++ da Microsoft  (batch "vsvars32.bat", pasta Visualstudio \Common7\Tools)
REM  Pode necessitar o ajuste da secao :contin para que o NotePad abra 
REM                      corretamente o arquivo de mensagens de erro geradas
REM                      ao compilar

pushd  .

if ""=="%1" goto erro

del "Resultados\*.err"
del *.obj

cd Composicao

if /I "CriaLib"=="%1"   set _var="CriaLib"
if /I "Paciencia"=="%1" set _var="Paciencia"
if /I "tudo"=="%1" goto tudo

if /I "o"=="%2" (nmake /F%_var%.make PRD=) else (nmake /F%_var%.make)
goto contin

:tudo
if /I "o"=="%2" (nmake /FCriaLib.make PRD=) else (nmake /FCriaLib.make)
if /I "o"=="%2" (nmake /FPaciencia.make PRD=) else (nmake /FPaciencia.make)
goto contin

:contin
echo "*.err em Resultados\"

goto sai

:erro
echo Falta nome do arquivo a compilar

:sai
cd ..
popd
