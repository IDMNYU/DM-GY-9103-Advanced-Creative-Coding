param (
    [string]$directory = ""
 )
<#
Shell script with commandline arguments.
Formula:
1. write some code and save your file as a .ps1
2. In Powershell, set your script ExecutionPolicy to Unrestricted
    type: Set-ExecutionPolicy Unrestricted
3. Execute the powershell script by typing .\loop_files_in_directory.ps1 -directory "path/to/folder" 
VERY IMPORTANT! Powershell parameters must be listed on first line of script
#>
echo "Looping through all files in " $directory
 
if ($directory) {
    cd $directory;
    # instead of listing all files, try filtering like so: Get-ChildItem $directory -Filter *.mp4
    $files = Get-ChildItem $directory

    for($i=0; $i -lt $files.Count; $i++){
        $filepath = $files[$i].FullName
        $filename = $files[$i].BaseName
        $extension = $files[$i].Extension
        echo $filepath
        echo $filename
        echo $extension
    }
}

    