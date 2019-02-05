#!/bin/bash
: '
Simple shell script in Bash. Formula:
1. Add the "shebang" at the top of your script: #!/bin/bash
2. Write some code
3. In your terminal, cd into the directory containing your bash script, then 
	run chmod +x simple_shell.sh
4. Now you can run your script by executing ./shellscript_directorypath_argument.sh 
	with your arguments separated by spacesin your terminal
'
echo "Checking whether argument is directory path"
echo 'argument $1 = ' $1
if [ -d "$1" ]
	then echo "$1 is a directory!"
elif [ -f "$1" ]
	then echo "$1 is a file!"
else
	echo "argument is not a directory nor file!";
	exit 1;
fi
