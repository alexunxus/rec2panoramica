# rec2panoramica

It is a side project for me to transform a normal(rectangular) image into a panoramic(circular) image. I found implementing through C++ is way faster than using Python. The concept is easy. We have to tell for each pixel on the target image, can where is the corresponding points on the source image.

# User Guide

Input image:
![alt text](./river.jpg?raw=true "River.jpg")

Output image:
![alt text](./panriver.jpg?raw=true "panriver.jpg")

1. clone this directory

> $ git clone https://github.com/alexunxus/rec2panoramica.git

2. install opencv3

> $ brew install opencv

If you cannot successfully install opencv, then checkout this page:
https://stackoverflow.com/questions/34340578/installing-c-libraries-on-os-x

3. open terminal and go to directory /rec2panoramica/

> $ cd ~/My/Path/To/rec2panoramica/

4. type make

> $ make

If you have not yet install GNU make, then

> $ brew install make

5. put your image into this directory and type

> $ ./myImg __yourjpgname__

6. your image will be stored in the same directory with prefix "pan"
