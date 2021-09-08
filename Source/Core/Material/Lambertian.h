#pragma once

#include "Material.h"
#include "SolidColor.h"

class Lambertian : public Material
{
public:
    Lambertian() = delete;
    Lambertian(Color albedo) : m_pAlbedo(std::make_shared<SolidColor>(std::move(albedo))) {}
	Lambertian(std::shared_ptr<Texture> pTexture) : m_pAlbedo(pTexture) {}
    virtual ~Lambertian() = default;

    Lambertian(const Lambertian&) = delete;
    Lambertian(Lambertian&&) = delete;
    Lambertian& operator=(const Lambertian&) = delete;
    Lambertian& operator=(Lambertian&&) = delete;
	
    virtual bool scatter(const Ray& ray, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const override;

private:
    std::shared_ptr<Texture> m_pAlbedo;
};