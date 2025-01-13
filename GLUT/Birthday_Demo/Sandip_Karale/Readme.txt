To compile:
cl.exe /c /I .\include\freeglut\ /I .\ OGL.c

To link:
link.exe OGL.obj /LIBPATH:.\lib\freeglut\x64

also the app should be able to find the dll