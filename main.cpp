#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cv.h"
#include <math.h>
#include "highgui.h"

using namespace std;

int main(int argc, char ** argv){

  CvCapture * camera = 0;
  IplImage * image = 0;
  int i, j, k;
  int frame_count = 0;
  int mean = 0, count = 0;
  int threshold = 10;
  int old_k = 0;
  char c;

  camera = cvCaptureFromCAM(CV_CAP_ANY);

  if (!camera){
    fprintf(stderr, "Could not interface with a camera.\n");
    return -1;
  }

  cvNamedWindow("grey_image", CV_WINDOW_AUTOSIZE);

  for (frame_count = 0; frame_count < 600; frame_count++){

    fprintf(stdout, "Frame %d\n", frame_count);

    image = cvQueryFrame(camera);

    if (!image) {
      fprintf(stderr, "Capture Failed\n");
      continue;
    }
    for(i=0; i < image->height; i++){
      for(j=0; j < image->width; j++){

        k = ( (image->imageData+i*image->widthStep)[j*image->nChannels+0]
            + (image->imageData+i*image->widthStep)[j*image->nChannels+1]
            + (image->imageData+i*image->widthStep)[j*image->nChannels+2])/3;
        if (k > old_k + threshold || k < old_k - threshold){
          (image->imageData+i*image->widthStep)[j*image->nChannels+0] = (unsigned char)255;
          (image->imageData+i*image->widthStep)[j*image->nChannels+1] = (unsigned char)255;
          (image->imageData+i*image->widthStep)[j*image->nChannels+2] = (unsigned char)255;
        }
        else{
          (image->imageData+i*image->widthStep)[j*image->nChannels+0] = (unsigned char)0;
          (image->imageData+i*image->widthStep)[j*image->nChannels+1] = (unsigned char)0;
          (image->imageData+i*image->widthStep)[j*image->nChannels+2] = (unsigned char)0;
        }
        old_k = k;
      }
    }

    cvShowImage("grey_image", image);
    cvWaitKey(0);
    cvDestroyWindow("grey_image");
  }

  cvReleaseCapture(&camera);

  return 0;
}
