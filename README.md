# sobel-edge-detection
Detect edges in an image using OpenCV implementation of Sobel filter

##### To run the project
Place the test image in the `data` folder.
```
cd source/build
cmake ..
make
./sobelEdgeDetection somefile.extension
```

##### Sample output

Sample input

![alt text](https://github.com/mrinal-r/sobel-edge-detection/blob/master/data/dog.jpeg "Input Image")



Detected edges (X and Y gradient combined)

![alt text](https://github.com/mrinal-r/sobel-edge-detection/blob/master/sample/Edges.jpeg "Edges Image")



Edges superimposed on the original image

![alt text](https://github.com/mrinal-r/sobel-edge-detection/blob/master/sample/combined.jpeg "Combined Image")



##### References
[OpenCV documentation](https://docs.opencv.org/3.4.3/d2/d2c/tutorial_sobel_derivatives.html)
