del *.obj
del *.exe

@REM cl /c /EHsc math/math.c DynamicBharat/DynamicBharat.c OGL.c 
@REM rc OGL.rc
@REM link OGL.obj math.obj DynamicBharat.obj OGL.res user32.lib gdi32.lib winmm.lib /SUBSYSTEM:WINDOWS
@REM OGL.exe

cl /c /EHsc OGL.c math/math.c utils/utils.c IndiaMap.c
rc OGL.rc
link OGL.obj math.obj IndiaMap.obj OGL.res utils.obj user32.lib gdi32.lib winmm.lib /SUBSYSTEM:WINDOWS
OGL.exe

del *.obj
del *.exe
del *.res