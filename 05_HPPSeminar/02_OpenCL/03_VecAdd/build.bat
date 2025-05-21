del *.obj
del *.exe

cl /I"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\include" /c VecAdd.cpp
link VecAdd.obj /LIBPATH:"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\lib\x64" OpenCL.lib
VecAdd.exe

del *.obj
del *.exe