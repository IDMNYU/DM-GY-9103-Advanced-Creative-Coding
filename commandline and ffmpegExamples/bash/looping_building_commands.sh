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
echo "looping through all files in $1"
if [ -d "$1" ]
	then cd $1;
		INPUTS=""
		#try replacing * with *.mov, to filter by file extension 
		for f in *; do
			INPUTS+="-i $f "
		done
		echo $INPUTS

fi