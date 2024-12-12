# First download headers
Invoke-WebRequest https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.6/wxWidgets-3.2.6-headers.7z -OutFile "$env:TEMP\wxWidgets-3.2.6-headers.7z"

# Next, download binaries
Invoke-WebRequest https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.6/wxMSW-3.2.6_vc14x_x64_ReleaseDLL.7z -OutFile "$env:TEMP\wxMSW-3.2.6_vc14x_x64_ReleaseDLL.7z"

# Unpack the stuff, assumes the current directory is `scripts`
..\lib\7-Zip\7z.exe e "$env:TEMP\wxWidgets-3.2.6-headers.7z" "-o..\lib\wxWidgets-3.2.6\include\" -aoa
..\lib\7-Zip\7z.exe e "$env:TEMP\wxMSW-3.2.6_vc14x_x64_ReleaseDLL.7z" "-o..\lib\wxWidgets-3.2.6\lib\" -aoa