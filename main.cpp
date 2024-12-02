#include "GeoPoint.hpp"
#include <iostream>

int main() {
    try {
        GeoPoint point1(55.7558, 37.6173); // Москва
        GeoPoint point2(59.94, 30.32); // Питер

        std::cout << point1 << "\n";
        std::cout << "Latitude Hemisphere: " << point1.getLatitudeHemisphere() << "\n";
        std::cout << "Longitude Hemisphere: " << point1.getLongitudeHemisphere() << "\n";

        std::cout << "\n" << point2 << "\n";
        std::cout << "Latitude Hemisphere: " << point2.getLatitudeHemisphere() << "\n";
        std::cout << "Longitude Hemisphere: " << point2.getLongitudeHemisphere() << "\n";

        double distance = point1.calculateDistance(point2);
        std::cout << "\nDistance between Moscow and St.Petersburg: " << distance << " km\n";

        std::cout << "Time offset for Moscow: " << point1.getTimeOffset() << " minutes\n";
        std::cout << "Time offset for St.Petersburg: " << point2.getTimeOffset() << " minutes\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}