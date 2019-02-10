del *.tds
del *.bak
del *.obj
del *.~??
del ..\numlocksrc.zip
md compact
copy numlock.exe compact
start /w D:\develop\aspack21\aspack.exe compact\numlock.exe
pkzip25 -add -passw=claudiosoft  ..\numlocksrc  *.* -excl=*.exe -excl=*.obj -excl=*.txt -excl=*.tds -excl=*.dcu -excl=*.chm -excl=*.bak
pkzip25 -add -passw=claudiosoft  ..\numlocksrc  -direct -recurse graphics32\*.* -excl=*.exe -excl=*.obj -excl=*.txt -excl=*.tds -excl=*.dcu -excl=*.chm -excl=*.bak -excl=*.zip
del ..\numlockexe.zip
pkzip25 -add ..\numlockexe compact\numlock.exe