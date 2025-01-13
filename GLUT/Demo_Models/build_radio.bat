cl /c /EHsc /I C:\freeglut\include Radio.c
link Radio.obj /LIBPATH:C:\freeglut\lib\x64 /SUBSYSTEM:CONSOLE
Radio.exe