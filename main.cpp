// Usage : AddSomeNoise [PATH] [NOISE-TYPE] [OPT-PARAM]
// Example : AddSomeNoise /path/to/image --gaussian --stddev 0.5
// Example : AddSomeNoise /path/to/image --periodic --vstr 0.5 --hstr 0.5
// For more option use AddSomeNoise --help
// Default Windows compatible
// To make the program linux compatible please change path delimiter.

#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

#include "noise.h"

using namespace std;
namespace po = boost::program_options;

int main(int argc, const char *argv[]) {

    po::options_description description("Add Some Noise Program Usage:");

    // Program args
    description.add_options()
            ("help", "Display this help message")
            ("path", po::value<string>(), "Input image file path")
            ("gaussian", "Add gaussian noise to image")
            ("sap", "Add salt & pepper noise to image")
            ("poisson", "Add poisson noise to image")
            ("speckle", "Add speckle noise to image")
            ("uniform", "Add speckle noise to image")
            ("periodic", "Add periodic noise to image")
            ("stddev", po::value<double>()->default_value(0.1), "Gaussian standard deviation, default is 0.1 [0, 1]")
            ("amount", po::value<double>()->default_value(0.05), "Amount of salt & pepper, default is 0.05 [0, 1]")
            ("mean", po::value<double>()->default_value(0.1), "Mean of poisson, default is 0.1 [0, 1]")
            ("vstr", po::value<double>()->default_value(0.1), "Vertical strength of periodic noise, default is 0.1 [0, 1]")
            ("hstr", po::value<double>()->default_value(0.1), "Horizontal strength of periodic noise, default is 0.1 [0, 1]");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(description).run(), vm);
    po::notify(vm);

    cv::Mat img;
    cv::Mat out_img;
    cv::Mat norm_img;

    string img_path;
    string img_ext;
    string img_name;
    string type;

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

        cv::imwrite(img_path+img_name+"_gauss."+img_ext, out_img);
        type = "_gauss";
    }

    if (vm.count("sap"))
    {
        double amount = vm["amount"].as<double>();
        out_img = noise::add_sap_noise(img, amount);

        cv::imwrite(img_path+img_name+"_sap."+img_ext, out_img);
        type = "_sap";
    }


    if (vm.count("poisson"))
    {
        double mean = vm["mean"].as<double>();
        out_img = noise::add_poisson_noise(img, mean);

        cv::imwrite(img_path+img_name+"_poisson."+img_ext, out_img);
        type = "_poisson";
    }


    if (vm.count("speckle"))
    {
        out_img = noise::add_speckle_noise(img);

        cv::imwrite(img_path+img_name+"_speckle."+img_ext, out_img);
        type = "_speckle";
    }


    if (vm.count("uniform"))
    {
        out_img = noise::add_uniform_noise(img);

        cv::imwrite(img_path+img_name+"_uni."+img_ext, out_img);
        type = "_uni";
    }


    if (vm.count("periodic"))
    {
        double vstr = vm["vstr"].as<double>();
        double hstr = vm["hstr"].as<double>();
        out_img = noise::add_periodic_noise(img, vstr, hstr);

        cv::imwrite(img_path+img_name+"_peri."+img_ext, out_img);
        type = "_peri";
    }

    cout << "Image " << img_name  << type << "." << img_ext << " saved to location " << img_path << endl;

    return  0;
}
