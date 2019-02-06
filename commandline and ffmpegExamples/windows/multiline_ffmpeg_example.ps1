# overlayed video, blurring background
ffmpeg -i INPUT_VIDEO_PATH `
-lavfi "color=color=black@.5:size=720x960:d=1[dark]; `
[0:v]crop=720:960[blurbase]; `
[blurbase]boxblur=luma_radius='min(h,w)/20':luma_power=1:chroma_radius='min(cw,ch)/20':chroma_power=1[blurred]; `
[blurred][dark]overlay[darkened]; `
[darkened]scale=1920:1080[bg]; `
[0:v]scale=-1:360[fg]; `
[bg][fg]overlay=(W-w)/2:(H-h)/2" `
OUTPUT_VIDEO_PATH
