<#
Shell script with commandline arguments.
Formula:
1. write some code and save your file as a .ps1
2. In Powershell, set your script ExecutionPolicy to Unrestricted
    type: Set-ExecutionPolicy Unrestricted
3. Execute the powershell script by typing .\shellscript_w_commandlineargs.ps1 
#>
echo "Simple script with positional parameters"
echo "First Argument: " $Args[0]
echo $Args[1]
echo $Args[2]
