#pragma once

#include "GeometryBase.h"

class Sphere : public GeometryBase
{
public:
    Sphere() = delete;
    Sphere(XYZ center, double radius);
    virtual ~Sphere() = default;

    Sphere(const Sphere& rhs) { m_center = rhs.center(); m_radius = rhs.radius(); }
    Sphere(Sphere&& rhs) = default;
    Sphere& operator=(const Sphere&) = default;
    Sphere& operator=(Sphere&&) = default;

    XYZ center(double curTime = 0.0) const;
    double radius() const { return m_radius; }

    virtual std::optional<HitRecord> hit(const Ray& ray, double minT = -10000000.0, double maxT = +10000000.0) const override;
    virtual UV uv(const XYZ& point) const override;

private:
    XYZ                         m_center;
    double                      m_radius;
};