#!/bin/bash
#this script batch transcodes files to the same codec
#then concatenates them
if [ -d "$1" ]
    then cd $1;
    FILE_COUNT=$#
    INPUTS=""
    FILTER=""
    INDEX=0
    #print the working directory and assign to a
    #variable
    ABS_PATH=$(pwd)
    
    #make a tmp directory if it doesn't already exist
    mkdir -p "tmp"

    #first loop through all the mp4 files in our directory
    #and convert them all to quicktime files
    #after each file conversion add that filename to a list
    #for concatenation
    #Careful: this can take a while depending on how many videos/
    #how large the video files are
    for i in *.mp4;do
        echo $i
        # the backtick ` symbol means to evaluate the code inside first
        name=`echo $i | cut -d'.' -f1`;
  		#convert the existing file to an h264 codec
        ffmpeg -i "$i" "tmp/${name}.mov";
        #then add the name and path to a concatenation file
        echo "file '$ABS_PATH/tmp/$name.mov'" >> files_to_concat.txt;
        echo "added $name to files_to_concat.txt"
	done

	#Now concatenate all files into one large video file
	ffmpeg -f concat -safe 0 -i files_to_concat.txt -c copy concat_output.mov
    
    #clean up our tmp directory by removing it
    rm -rf tmp;
fi

