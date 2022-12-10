#include "noise.h"

cv::Mat noise::add_gaussian_noise(cv::Mat &img, double stddev) {

    // Convert image to the double
    cv::Mat out_img;
    cv::Mat norm_img;
    img.convertTo(norm_img, CV_64FC3);
    norm_img = norm_img / 255;

    // Generate normal noise
    cv::Mat noise(norm_img.size(), norm_img.type());
    cv::randn(noise, 0, stddev);

    out_img = norm_img + noise;

    // Convert double to the 8-bit unsigned
    normalize(out_img, out_img, 0.0, 1.0, cv::NORM_MINMAX, CV_64FC3);
    out_img *= 255;
    out_img.convertTo(out_img, CV_8UC3);

    return  out_img;
}

cv::Mat noise::add_sap_noise(cv::Mat &img, double amount) {

    // Amount of salt and pepper pixels
    int num_salt_px = static_cast<int>(img.size().area() * amount / 2);
    int num_pepper_px = static_cast<int>(img.size().area() * amount / 2);

    cv::Mat out_img = img.clone();

    // Obtain a random number from hardware
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_int_distribution<> distr1(0, out_img.size().height-1);

    // Obtain a random number from hardware
    std::random_device rd2;
    std::mt19937 gen2(rd2());
    // Define the range
    std::uniform_int_distribution<> distr2(0, out_img.size().width-1);

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

cv::Mat noise::add_poisson_noise(cv::Mat& img, double mean) {

    // Convert image to the double
    cv::Mat out_img;
    cv::Mat norm_img;
    img.convertTo(norm_img, CV_64FC3);
    norm_img = norm_img / 255;

    // Obtain a random number from hardware
    cv::Mat noise(norm_img.size(), CV_64FC3);
    std::random_device rd;
    std::mt19937 gen(rd());

    std::poisson_distribution<int> dist(mean*255);

    for (int i = 0 ; i < norm_img.size().height ; i++)
    {
        for (int j = 0 ; j < norm_img.size().width ; j++)
        {
            auto poisson_val = static_cast<double>(dist(gen));
            noise.at<cv::Vec3d>(i, j) = cv::Vec3d(poisson_val,poisson_val,poisson_val);
        }
    }

    normalize(noise, noise, 0.0, 1.0, cv::NORM_MINMAX, CV_64FC3);
    out_img = norm_img + noise;

    // Convert double to the 8-bit unsigned
    normalize(out_img, out_img, 0.0, 1.0, cv::NORM_MINMAX, CV_64FC3);
    out_img *= 255;
    out_img.convertTo(out_img, CV_8UC3);

    return  out_img;
}

cv::Mat noise::add_uniform_noise(cv::Mat& img) {

    // Convert image to the double
    cv::Mat out_img;
    cv::Mat norm_img;
    img.convertTo(norm_img, CV_64FC3);
    norm_img = norm_img / 255;

    // Generate uniform noise
    cv::Mat noise(norm_img.size(), CV_64FC3);
    cv::randu(noise,0,1);

    out_img = norm_img + noise;

    // Convert double to the 8-bit unsigned
    normalize(out_img, out_img, 0.0, 1.0, cv::NORM_MINMAX, CV_64FC3);
    out_img *= 255;
    out_img.convertTo(out_img, CV_8UC3);

    return out_img;
}

cv::Mat noise::add_periodic_noise(cv::Mat & img, double v_str, double h_str) {

    // Convert image to the double
    cv::Mat out_img;
    cv::Mat norm_img;
    img.convertTo(norm_img, CV_64FC3);
    norm_img = norm_img / 255;

    // Generate meshgrid in 2D
    cv::Mat xx, yy;
    std::vector<int> t_x, t_y;
    for (int i = 0; i < norm_img.size().width; i++) t_x.push_back(i);
    for (int i = 0; i < norm_img.size().height; i++) t_y.push_back(i);
    xx = cv::Mat(t_x);
    yy = cv::Mat(t_y);

    cv::repeat(xx.reshape(1,1), (int)yy.total(), 1, xx);
    cv::repeat(yy.reshape(1,1).t(), 1, (int)xx.total(), yy);

    cv::Mat buf1[] = {xx, xx, xx};
    cv::merge(buf1, 3, xx);
    cv::Mat buf2[] = {yy, yy, yy};
    cv::merge(buf2, 3, yy);

    xx.convertTo(xx, CV_64FC3);
    yy.convertTo(yy, CV_64FC3);

    // Add vertical periodic noise to image
    cv::Mat noise_v = cv::Mat(xx.size(), CV_64FC3);
    double freq = static_cast<double>(noise_v.size().width) / 4.0;
    for (int i = 0 ; i < noise_v.size().height ; i++)
    {
        for (int j = 0 ; j < noise_v.size().width ; j++)
        {
            cv::Vec3d pxs = xx.at<cv::Vec3d>(i , j);
            double b_val = v_str * cos(freq * 3.14 * pxs[0]);
            double g_val = v_str * cos(freq * 3.14 * pxs[1]);
            double r_val = v_str * cos(freq * 3.14 * pxs[2]);
            noise_v.at<cv::Vec3d>(i , j) = {b_val, g_val, r_val};
        }
    }

    // Add horizontal periodic noise to image
    cv::Mat noise_h = cv::Mat(xx.size(), CV_64FC3);
    freq = static_cast<double>(noise_h.size().height) / 4.0;
    for (int i = 0 ; i < noise_h.size().height ; i++)
    {
        for (int j = 0 ; j < noise_h.size().width ; j++)
        {
            cv::Vec3d pxs = yy.at<cv::Vec3d>(i , j);
            double b_val = h_str * sin(freq * 3.14 * pxs[0]);
            double g_val = h_str * sin(freq * 3.14 * pxs[1]);
            double r_val = h_str * sin(freq * 3.14 * pxs[2]);
            noise_h.at<cv::Vec3d>(i , j) = {b_val, g_val, r_val};
        }
    }

    out_img = norm_img  + noise_v + noise_h;

    // Convert double to the 8-bit unsigned
    normalize(out_img, out_img, 0.0, 1.0, cv::NORM_MINMAX, CV_64FC3);
    out_img *= 255;
    out_img.convertTo(out_img, CV_8UC3);

    return out_img;
}

cv::Mat noise::add_speckle_noise(cv::Mat& img) {

    // Convert image to the double
    cv::Mat out_img;
    cv::Mat norm_img;
    img.convertTo(norm_img, CV_64FC3);
    norm_img = norm_img / 255;

    cv::Mat noise(norm_img.size(), CV_64FC3);
    cv::randn(noise,0.5,0.1);

    // Make multiplicative noise
    out_img = norm_img.mul(noise);

    // Convert double to the 8-bit unsigned
    normalize(out_img, out_img, 0.0, 1.0, cv::NORM_MINMAX, CV_64FC3);
    out_img *= 255;
    out_img.convertTo(out_img, CV_8UC3);

    return out_img;
}