# Download the binaries
Invoke-WebRequest https://github.com/g-truc/glm/releases/download/1.0.1/glm-1.0.1-light.7z -OutFile "$env:TEMP\glm-1.0.1-light.7z"

# Extract to lib folder
..\lib\7-Zip\7z.exe x "$env:TEMP\glm-1.0.1-light.7z" "-o..\lib\glm-1.0.1-light\" -aoa