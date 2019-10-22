#include <celero/Celero.h>

#include <iostream>

#include <random>

#ifndef WIN32
#include <cmath>
#include <cstdlib>
#endif

CELERO_MAIN

std::random_device RandomDevice;
std::uniform_int_distribution<int> UniformDistribution(-100000, 100000);

struct Point
{
    int x, y;
};

struct AABB
{
    Point min, max;

    AABB(int x1, int y1, int x2, int y2)
        : min {x1 < x2 ? x1 : x2, y1 < y2 ? y1 : y2}, max {x1 > x2 ? x1 : x2, y1 > y2 ? y1 : y2}
    {
    }

    bool isInside(Point p) const
    {
        return min.x <= p.x && min.y <= p.y && p.x <= max.x && p.y <= max.y;
    }
};

struct CollisionFixture : public celero::TestFixture
{
    int len;
    std::vector<AABB> boxes;

    virtual std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
    {
        return std::vector<celero::TestFixture::ExperimentValue> {
            8, 1 << 9, 1 << 10, 1 << 11, 32, 1 << 8, 1 << 12, 1 << 13, 1 << 14, 1 << 15};
    }

    virtual void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
    {
        len = int(experimentValue.Value);
        boxes.clear();
        boxes.reserve(len);
        for (int i = 0; i < len; ++i)
        {
            int a = UniformDistribution(RandomDevice), b = UniformDistribution(RandomDevice),
                c = UniformDistribution(RandomDevice), d = UniformDistribution(RandomDevice);

            boxes.emplace_back(a, b, c, d);
        }
    }
};

struct SortedCollisionFixture : public CollisionFixture
{
    virtual void setUp(const celero::TestFixture::ExperimentValue& experimentValue) override
    {
        CollisionFixture::setUp(experimentValue);
        std::sort(boxes.begin(), boxes.end(), [](AABB const& a, AABB const& b) {
            return a.min.x < b.min.x || (a.min.x == b.min.x && a.min.y < b.min.y);
        });
    }
};

int count_collisions(const std::vector<AABB>& boxes, Point p)
{
    return std::count_if(boxes.begin(), boxes.end(), [=](AABB const& a) { return a.isInside(p); });
}

BASELINE_F(Boxes, Unordered, CollisionFixture, 200, 1024)
{
    Point p;
    p.x = UniformDistribution(RandomDevice);
    p.y = UniformDistribution(RandomDevice);
    const int count = count_collisions(boxes, p);
    celero::DoNotOptimizeAway(count);
}

BENCHMARK_F(Boxes, Ordered, SortedCollisionFixture, 200, 1024)
{
    Point p;
    p.x = UniformDistribution(RandomDevice);
    p.y = UniformDistribution(RandomDevice);
    const int count = count_collisions(boxes, p);
    celero::DoNotOptimizeAway(count);
}
