del *.obj
del *.exe
del OGL.res

cl /c /EHsc OGL.c
rc OGL.rc
link OGL.obj OGL.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
OGL.exe

del *.obj
del *.exe
del OGL.res