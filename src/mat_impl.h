#pragma once

#include "../mat.h"
#include "../math.h"

#include "math_impl.h"

#pragma warning(push, 0)
#include <opencv2/core/mat.hpp>
#pragma warning(pop)

namespace opencv_wrapper
{
	class Mat::MatImpl : public cv::Mat
	{
	public:
		MatImpl()
			: cv::Mat()
		{
		}

		MatImpl(const cv::Mat& mat)
			: cv::Mat(mat)
		{
		}

		explicit MatImpl(const std::vector<cv::Point>& points, bool copy = false)
			: cv::Mat(points, copy)
		{
		}
	};
}