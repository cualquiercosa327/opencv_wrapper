#pragma once

#include "exports.h"
#include "math.h"

#include <memory>
#include <vector>

namespace opencv_wrapper
{
	class Mat
	{
	public:
		EXPORTS Mat();
		EXPORTS explicit Mat(const Contour& contour);
		EXPORTS Mat(const Mat& mat);
		EXPORTS ~Mat();
		class MatImpl;
		EXPORTS MatImpl* get() const;
		EXPORTS void copyTo(const Mat& mat) const;
		EXPORTS Mat operator()(const Rect& roi) const;

		EXPORTS int rows() const;
		EXPORTS int cols() const;
	private:
		std::unique_ptr<MatImpl> _impl;
	};
}