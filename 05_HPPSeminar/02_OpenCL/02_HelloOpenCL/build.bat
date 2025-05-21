del *.obj
del *.exe

cl /I"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\include" /c HelloOpenCL.c
link HelloOpenCL.obj /LIBPATH:"C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.8\lib\x64" OpenCL.lib
HelloOpenCL.exe

del *.obj
del *.exe