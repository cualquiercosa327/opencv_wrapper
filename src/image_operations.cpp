#include "../image_operations.h"

#include "mat_impl.h"
#include "math_impl.h"

#pragma warning(push, 0)
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#pragma warning(pop)

namespace opencv_wrapper
{
	Mat imread(const char* filename, int flags)
	{
		Mat result;
		*result.get() = Mat::MatImpl(cv::imread(cv::String{ filename }, flags));
		return result;
	}

	bool imwrite(const char* filename, const Mat& img,
		const std::vector<int>& params)
	{
		return cv::imwrite(cv::String{ filename }, *img.get(), params);
	}

	void resize(const Mat& src, Mat& dst, const Size& dsize, double fx, double fy, int interpolation)
	{
		cv::resize(*src.get(), *dst.get(), *dsize.get(), fx, fy, interpolation);
	}

	Rect boundingRect(const Mat& mat)
	{
		Rect result;
		*result.get() = Rect::RectImpl(cv::boundingRect(*mat.get()));
		return result;
	}

	void inRange(const Mat& src, const Scalar& lowerb,
		const Scalar& upperb, Mat& dst)
	{
		cv::inRange(*src.get(), *lowerb.get(), *upperb.get(), *dst.get());
	}

	void cvtColor(const Mat& src, Mat& dst, int code, int dstCn)
	{
		cv::cvtColor(*src.get(), *dst.get(), code, dstCn);
	}

	void findContours(const Mat& image, Contour*& contours, std::size_t& total_contours)
	{
		std::vector<std::vector<cv::Point>> cv_contours;
		std::vector<cv::Vec4i> hierarchy;
		cv::findContours(*image.get(), cv_contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE,
			cv::Point(0, 0));

		total_contours = cv_contours.size();
		contours = new Contour[cv_contours.size()];

		for (std::size_t i = 0; i < cv_contours.size(); i++)
		{
			contours[i].get()->SetPoints(cv_contours[i]);
		}
	}

	void destroyFoundContours(Contour*& contours)
	{
		delete[] contours;
	}

	void copyMakeBorder(const Mat& src, Mat& dst,
		int top, int bottom, int left, int right,
		int borderType, const Scalar& value)
	{
		cv::copyMakeBorder(*src.get(), *dst.get(), top, bottom, left, right, borderType, *value.get());
	}
}
