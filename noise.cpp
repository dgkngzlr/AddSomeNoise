#include "noise.h"

cv::Mat noise::add_gaussian_noise(cv::Mat &img, double stddev) {

    cv::Mat out_img;
    cv::Mat norm_img;
    normalize(img, norm_img, 0.0, 1.0, cv::NORM_MINMAX, CV_64F);

    cv::Mat noise(norm_img.size(), norm_img.type());
    cv::randn(noise, 0, stddev);

    out_img = norm_img + noise;

    normalize(out_img, out_img, 0.0, 1.0, cv::NORM_MINMAX, CV_64F);
    out_img *= 255;
    out_img.convertTo(out_img, CV_8U);

    return  out_img;
}

cv::Mat noise::add_sap_noise(cv::Mat &img, double amount) {

    int num_salt_px = static_cast<int>(img.size().area() * amount / 2);
    int num_pepper_px = static_cast<int>(img.size().area() * amount / 2);
    std::cout << "Target : " << num_pepper_px << std::endl;
    cv::Mat out_img = img.clone();

    std::random_device rd1; // obtain a random number from hardware
    std::mt19937 gen1(rd1()); // seed the generator
    std::uniform_int_distribution<> distr1(0, out_img.size().height-1); // define the range

    std::random_device rd2; // obtain a random number from hardware
    std::mt19937 gen2(rd1()); // seed the generator
    std::uniform_int_distribution<> distr2(0, out_img.size().width-1); // define the range

    for (int n = 0; n < num_salt_px ; n++)
    {
        int i = distr1(gen1);
        int j = distr2(gen2);

        // Add salt noise
        out_img.at<cv::Vec3b>(i, j) = cv::Vec3f(255, 255,255);
    }

    for (int n = 0; n < num_pepper_px ; n++)
    {
        int i = distr1(gen1);
        int j = distr2(gen2);

        // Add pepper noise
        out_img.at<cv::Vec3b>(i, j) = cv::Vec3f(0,0,0);
    }

    return  out_img;
}
