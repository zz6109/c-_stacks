#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>

int main()
{
    // 챕터 1
    // std::cout << "안녕" << CV_VERSION << std::endl;

    // 챕터 2
    // cv::Mat img;
    // std::cout << img.empty() << std::endl;
    // img = cv::imread("lena.bmp");
    // if (img.empty())
    // {
    //     std::cout << "이미지가 없음" << std::endl;
    //     return -1;
    // }

    // std::string windowName = "image";
    // cv::String windowName2 = "image2";

    // img = cv::imread("lena.bmp");
    // cv::imshow("image", img);
    // std::cout << "Hello OpenCV" << std::endl;
    // cv::waitKey(0);
    // return 0;

    // 챕터 3
    cv::Mat img;
    std::cout << img.empty() << std::endl;
    img = cv::imread("lena.bmp");
    if (img.empty())
    {
        std::cout << "Image is empty" << std::endl;
        return -1;
    }

    std::string windowName = "image";
    cv::String windowName2 = "image2";

    cv::imshow("image", img);
    std::cout << "Hello OpenCV" << std::endl;
    cv::imwrite("lena.jpg", img);
    int key;
    while (key != 'x')
    {
        key = cv::waitKey(0);
        std::cout << key << std::endl;
    }
    return 0;
}