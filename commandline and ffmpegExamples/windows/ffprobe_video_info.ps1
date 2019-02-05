#ffprobe is a utility that comes with ffmpeg. You can use it to get info on video files.
#Here we probe an input video and filter the result to show duration.
#we use the pipe | character to pass ffprobe into powershell's Select-String method
ffprobe -i INPUT_VIDEO_FILE -show_format -v quiet | Select-String -Pattern "duration=.*"
