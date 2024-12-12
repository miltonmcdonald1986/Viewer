# Download the 7-Zip installer
Invoke-WebRequest "https://www.7-zip.org/a/7z2409-x64.exe" -OutFile "$env:TEMP\7z2409-x64.exe"

# Assumes current directory is "scripts" i.e. the directory containing this script.
$lib = "$pwd\..\lib"
& "$env:TEMP\7z2409-x64.exe" "/S" "/D=$lib\7-Zip"
