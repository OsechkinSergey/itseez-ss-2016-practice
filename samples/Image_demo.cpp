#include <iostream>
#include <string>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

#include "image_processing.hpp"

using namespace std;
using namespace cv;

const char* kAbout = "Application for practice #1.";

const char* kOptions =
    "{ @image         |        | image to process         }"
    "{ t              |  128   | threshold                }"
    "{ h ? help usage |        | print help message       }";

int main(int argc, const char** argv) {
  // Parse command line arguments.
  CommandLineParser parser(argc, argv, kOptions);
  parser.about(kAbout);

  // If help option is given, print help message and exit.
  if (parser.has("help")) {
    parser.printMessage();
    return 0;
  }

  // Read image.
  Mat src = imread(parser.get<string>(0));
  if (src.empty()) {
    cout << "Failed to open image file '" + parser.get<string>(0) + "'."
         << endl;
    return 0;
  }

  // Show source image.
  const string kSrcWindowName = "Source image";
  const int kWaitKeyDelay = 1;
  namedWindow(kSrcWindowName, WINDOW_NORMAL);
  resizeWindow(kSrcWindowName, 640, 480);
  imshow(kSrcWindowName, src);
  waitKey(kWaitKeyDelay);

  Rect rec(50,50,200,200);
  int size = 3;

  // CvtColor data.
  ImageProcessorImpl processor;
    processor.Filter(src, rec,size);


  // Show destination image.
  const string kDstWindowName = "Destination image";
  namedWindow(kDstWindowName, WINDOW_NORMAL);
  resizeWindow(kDstWindowName, 640, 480);
  imshow(kDstWindowName, processor.Filter(src, rec,size));
  waitKey();

  return 0;
}