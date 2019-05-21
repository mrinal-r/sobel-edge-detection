#include "sobel.h"

ostringstream err;

void info(){
    err << "\nUsage\tsobelEdgeDetection <imageName>";
    err << "\nWhere imageName has the form somefile.extn and is placed in the data folder";
}

void display(string windowName, Mat& image, bool display){
    imshow(windowName, image);
    if (display){
        string fileName = windowName+".jpeg";
        imwrite(fileName, image);
    }
}

int main(int argc, char *argv[]) {

    try{

        if (argc < 2){
            info();
            throw err.str();
        }

        string imageName = argv[1];

        string filename = "../../data/"+imageName;
        cout << "\nProcessing file " << filename;

        Mat image = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

        int ksize = 5; // -- avoid using 3 to avoid scharr for now -- //
        int scale = 1; // -- default
        int delta = 0; // -- defalut

        Mat edgy =sobelEdgeDetector(image, ksize, scale, delta);

        Mat combined = superimpose(image, edgy);

        display("Image", image, false);
        display("Edges", edgy, true);
        display("combined", combined, true);
        waitKey();

        cvDestroyAllWindows();

    }catch(string& errorMessage){
        cout << "\nError in main" << errorMessage;
        return -1;
    }

    return 0;
}