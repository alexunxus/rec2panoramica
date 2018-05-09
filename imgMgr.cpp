#include "imgMgr.h"
#include <math.h>

#define PI 3.14159265

using namespace std;
using namespace cv;

imgMgr * iMgr = new imgMgr;

imgMgr::~imgMgr() { if (_img != NULL) delete _img; _img = NULL; }

bool
imgMgr::read(const char s[]) {
    if (_img ==NULL) {
        _img = new cv::Mat; }
    else {
        cout << "Replacing: replace " <<string(s) << " for " << _name <<endl;
        delete _img; }
    *_img = cv::imread(s, CV_LOAD_IMAGE_COLOR);
    _name = string(s);
    if(! (*_img).data){
        cout << "Image " << string(s) << " doesn't exit!"<< endl;
        delete _img;
        _img = NULL;
        _name = "";
        return false;
    }
    return true;
}

void
imgMgr::rec2panoramic() {
    _mapx.create(_img->rows*2, _img->rows*2, CV_32FC1);//why CV_32FC1 ??
    _mapy.create(_img->rows*2, _img->rows*2, CV_32FC1);
	//_img->at<cv::Scalar>(0, 0) = cv::Scalar(255, 255, 255, 0);
	
	rec2circle();
    _oImg = new cv::Mat(_img->rows*2, _img->rows*2, _img->type());
    cv::remap(*_img, *_oImg, _mapx, _mapy, CV_INTER_LINEAR, BORDER_CONSTANT);
}


void
imgMgr::invert() {
    size_t i, j;
	for(i = 0; i < _img->cols; i++) {
	    for(j = 0; j < _img->rows; j++) {
		    _mapx.at<float>(j, i) = i;
			_mapy.at<float>(j, i) = _img->rows - j;
		}
	}
}

void
imgMgr::rec2circle() {
    int i, j;
    float a = _img->cols;
    float b = _img->rows;
    assert(a!=0 && b!=0);
	cout << "row = " << _img->rows << endl;
	cout << "col = " << _img->cols << endl;
	// x' = (b-1-y)cos(pi*x/(a-1)) + b
	// y' = (b-1-y)sin(pi*x/(a-1)) + b
    for(i = 0; i < 2*b; i++) {// i is x
        for (j = b; j < b+sqrt((b-1)*(b-1)-(i-b)*(i-b)); j++) {//j is y
			if(i >=b ) {
				_mapx.at<float>(j, i)=_mapx.at<float>(2*b-j, i)=(a-1)/PI*atan((j-b)/(i-b));			
			}
            else
				_mapx.at<float>(j, i)=_mapx.at<float>(2*b-j, i)=(a-1)/PI*(PI + atan((j-b)/(i-b)));
			_mapy.at<float>(j, i)=_mapy.at<float>(2*b-j, i)= b-1 - sqrt((i-b)*(i-b)+(j-b)*(j-b));
        }
    }
}

void
imgMgr::show() {
    namedWindow(_name, WINDOW_AUTOSIZE);
    imshow(_name, *_img);
    waitKey(0);
}
void
imgMgr::showOutputImg() const {
    namedWindow(_name, WINDOW_AUTOSIZE);
    resizeWindow(_name, 60, 60);
    imshow(_name, *_oImg);
    waitKey(0);
	saveOutput();
}
void
imgMgr::saveOutput() const {
    //some problem with imwrite, solved by changing g++ to clang++
    imwrite("pan"+_name, *_oImg);
    
}

