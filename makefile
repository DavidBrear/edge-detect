LIBS=-L/usr/local/Cellar/opencv/2.4.6.1/lib -l opencv_calib3d -l opencv_contrib -l opencv_core -l opencv_features2d -l opencv_flann -l opencv_gpu -l opencv_highgui -l opencv_imgproc -l opencv_legacy -l opencv_ml -l opencv_nonfree -l opencv_objdetect -l opencv_ocl -l opencv_photo -l opencv_stitching -l opencv_superres -l opencv_ts -l opencv_video -l opencv_videostab
INCLUDES=-I/usr/local/Cellar/opencv/2.4.6.1/include/opencv -I/usr/local/Cellar/opencv/2.4.6.1/include

all:
	g++ ${INCLUDES} ${LIBS} main.cpp -o edge-detect.o

clean:
	rm ./*.o
