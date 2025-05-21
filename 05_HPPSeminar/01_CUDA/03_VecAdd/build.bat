del *.exe
del *.exp
del *.lib

nvcc VecAdd.cu -o VecAdd.exe
VecAdd.exe

del *.exe
del *.exp
del *.lib