#ifndef NOISE_H
#define NOISE_H

#include <opencv2/core/core.hpp>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

namespace noise
{
    cv::Mat add_gaussian_noise(cv::Mat& img, double stddev);
    cv::Mat add_sap_noise(cv::Mat& img, double amount);
    cv::Mat add_poisson_noise(cv::Mat& img, double mean);
    cv::Mat add_speckle_noise(cv::Mat& img);
    cv::Mat add_uniform_noise(cv::Mat& img);
    cv::Mat add_periodic_noise(cv::Mat & img, double v_str, double h_str);
}

#endif //NOISE_H
