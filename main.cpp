//
//  main.cpp
//  rec2panoramic
//
//  Created by mac of alex on 2018/2/26.
//  Copyright © 2018年 mac of alex. All rights reserved.
//

#include <iostream>
#include "imgMgr.h"
#include "myUsage.h"
#include "myString.cpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

static void// this function can only be access in this file due to static statement
usage()
{
    cout << "Usage: imgMgr [ imgfile.jpg | imgfile.png ]" << endl;
}

static void
myexit()
{
    usage();
    exit(-1);
}

extern imgMgr * iMgr;

int main(int argc, const char * argv[]) {
    MyUsage myUsage;
    myUsage.reset();
    if (argc == 2) {
        if(!iMgr->read(argv[1])) {
            cerr << "Image file "<<argv[1]<<" doesn't exist!"<< endl;
            myexit();
        }
    }
    else {
        cerr << "Error: illegal number of argument (" << argc << ")!!\n";
        myexit();
    }
    // test to show image
    //iMgr->show();
    iMgr->rec2panoramic();
    iMgr->showOutputImg();
    
    myUsage.report(true, true);
}
