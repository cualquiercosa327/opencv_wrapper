#pragma once

#include "exports.h"

#include <memory>

namespace opencv_wrapper
{
	// While opencv doesn't have a concept of an
	// actual "contour" this wraps up the returns
	// of findContours into a convienant structure
	class Contour
	{
	public:
		EXPORTS Contour();
		EXPORTS ~Contour();
		class ContourImpl;
		EXPORTS ContourImpl* get() const;
	private:
		std::unique_ptr<ContourImpl> _impl;
	};

	class Point
	{
	public:
		EXPORTS Point();
		EXPORTS ~Point();
		EXPORTS Point(const Point& p);
		class PointImpl;
		EXPORTS PointImpl* get() const;
	private:
		std::unique_ptr<PointImpl> _impl;
	};

	class Size;

	class Rect
	{
	public:
		EXPORTS Rect();
		EXPORTS ~Rect();
		EXPORTS Rect(const Rect& rect);
		class RectImpl;
		EXPORTS RectImpl* get() const;

		EXPORTS Size size() const;
		EXPORTS int width() const;
		EXPORTS int height() const;
	private:
		std::unique_ptr<RectImpl> _impl;
	};

	class Scalar
	{
	public:
		EXPORTS Scalar();
		EXPORTS explicit Scalar(double v1, double v2, double v3=0, double v4=0);
		EXPORTS ~Scalar();
		class ScalarImpl;
		EXPORTS ScalarImpl* get() const;
	private:
		std::unique_ptr<ScalarImpl> _impl;
	};

	class Size
	{
	public:
		EXPORTS Size();
		EXPORTS explicit Size(int w, int h);
		EXPORTS ~Size();
		class SizeImpl;
		EXPORTS SizeImpl* get() const;

		EXPORTS int width() const;
		EXPORTS int height() const;
	private:
		std::unique_ptr<SizeImpl> _impl;
	};
}