# Download the binaries
Invoke-WebRequest https://github.com/gabime/spdlog/archive/refs/tags/v1.15.0.zip -OutFile "$env:TEMP\v1.15.0.zip"

# Extract to lib folder
Expand-Archive -Path "$env:TEMP\v1.15.0.zip" -DestinationPath "..\lib"