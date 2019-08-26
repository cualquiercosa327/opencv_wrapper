#include "../mat.h"

#include "mat_impl.h"

namespace opencv_wrapper
{
	Mat::Mat()
		: _impl(std::make_unique<Mat::MatImpl>())
	{
	}

	Mat::Mat(const Contour& contour)
		: _impl(std::make_unique<Mat::MatImpl>(contour.get()->GetPoints()))
	{
	}

	Mat::Mat(const Mat& mat)
	{
		if (!_impl)
		{
			_impl = std::make_unique<Mat::MatImpl>();
		}
		*_impl.get() = *mat.get();
	}

	Mat::~Mat() = default;

	Mat::MatImpl* Mat::get() const
	{
		return _impl.get();
	}

	void Mat::copyTo(const Mat& mat) const
	{
		_impl->copyTo(*mat.get());
	}

	Mat Mat::operator()(const Rect& roi) const
	{
		Mat mat;
		*mat.get() = Mat::MatImpl((*_impl)(*roi.get()));
		return mat;
	}

	int Mat::rows() const
	{
		return _impl->rows;
	}

	int Mat::cols() const
	{
		return _impl->cols;
	}
}