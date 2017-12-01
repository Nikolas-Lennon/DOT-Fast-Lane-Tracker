// shapes.h
#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <string>
#include <cmath>

class Shape
{

public:
  Shape();
  virtual ~Shape();
  Shape(float x, float y, float z, bool verbose = false);
  
  virtual const char* Name() const;
  virtual float Volume() const;
  virtual float Area() const;

protected:
  float x_, y_, z_;
  bool verbose_;

private:
  Shape(const Shape& s);
  Shape& operator= (const Shape s);
};

class Rectangle : public Shape
{
public:
  Rectangle(); //default constructor
  Rectangle(float, float, bool verbose = false);
  virtual ~Rectangle();

  float Area() const;
  const char* Name() const;

private:

  Rectangle& operator= (const Rectangle r);
  Rectangle(const Rectangle& r);
  float width_, length_, height_;
  bool verbose_;
};

class Cylinder : public Shape
{
public:
  Cylinder();
  virtual ~Cylinder();
  Cylinder(float, float, bool verbose = false);

  float Area() const;
  float Volume() const;
  const char* Name() const;

private:
  Cylinder& operator = (const Cylinder c);
  Cylinder(const Cylinder& c);
  float radius_;
  float height_;
  bool verbose_;

};

class Box : public Shape
{

public:
  Box();
  Box(float, float, float, bool verbose = false);
  virtual ~Box();
  float Area() const;
  float Volume() const;
  const char* Name() const;

private:
  Box& operator = (const Box b);
  Box(const Box& b);
  float length_;
  float width_;
  float height_;
  bool verbose_;
};

#endif
