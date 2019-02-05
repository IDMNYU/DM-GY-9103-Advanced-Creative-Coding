#!/bin/bash
if [ -d "$1" ]
    then cd $1;
    FILE_COUNT=$#
    INPUTS=""
    FILTER=""
    INDEX=0
    for FNAME in *.mp4; do
        echo "Processing ${FNAME}"
        INPUTS+="-i $FNAME "
        FILTER+="[${INDEX}:v:0][${INDEX}:a:0]"
        let INDEX+=1
    done

    COMMAND="ffmpeg ${INPUTS} \
        -filter_complex '${FILTER} \
        concat=n=${INDEX}:v=1:a=1[v][a]' \
        -map '[v]' -map '[a]' \
        ./ffmpeg-concat-output.mov"

    #   -af 'volume=15dB' # won't work with -filter_complex
    #echo "${COMMAND}"
    bash -c "${COMMAND}"
fi

# ffmpeg -i input0.wav -i input1.wav -filter_complex "[0:a][1:a]concat=n=2:v=0:a=1[a]" -map "[a]" output.wav
