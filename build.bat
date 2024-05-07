@REM 创建临时文件夹
mkdir .\temp\bin

@REM 单条构建
cd .\Nizday88
g++ JudgingPrimeNumber.cpp -o JudgingPrimeNumber.exe
move JudgingPrimeNumber.exe ..\temp
cd ..
