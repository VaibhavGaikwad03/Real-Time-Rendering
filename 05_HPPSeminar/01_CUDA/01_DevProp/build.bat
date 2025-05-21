del *.exe
del *.exp
del *.lib

nvcc DevProp.cu -o DevProp.exe
DevProp.exe

del *.exe
del *.exp
del *.lib