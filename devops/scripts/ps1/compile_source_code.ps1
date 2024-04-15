param(
    [string]$CMakeToolchainFile,
    [switch]$RunTests,
    [switch]$Help
)

function Show-Help {
    echo "Usage: .\compile_source_code.ps1 -CMakeToolchainFile <Path> [-RunTests] [-Help]"
    echo "  -CMakeToolchainFile <Path>   Path to CMAKE_TOOLCHAIN_FILE"
    echo "  -RunTests                    Run tests after building (optional)"
    echo "  -Help                        Display this help message"
}

if ($Help) {
    Show-Help
    exit
}

$currentDir = Get-Location
Set-Location -Path "$PSScriptRoot/../../.."

if (-not $CMakeToolchainFile) {
    $CMakeToolchainFile = Read-Host "Enter the path to CMakeToolchainFile, e.g. 'D:\c++ repos\dependencies\vcpkg\scripts\buildsystems\vcpkg.cmake'"
}
cmake -B build -DBUILD_LIB=ON -DBUILD_TEST=ON -DCMAKE_TOOLCHAIN_FILE="$CMakeToolchainFile" .
cmake --build build --parallel 8
if ($RunTests) {
    Set-Location -Path "build"
    ctest --verbose
}

Set-Location -Path $currentDir
