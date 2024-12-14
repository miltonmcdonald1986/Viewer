# First download the header files
Invoke-WebRequest https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.6/wxWidgets-3.2.6-headers.7z -OutFile "$env:TEMP\wxWidgets-3.2.6-headers.7z"

# Then, download the development files
Invoke-WebRequest https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.6/wxMSW-3.2.6_vc14x_x64_Dev.7z -OutFile "$env:TEMP\wxMSW-3.2.6_vc14x_x64_Dev.7z"

# Finally, download the Release DLLs
Invoke-WebRequest https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.6/wxMSW-3.2.6_vc14x_x64_ReleaseDLL.7z -OutFile "$env:TEMP\wxMSW-3.2.6_vc14x_x64_ReleaseDLL.7z"

# Unpack the stuff, assumes the current directory is `scripts`
..\lib\7-Zip\7z.exe x "$env:TEMP\wxWidgets-3.2.6-headers.7z" "-o..\lib\wxWidgets-3.2.6\" -aoa
..\lib\7-Zip\7z.exe x "$env:TEMP\wxMSW-3.2.6_vc14x_x64_Dev.7z" "-o..\lib\wxWidgets-3.2.6\" -aoa
..\lib\7-Zip\7z.exe x "$env:TEMP\wxMSW-3.2.6_vc14x_x64_ReleaseDLL.7z" "-o..\lib\wxWidgets-3.2.6\" -aoa