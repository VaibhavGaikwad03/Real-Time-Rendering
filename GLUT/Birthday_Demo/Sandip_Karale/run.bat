cl.exe /c /I .\ /I .\include OGL.c
link.exe OGL.obj /LIBPATH:.\lib\freeglut\x64
OGL.exe