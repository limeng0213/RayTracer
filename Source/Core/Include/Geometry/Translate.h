#pragma once

#include "GeometryBase.h"

class Translate : public GeometryBase
{
public:
    Translate(std::shared_ptr<GeometryBase> pObject, XYZ offset)
        : m_pObject(pObject), m_offset(std::move(offset))
    {
    }

    virtual std::optional<HitRecord> hit(const Ray& ray, double minT, double maxT) const override;
    virtual UV uv(const XYZ& point) const override;
    virtual std::optional<AABB> boundingBox(double t0, double t1) const override;

private:
    XYZ m_offset;
    std::shared_ptr<GeometryBase> m_pObject;
};