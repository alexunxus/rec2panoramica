#ifndef IMG_MGR_H
#define IMG_MGR_H

#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

class imgMgr
{
public:
    imgMgr(): _img(NULL), _oImg(NULL){}
    ~imgMgr();
    
    bool read(const char s[]);
    void show();
    
    //Related to rec2panoramic
    void rec2panoramic();
    
    //Output img
    void showOutputImg() const;
    void saveOutput() const;
    
private:
    cv::Mat *   _img;
    cv::Mat *   _oImg;
    cv::Mat     _mapx;
    cv::Mat     _mapy;
    string      _name;
    
    //Related to mapping
    void rec2circle();
	void trimCirBorder();
	void invert();
    
    
    
};

#endif //IMG_MGR_H
