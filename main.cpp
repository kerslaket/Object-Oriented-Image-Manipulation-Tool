//main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include "ReadWritePPm.h"
#include "ImageZoom.h"
#include "imageManipulation.h"

//Program for image stacking and scaling

int main()
{
	//Output program title to console
	std::cout << "************************************" << std::endl;
	std::cout << "Image Stacker / Image Scaler" << std::endl;
	std::cout << "************************************" << std::endl;

	//Instansiates a new instance of the imageManipulation Class named images 
	imageManipulation *images = new imageManipulation();

	images->meanMedian(10, false);//finds the median blend of all the images
	images->meanMedian(10, true);//finds the mean of all the iimages
	images->sigmaClipping(10);//finds the sigma clipped mean of all the images
	images->twoTimesZoom();//Scales the image to twice the resolution
	images->fourTimesZoom();//Scales the image to four times the resolution

	Image testImage = images->getImg1();//instanciates a new instance of the image class with the get function from the imageManipulation object
	testImage.imgInfo();//demonstrates the imgInfo member function
	testImage.~Image();//destructor for image instance

	ImageZoom testZoomImage = images->getZoom2();//instanciates a new instance of the imageZoom class with the get function from the imageManipulation object
	testZoomImage.imgInfo();//demonstrates the polymorphed imgInfo member function
	testZoomImage.~ImageZoom();//destructor for imageZOom instance

	images->~imageManipulation();//destructor for the imageManipulation object

	//pauses system
	system("pause");
	return 0;
}







