cl /c /EHsc /I C:\freeglut\include IndiaMap.c
link IndiaMap.obj /LIBPATH:C:\freeglut\lib\x64 /SUBSYSTEM:CONSOLE
IndiaMap.exe