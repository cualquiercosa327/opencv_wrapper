#include "../math.h"

#include "math_impl.h"

namespace opencv_wrapper
{
	Contour::Contour()
		: _impl(std::make_unique<Contour::ContourImpl>())
	{
	}

	Contour::~Contour() = default;

	Contour::ContourImpl* Contour::get() const
	{
		return _impl.get();
	}

	Point::Point()
		: _impl(std::make_unique<Point::PointImpl>())
	{
	}

	Point::Point(const Point& p)
	{
		if (!_impl)
		{
			_impl = std::make_unique<Point::PointImpl>();
		}
		*_impl.get() = *p.get();
	}

	Point::~Point() = default;

	Point::PointImpl* Point::get() const
	{
		return _impl.get();
	}

	Rect::Rect()
		: _impl(std::make_unique<Rect::RectImpl>())
	{
	}

	Rect::Rect(const Rect& rect)
	{
		if (!_impl)
		{
			_impl = std::make_unique<Rect::RectImpl>();
		}
		*_impl.get() = *rect.get();
	}

	Rect::~Rect() = default;

	Rect::RectImpl* Rect::get() const
	{
		return _impl.get();
	}

	Size Rect::size() const
	{
		const auto size = _impl->size();
		return Size{ size.width, size.height };
	}

	int Rect::width() const
	{
		return _impl->width;
	}

	int Rect::height() const
	{
		return _impl->height;
	}

	Scalar::Scalar()
		: _impl(std::make_unique<Scalar::ScalarImpl>())
	{
	}

	Scalar::Scalar(double v1, double v2, double v3, double v4)
		: _impl(std::make_unique<Scalar::ScalarImpl>(v1, v2, v3, v4))
	{
	}

	Scalar::~Scalar() = default;

	Scalar::ScalarImpl* Scalar::get() const
	{
		return _impl.get();
	}

	Size::Size()
		: _impl(std::make_unique<Size::SizeImpl>())
	{
	}

	Size::Size(int w, int h)
		: _impl(std::make_unique<Size::SizeImpl>(w, h))
	{
	}

	Size::~Size() = default;

	Size::SizeImpl* Size::get() const
	{
		return _impl.get();
	}

	int Size::width() const
	{
		return _impl->width;
	}

	int Size::height() const
	{
		return _impl->height;
	}
}