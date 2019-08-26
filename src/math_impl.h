#pragma once

#include "../math.h"

#pragma warning(push, 0)
#include <opencv2/core/types.hpp>
#pragma warning(pop)

namespace opencv_wrapper
{
	class Contour::ContourImpl
	{
	public:
		void SetPoints(std::vector<cv::Point> points)
		{
			_points = std::move(points);
		}
		const std::vector<cv::Point>& GetPoints() const
		{
			return _points;
		}
	private:
		std::vector<cv::Point> _points;
	};

	class Point::PointImpl : public cv::Point
	{
	public:
		using cv::Point::Point;
	};

	class Rect::RectImpl : public cv::Rect
	{
	public:
		RectImpl()
			: cv::Rect()
		{
		}
		explicit RectImpl(const cv::Rect& rect)
			: cv::Rect(rect)
		{
		}
	};

	class Scalar::ScalarImpl : public cv::Scalar
	{
	public:
		using cv::Scalar::Scalar;
	};

	class Size::SizeImpl : public cv::Size
	{
	public:
		using cv::Size::Size;
	};
}