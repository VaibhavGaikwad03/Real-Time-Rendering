del *.obj
del *.exe

cl /I"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\include" /c MatMul.cpp
link MatMul.obj /LIBPATH:"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\lib\x64" OpenCL.lib
MatMul.exe

del *.obj
del *.exe