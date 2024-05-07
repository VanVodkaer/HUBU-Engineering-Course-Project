del /Q .\vodkaer\resources\bin

cd .\Nizday88
g++ JudgingPrimeNumber.cpp -o JudgingPrimeNumber.exe
move JudgingPrimeNumber.exe ..\vodkaer\resources\bin
cd ..

cd .\temperature
g++ tempature.cpp -o tempature.exe
move tempature.exe ..\vodkaer\resources\bin
cd ..

cd .\number
g++ numberguess.cpp -o numberguess.exe
move numberguess.exe ..\vodkaer\resources\bin
cd ..
