# Download the installer
Invoke-WebRequest https://github.com/wxFormBuilder/wxFormBuilder/releases/download/v4.2.1/wxFormBuilder-4.2.1-x64.exe -OutFile "$env:TEMP\wxFormBuilder-4.2.1-x64.exe"

# Install it
& "$env:TEMP\wxFormBuilder-4.2.1-x64.exe" "/VERYSILENT" "/DIR=C:\Users\milto\source\repos\Viewer\lib\wxFormBuilder-4.2.1-x64"
