#include "detection.hpp"

#include <iostream>

using std::string;
using std::shared_ptr;
using namespace cv;

shared_ptr<Detector> Detector::CreateDetector(const string& name) {
  std::cerr << "Failed to create detector with name '" << name << "'"
            << std::endl;
  return nullptr;
}

bool CascadeDetector::Init(const std::string & model_file_path)
{
	bool Init;
	CascadeClassifier::load(model_file_path);
	return false;
}
