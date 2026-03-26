param(
    [string]$id,
    [Parameter(ValueFromRemainingArguments=$true)]
    [string[]]$args
)

$file = Get-ChildItem -Path . -Recurse -Filter "$id*.cpp" | Select-Object -First 1

if (-not $file) {
    Write-Host "Arquivo com ID $id não encontrado." -ForegroundColor Red
    exit 1
}

$output = [System.IO.Path]::GetFileNameWithoutExtension($file.Name)

Write-Host "Compiling: $($file.Name) from $($file.Directory.Name)" -ForegroundColor Cyan

g++ $file.FullName -o $output

if ($LASTEXITCODE -ne 0) {
    Write-Host "Compilation Error." -ForegroundColor Red
    exit 1
}

Write-Host "Executing...`n" -ForegroundColor Green
& ".\$output.exe" $args

Write-Host "`nExecution Finished" -ForegroundColor Green

Write-Host "Deleting *.exe file..." -ForegroundColor Cyan
Remove-Item ".\$output.exe"