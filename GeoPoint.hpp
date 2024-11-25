#ifndef GEOPOINT_HPP
#define GEOPOINT_HPP

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class GeoPoint {
private:
    double latitude;  // Широта в градусах
    double longitude; // Долгота в градусах

    static constexpr double DEG_TO_RAD = M_PI / 180.0; // Конвертация градусов в радианы

public:
    // Конструкторы
    GeoPoint(double latitude, double longitude);

    // Методы доступа
    double getLatitude() const;
    double getLongitude() const;

    // Определение полушарий
    std::string getLatitudeHemisphere() const;
    std::string getLongitudeHemisphere() const;

    // Вычисление расстояния (ортодромия)
    double calculateDistance(const GeoPoint& other) const;

    // Смещение времени относительно Гринвича
    int getTimeOffset() const;

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const GeoPoint& point);
};

#endif // GEOPOINT_HPP