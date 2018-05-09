# rec2panoramic-
C++ version of rec2panoramic

Input image:
![alt text](./river.jpg?raw=true "River.jpg")

Output image:
![alt text](./panriver.png?raw=true "panriver.jpg")

1. One first put the image one wants to process in the same directory
2. Secondly, one opens terminal and changes directory (using cd) to the directory containing this python file
3. One run the python program:(typing as below)
   python3 rec2panoramic.py
* If you didn't install python3 yet, please first install homebrew and then type "brew install python3" in your terminal.
4. The program will ask you to input the file name (without .jpg), for example:(if I have a jpg file named river.jpg in the same directory)
   Enter jpg filename(should not contain .jpg): river
5. Then the program will ask you if you want to invert the image so that the top of the image will be projected to "center" of output image
   Do you want to turn the photo upside-down?[type Yes]
* type words other than yes will NOT invert the image
6. The program finally ask you the output format. If one type nothing, the default output format will be .png
