$zipPath = "..\lib\wxWidgets-3.2.6.zip"
Invoke-WebRequest https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.6/wxWidgets-3.2.6.zip -OutFile $zipPath

$unzipPath = $FilePath + "\wxWidgetsTEMP"
Expand-Archive -Path $zipPath -DestinationPath $unzipPath

$libPath = $unzipPath + "\wxWidgets-3.2.6"
Move-Item $libPath $FilePath

Remove-Item $zipPath
Remove-Item $unzipPath

$realPath = $FilePath + "wxWidgets-3.2.6\"
[System.Environment]::SetEnvironmentVariable('WXWIN_3_2_6', $realPath, 'User')
	
cd $realPath
cd build
cd msw
nmake /f makefile.vc BUILD=debug SHARED=1 TARGET_CPU=x64
nmake /f makefile.vc BUILD=release SHARED=1 TARGET_CPU=x64
