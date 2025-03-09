del *.obj
del *.exe

cl /c /EHsc OGL.c
rc OGL.rc
link OGL.obj OGL.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
OGL.exe
