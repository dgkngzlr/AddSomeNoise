#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

#include "noise.h"

using namespace std;
namespace po = boost::program_options;

int main(int argc, const char *argv[]) {

    po::options_description description("Add Some Noise Program Usage:");

    description.add_options()
            ("help", "Display this help message")
            ("path", po::value<string>(), "Input image file path")
            ("gaussian", "Add gaussian noise to image")
            ("sap", "Add salt & pepper noise to image")
            ("poisson", "Add poisson noise to image")
            ("speckle", "Add speckle noise to image")
            ("uniform", "Add speckle noise to image")
            ("periodic", "Add periodic noise to image")
            ("stddev", po::value<double>()->default_value(0.1), "Gaussian standard deviation, default is 0.1")
            ("amount", po::value<double>()->default_value(0.05), "Amount of salt & pepper, default is 0.05");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(description).run(), vm);
    po::notify(vm);

    cv::Mat img;
    cv::Mat out_img;
    cv::Mat norm_img;

    string img_path;
    string img_ext;
    string img_name;

    if (vm.count("help"))
    {
        cout << description << endl;
    }

    if (vm.count("path"))
    {
        img_path = vm["path"].as<string>();

        vector<string> path_tokens;
        vector<string> file_tokens;
        boost::split(path_tokens,img_path,boost::is_any_of("\\"));
        boost::split(file_tokens,path_tokens[path_tokens.size()-1],boost::is_any_of("."));

        img_name = file_tokens[0];
        img_ext = file_tokens[file_tokens.size()-1];

        img = cv::imread(img_path, cv::IMREAD_COLOR);

        img_path = "";
        for (int i = 0; i < path_tokens.size()-1; i++)
        {
            img_path += path_tokens[i] + "\\";
        }
    }

    if (vm.count("gaussian"))
    {
        double stddev = vm["stddev"].as<double>();
        out_img = noise::add_gaussian_noise(img, stddev);

        cv::imwrite(img_path+img_name+"_gaussian."+img_ext, out_img);
    }

    if (vm.count("sap"))
    {
        double amount = vm["amount"].as<double>();
        out_img = noise::add_sap_noise(img, amount);

        cv::imwrite(img_path+img_name+"_sap."+img_ext, out_img);
    }

    // TODO
    if (vm.count("poisson"))
    {
        std::cout << "Poisson specified" << endl;
    }

    // TODO
    if (vm.count("speckle"))
    {
        std::cout << "Poisson specified" << endl;
    }

    // TODO
    if (vm.count("uniform"))
    {
        std::cout << "Poisson specified" << endl;
    }

    // TODO
    if (vm.count("periodic"))
    {
        std::cout << "Poisson specified" << endl;
    }

    cv::imshow("Window", out_img);
    int key = cv::waitKey(0);

    return  0;

}
