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
    _mapx.create(_img->size(), CV_32FC1);//why CV_32FC1 ??
    _mapy.create(_img->size(), CV_32FC1);
    rec2circle();
    _oImg = new cv::Mat(_img->rows*2, _img->rows*2, _img->type());
    //*_oImg = cv::Scalar(255,255,255,0);
    cv::remap(*_img, *_oImg, _mapx, _mapy, CV_INTER_LINEAR, BORDER_CONSTANT);
}
void
imgMgr::rec2circle() {
    int i, j;
    size_t a = _img->cols;
    size_t b = _img->rows;
    assert(a!=0 && b!=0);
    i = j = 0;
    for(i = 0; i < _img->cols; i++) {
        for (j = 0; j < _img->rows; j++) {
            _mapx.at<float>(j, i) = (b - j -1) * cos(PI*i/a) + b;
            _mapy.at<float>(j, i) = (b - j -1) * sin(PI*i/a) + b;
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
    resizeWindow(_name, 1, 1);
    imshow(_name, *_oImg);
    waitKey(0);
}
void
imgMgr::saveOutput() const {
    //some problem with imwrite
    imwrite(_name+"_pan", *_oImg);
    
}

