$Alias = 'build'

function Build-UPDATENAME # TODO: update name + file name
{
    param(
        [switch]$Restore
    )

    if ($Restore)
    {
        & MSBuild.exe -t:Restore
    }

    & MSBuild.exe $ProjectRoot
}