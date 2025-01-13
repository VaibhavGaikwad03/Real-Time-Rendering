cl /c /EHsc /I C:\freeglut\include Table.c
link Table.obj /LIBPATH:C:\freeglut\lib\x64 /SUBSYSTEM:CONSOLE
Table.exe