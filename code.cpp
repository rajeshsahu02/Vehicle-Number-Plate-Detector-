#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Images //////////////////////


void main() {

	VideoCapture cap(1);
	Mat img;

	CascadeClassifier plateCascade;
	plateCascade.load("Resources / plate_number.xml");

	if (plateCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> plates;
	while (true) {

		cap.read(img);
		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			Mat imgcrop = img(plates[i]);
			//imshow(to_string(i), imgcrop);
			imwrite("resources/plates/" + to_string(i) + ".png", imgcrop);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
		}

		imshow("image", img);
		waitKey(1);
	}
}
