# Download the binaries
Invoke-WebRequest https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0-win32.zip -OutFile "$env:TEMP\glew-2.2.0-win32.zip"

# Extract to lib folder
Expand-Archive -Path "$env:TEMP\glew-2.2.0-win32.zip" -DestinationPath "..\lib"
