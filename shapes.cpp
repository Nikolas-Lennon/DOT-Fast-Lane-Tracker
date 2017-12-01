//shapes.cpp
//Nikolas Lennon

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <shapes.h>

Shape::Shape() : x_(0), y_(0), z_(0), verbose_(0)
{
  if (verbose_)
    std::cout << "Shape(" << x_ << "," << y_ << "," << z_ << "," << verbose_ << ")" << std::endl;
}

Shape::~Shape()
{
  if (verbose_)
  std::cout << "~Shape()" << std::endl;
}

Shape::Shape(float x, float y, float z, bool verbose) : x_(x), y_(y), z_(z), verbose_(verbose)
{
  if (verbose_)
    std::cout << "Shape(" << x_ << "," << y_ << "," << z_ << "," << verbose_ << ")" << std::endl;
}

const char * Shape::Name() const
{
  return "generic";
}

float Shape::Volume() const
{
  return 0;
}

float Shape::Area() const
{
  return 0;
}

Rectangle::Rectangle() : Shape()
{
  // if (verbose_)
  //  std::cout << "Rectangle(" << width_ << "," << length_ << "," << verbose_ << ")" << std::endl;
}

Rectangle::Rectangle(float width, float length, bool verbose) : width_(width), length_(length), verbose_(verbose)
{
  if (verbose_)
    std::cout << "Shape(" << width_ << "," << length_ << "," << 0.00 << "," << verbose << ")" << std::endl;
  if (verbose_)
    std::cout << "Rectangle(" << width_ << "," << length_ << "," << verbose_ << ")" << std::endl;
}

Rectangle::~Rectangle()
{
  if (verbose_)
  std::cout << "~Rectangle()" << std::endl;
  if (verbose_)
  std::cout << "~Shape()" << std::endl;
}

float Rectangle::Area() const
{
  return width_ * length_;
}

const char * Rectangle::Name() const
{
  return "rectangle";
}

Cylinder::Cylinder() : radius_(0), height_(0), verbose_(0)
{
  //if (verbose_)
  //  std::cout << "Cylinder(" << radius_ << "," << height_ << "," << 0 << "," << verbose_ << ")" << std::endl;
}

Cylinder::~Cylinder()
{
  if (verbose_)
  std::cout << "~Cylinder()" << std::endl;
  if (verbose_)
  std::cout << "~Shape()" << std::endl;
}

Cylinder::Cylinder(float radius, float height, bool verbose) : radius_(radius), height_(height), verbose_(verbose)
{
  if (verbose_)
    std::cout << "Shape(" << radius_ << "," << 0.00 << "," << height_ << "," << verbose_ << ")" << std::endl;
  if (verbose_)
    std::cout << "Cylinder(" << radius_ << "," << height_ << "," << verbose_ << ")" << std::endl;
}

float Cylinder::Area() const
{
  return (2 * M_PI * radius_ * height_) + (2 * M_PI * radius_ * radius_);
}

float Cylinder::Volume() const
{
  return M_PI * radius_ * radius_ * height_;
}

const char * Cylinder::Name() const
{
  return "cylinder";
}

Box::Box() : length_(0), width_(0), verbose_(0)
{
  //  if(Shape::verbose_)
  // std::cout << "Box(" << length_ << "," << width_ << "," << height_ << "," << verbose_ << ")" << std::endl;
}

Box::Box(float width, float length, float height, bool verbose) : length_(length), width_(width), height_(height), verbose_(verbose)
{
  if (verbose_)
    std::cout << "Shape(" << width << "," << length << "," << height << "," << verbose << ")" << std::endl;
  if (verbose_)
   std::cout << "Box(" << width << "," << length << "," << height << "," << verbose << ")" << std::endl;
}

Box::~Box()
{
  if (verbose_)
  std::cout << "~Box()" << std::endl;
  if (verbose_)
  std::cout << "~Shape()" << std::endl;
}

float Box::Area() const
{
  return (2 * length_ * width_) + (2 * length_ * height_) + (2 * width_ * height_);
}

float Box::Volume() const 
{
  return length_ * width_ * height_;
}

const char * Box::Name() const
{
  return "box";
}
