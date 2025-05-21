del *.exe
del *.exp
del *.lib

nvcc HelloCUDA.cu -o HelloCUDA.exe
HelloCUDA.exe

del *.exe
del *.exp
del *.lib