# Download the installer
Invoke-WebRequest https://github.com/wxFormBuilder/wxFormBuilder/releases/download/v4.2.1/wxFormBuilder-4.2.1-x64.exe -OutFile "$env:TEMP\wxFormBuilder-4.2.1-x64.exe"

# Install it
$lib = "$pwd\..\lib"
& "$env:TEMP\wxFormBuilder-4.2.1-x64.exe" "/VERYSILENT" "/DIR=$lib\wxFormBuilder-4.2.1-x64"
