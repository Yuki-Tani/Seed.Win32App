$Alias = 'run'

function Start-UPDATENAME # TODO: update name
{
    & (Join-Path $ProjectRoot 'bin' 'x64' 'Debug' 'UPDATENAME.exe') # TODO: update name
}