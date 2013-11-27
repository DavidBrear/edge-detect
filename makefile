CC=g++

LIBS= -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
LIBPATH= -L /usr/local/lib

INCLUDES= -I /usr/local/include/opencv -I /usr/local/include

all:
	$(CC) main.cpp $(INCLUDES) $(LIBS) $(LIBPATH) -o camera2.o
clean:
	rm *.o