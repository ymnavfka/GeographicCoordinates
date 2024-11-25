#include "GeoPoint.hpp"
#include <stdexcept>

// Конструктор с проверкой на корректность
GeoPoint::GeoPoint(double latitude, double longitude)
    : latitude(latitude), longitude(longitude) {
    if (latitude < -90.0 || latitude > 90.0) {
        throw std::invalid_argument("Latitude must be between -90 and 90 degrees.");
    }
    if (longitude < -180.0 || longitude > 180.0) {
        throw std::invalid_argument("Longitude must be between -180 and 180 degrees.");
    }
}

// Методы доступа
double GeoPoint::getLatitude() const {
    return latitude;
}

double GeoPoint::getLongitude() const {
    return longitude;
}

// Определение полушарий
std::string GeoPoint::getLatitudeHemisphere() const {
    return latitude >= 0 ? "Northern Hemisphere" : "Southern Hemisphere";
}

std::string GeoPoint::getLongitudeHemisphere() const {
    return longitude >= 0 ? "Eastern Hemisphere" : "Western Hemisphere";
}

// Вычисление расстояния (ортодромия)
double GeoPoint::calculateDistance(const GeoPoint& other) const {
    double lat1Rad = latitude * DEG_TO_RAD;
    double lon1Rad = longitude * DEG_TO_RAD;
    double lat2Rad = other.latitude * DEG_TO_RAD;
    double lon2Rad = other.longitude * DEG_TO_RAD;

    double deltaLon = lon2Rad - lon1Rad;

    double centralAngle = std::acos(
        std::sin(lat1Rad) * std::sin(lat2Rad) +
        std::cos(lat1Rad) * std::cos(lat2Rad) * std::cos(deltaLon)
    );

    constexpr double EARTH_RADIUS = 6371.0; // Радиус Земли в км
    return EARTH_RADIUS * centralAngle;
}

// Смещение времени относительно Гринвича
int GeoPoint::getTimeOffset() const {
    return static_cast<int>(longitude * 4); // 1 градус = 4 минуты
}

// Перегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const GeoPoint& point) {
    os << "GeoPoint(Latitude: " << point.latitude
       << ", Longitude: " << point.longitude << ")";
    return os;
}
