#pragma once
#include "Eigen/Dense"

float Random() {
    return ((double)rand()) / RAND_MAX;
}

Eigen::Vector3f RandomInUnitDisk() {
    Eigen::Vector3f p;
    do {
        p = 2.0f * Eigen::Vector3f(((double)rand()) / RAND_MAX, ((double)rand()) / RAND_MAX, 0) - Eigen::Vector3f(1, 1, 0);
    } while (p.dot(p) >= 1.0);
    return p;
}

float Schlick(float cosine, float ref_idx) {
    float r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

bool Refract(const Eigen::Vector3f& v, const Eigen::Vector3f& n, float ni_over_nt, Eigen::Vector3f& refracted) {
    Eigen::Vector3f uv = v.normalized();
    float dt = uv.dot(n);
    float discriminant = 1.0f - ni_over_nt * ni_over_nt * (1 - dt * dt);
    if (discriminant > 0) {
        refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
        return true;
    }
    else
        return false;
}

Eigen::Vector3f Reflect(const Eigen::Vector3f& v, const Eigen::Vector3f& n) {
    return v - 2 * v.dot(n) * n;
}

Eigen::Vector3f RandomInUnitSphere() {
    Eigen::Vector3f p;
    do {
        p = 2.0f * Eigen::Vector3f(((double)rand()) / RAND_MAX, ((double)rand()) / RAND_MAX, ((double)rand()) / RAND_MAX) - Eigen::Vector3f(1, 1, 1);
    } while (p.squaredNorm() >= 1.0);
    return p;
}