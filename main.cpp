#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    int res = 0;

    cv::VideoCapture cap(0);

    if(!cap.isOpened()) {
        std::cerr << "Error: Unable to open camera" << std::endl;
        return -1;
    }       

    cv::Mat frame;

    while (true) {
        cap.read(frame);

        cv::imshow("Camera Feed", frame);
    
        if (cv::waitKey(30) == 27) {
            break;
        }
    }

    return res;
}

// g++ -o  hand_recognition main.cpp $(pkg-config --cflags --libs opencv4)