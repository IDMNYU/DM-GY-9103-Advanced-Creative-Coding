#!/bin/bash
: '
Simple shell script in Bash. Formula:
1. Add the "shebang" at the top of your script: #!/bin/bash
2. Write some code
3. In your terminal, cd into the directory containing your bash script, then 
	run chmod +x shellscript_w_commandlineargs.sh
4. Now you can run your script by executing ./shellscript_w_commandlineargs.sh 
	with your arguments separated by spaces afterward in your terminal
'
echo "Simple script with positional parameters"
echo '$0 = ' $0
echo '$1 = ' $1
echo '$2 = ' $2
echo '$3 = ' $3