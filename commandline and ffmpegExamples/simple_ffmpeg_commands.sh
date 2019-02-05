#video resources:
#
# 
# Installing pro video formats - https://blairneal.com/installing-apple-pro-video-formats-without-fcpmotion-using-pacifist/
# https://duduf.com/easily-transcode-any-media-to-any-format-using-ffmpeg/
#

#want to add narration? try using the system speak unix command, 'say'
#to view other system speak voices, go to System Preferences-> Accessibility -> Speech
#output speech to aif file
#if on Windows, check out the following text to speech command line applications:
# http://espeak.sourceforge.net/index.html
# https://pythonprogramminglanguage.com/text-to-speech/
say -v Alex -o "output.aiff" "hello world"


#to view pixel formats and bit depths
ffmpeg -h encoder=libx264

#list all pixel formats pix_fmts
ffmpeg -pix_fmts


#use case: converting image sequence to .mp4 video
#official documentation: https://trac.ffmpeg.org/wiki/Create%20a%20video%20slideshow%20from%20images
#description: 
# An image sequence follows the filename pattern, defaultCanvas0-000000000.png (9 zeros)
# video codec is libx264
# pixel format yuv420p
# output file is named out.mp4
ffmpeg -i 'defaultCanvas0-%9d.png' -c:v libx264 -pix_fmt yuv420p out.mp4

#if you want your image sequence to start on a different number than index 0, use the -start_number parameter
ffmpeg -start_number 000000060 -i 'defaultCanvas-%9d.png' -c:v libx264 -pix_fmt yuv420p out.mp4


#Extract one image per second:
 ffmpeg -i video.webm -vf fps=1 image-%03d.png
#Extract one image from a specific time:
 ffmpeg -i video.webm -ss 00:00:10 -vframes 1 thumbnail.png


# Flip video  vertically:
 ffmpeg -i INPUT_VIDEO_PATH -vf vflip -c:a copy OUTPUT 
 #flip video horizontally:
 ffmpeg -i INPUT_VIDEO_PATH -vf hflip -c:a copy OUTPUT


# combine video with new audio
ffmpeg -i INPUT_VIDEO_PATH -i INPUT_AUDIO \
-c:v copy -c:a aac -strict experimental \
-map 0:v:0 -map 1:a:0 OUTPUT

# overlayed video, blurring background
ffmpeg -i INPUT_VIDEO_PATH \
-lavfi "color=color=black@.5:size=720x960:d=1[dark]; \
[0:v]crop=720:960[blurbase]; \
[blurbase]boxblur=luma_radius='min(h,w)/20':luma_power=1:chroma_radius='min(cw,ch)/20':chroma_power=1[blurred]; \
[blurred][dark]overlay[darkened]; \
[darkened]scale=1920:1080[bg]; \
[0:v]scale=-1:360[fg]; \
[bg][fg]overlay=(W-w)/2:(H-h)/2" \
OUTPUT_VIDEO_PATH

#side by side video
#to adjust spacing btwn vids add pixels to width and position
ffmpeg -i INPUT_VIDEO  \
  -i INPUT_VIDEO_2 \
  -filter_complex "color=white,[0:v:0]pad=iw*2:ih[bg]; [bg][1:v:0]overlay=w" \
  OUTPUT

#two videos overlayed
 ffmpeg \
-i INPUT_VIDEO_PATH_1 -i INPUT_VIDEO_PATH_2 \
-filter_complex " \
[0:v]setpts=PTS-STARTPTS, scale=480x360[top]; \
[1:v]setpts=PTS-STARTPTS, scale=480x360, \
format=yuva420p, colorchannelmixer=aa=0.5[bottom]; \
[top][bottom]overlay=shortest=1" \
-vcodec libx264 OUTPUT




#################################################
#Examples using lavfi input instead of video file
#################################################

#smptebars
ffmpeg -f lavfi -i "smptebars=duration=5:size=1280x720:rate=30" output.mp4

#to change the frame size, you must use the scale filter
#more info on aspect ratios and frame sizes: https://www.andrew.cmu.edu/user/lshea/2.Tech_PDFs/Pixel_Fun_Aspect-NonSquare.pdf
ffmpeg -f lavfi -i testsrc -t 30 -pix_fmt yuv420p -vf scale=720:540 testsrc.mp4

#lavfi input using a mandlebrat test pattern
ffmpeg -f lavfi -i mandelbrot -t 30 -pix_fmt yuv422p mandle.mp4

#conways game of life; play around with the s and scale parameters for sizing
ffmpeg -f lavfi -i 'life=s=60x60:death_color=#C83232:life_color=00ff00:ratio=.5:mold=10'\
  -sws_flags neighbor -vf scale=480:360,drawgrid=w=6:h=6 \
  -t 20 -pix_fmt yuv420p lifegame2.mp4

#analyze an audio file and output as video file

ffmpeg -f lavfi -i 'amovie=ambience.wav,asplit=2[out1][a]; [a]showspectrum=color=fire:scale=log:orientation=vertical:overlap=1:s=1024x1024[out0]' \
-pix_fmt yuv420p spectrum.mp4

#cell automata
#Other interesting cellauto rule values: 
#9, 18, 22, 26, 30, 41, 45, 50, 54, 60, 62, 
#73, 75, 77, 82, 86, 89, 90, 97, 99, 101, 102, 
#105, 107, 109, ​110 (default), 124, 126, 129, 131, 
#133, 135, 137, 145, 146, 149, 150, 151, 153, 154, 
#161, 167, 169, 181, 182, 183, 193, 195, 210, 218, 225
#The -profileoption is specific to the prores encoder, 
#it specifies the ProRes profile quality: 0 is Proxy, 1 is LT, 2 is Normal, and 3 is HQ.
ffmpeg -f lavfi -i cellauto=rule=123 -t 30 -pix_fmt yuv422p10 -vcodec prores -profile 3 -vf scale=480:360 cellautoma.mov


#Combining and concatenating files using ffmpeg
# depending on the media you are looking to concat, there are different methods
# these additional guides may be helpful to you:
# https://trac.ffmpeg.org/wiki/Concatenate
# https://trac.ffmpeg.org/wiki/Concatenate#differentcodec
# https://trac.ffmpeg.org/wiki/mmcat
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
