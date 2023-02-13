# Seed.Win32App

## Getting Started
### Update File Names/Contents
Decide .exe file name and update files and contents

- `UPDATENAME.vcxproj`
- `UPDATENAME.psm1`
- `pwsh/Build-UPDATENAME.ps1` and its content
- `pwsh/Start-UPDATENAME.ps1` and its content

## Build
1. (Once, device) Install VS2022 with "C++ development environment".
1. (Once, device) Set environment path to "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\MSBuild\Current\Bin" for msbuild.
1. (Once, pwsh) In pwsh, `Import-Module .\(UPDATENAME).psm1`.
1. In pwsh, `build`. At the first time, `build -restore` to install necessary packages.
1. Output files are under `bin/(arch)/(flavor)/`.

## Run output exe
1. In pwsh, `run`.
