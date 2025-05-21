del *.obj
del *.exe

cl /I"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\include" /c DevProp.c
link DevProp.obj /LIBPATH:"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\lib\x64" OpenCL.lib
DevProp.exe

del *.obj
del *.exe