#!/bin/bash
: '
Simple shell script in Bash. Formula:
1. Add the "shebang" at the top of your script: #!/bin/bash
2. Write some code
3. In your terminal, cd into the directory containing your bash script, then 
	run chmod +x shellscript_loop_arguments.sh
4. Now you can run your script by executing ./shellscript_loop_arguments.sh 
	with your arguments separated by spaces in your terminal
'
echo "looping through all arguments"
# Loop until all parameters are used up
while [ "$1" != "" ]; do
    echo "Parameter: $1"
    echo "You now have $# positional parameters"
    # Shift all the parameters down by one
    shift

done