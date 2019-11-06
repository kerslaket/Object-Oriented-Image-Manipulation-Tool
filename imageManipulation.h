#pragma once
#include <vector>
#include <math.h>
#include "ReadWritePPm.h"
#include "ImageZoom.h"
class imageManipulation
{

private:
	//private attributes for storing images
	Image *img1 = new Image(3264, 2448);
	Image *img2 = new Image(3264, 2448);
	Image *img3 = new Image(3264, 2448);;
	Image *img4 = new Image(3264, 2448);
	Image *img5 = new Image(3264, 2448);
	Image *img6 = new Image(3264, 2448);
	Image *img7 = new Image(3264, 2448);
	Image *img8 = new Image(3264, 2448);
	Image *img9 = new Image(3264, 2448);
	Image *img10 = new Image(3264, 2448);
	Image *imgZoom = new Image(750, 750);
	Image *medianBlendedImage = new Image(3264, 2448); // create new image
	Image *meanBlendedImage = new Image(3264, 2448); // create new image
	Image *sigmaClippedImage = new Image(3264, 2448); // create new image
	ImageZoom *ZoomedImage2 = new ImageZoom(750 * 2, 750 * 2,2); // create new image
	ImageZoom *ZoomedImage4 = new ImageZoom(750 * 4, 750 * 4,4); // create new image

	std::vector<Image> images;//private vector for storing all the image together


public:
	//default constructor
	imageManipulation();

	//accessor functions
	void setImg1(char* s);
	void setImg2(char* s);
	void setImg3(char* s);
	void setImg4(char* s);
	void setImg5(char* s);
	void setImg6(char* s);
	void setImg7(char* s);
	void setImg8(char* s);
	void setImg9(char* s);
	void setImg10(char* s);
	void setImgZoom(char* s);

	Image getImg1();
	Image getImg2();
	Image getImg3();
	Image getImg4();
	Image getImg5();
	Image getImg6();
	Image getImg7();
	Image getImg8();
	Image getImg9();
	Image getImg10();
	Image getImgZoom();

	Image getMedianImage();
	Image getMeanImage();
	Image getSigmaImage();
	ImageZoom getZoom2();
	ImageZoom getZoom4();
	
	//member functions
	void setImagesVector();//puts all the images in a vector
	void meanMedian(int pixels, bool mean);//writes either the mean or the median blended image to a file
	int medianBlending(std::vector<int> onePixel);//finds the median
	int meanBlending(std::vector<int> onePixel);//finds the mean
	float standardDeviation(std::vector<int> onePixel);//finds the standard deviation
	void sigmaClipping(int pixels);//writes the sigma clipped mean blended image
	void twoTimesZoom();//writes a 2 times scaled image to a file
	void fourTimesZoom();//writes a 4 times scaled image to a file
	
	//destructor
	~imageManipulation();


};

