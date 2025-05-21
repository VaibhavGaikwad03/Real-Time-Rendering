del *.exe
del *.exp
del *.lib

nvcc MatMul.cu -o MatMul.exe
MatMul.exe

del *.exe
del *.exp
del *.lib