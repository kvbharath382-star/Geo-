#include <iostream>
#include <cmath>
using namespace std;

// Haversine Formula function (distance in km)
double getDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Earth radius (km)
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat/2) * sin(dLat/2) +
               cos(lat1) * cos(lat2) *
               sin(dLon/2) * sin(dLon/2);

    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

int main() {
    // Fixed office/school location
    double officeLat = 12.9716;
    double officeLon = 77.5946;

    // Example student location
    double userLat, userLon;
    cout << "Enter your latitude: ";
    cin >> userLat;
    cout << "Enter your longitude: ";
    cin >> userLon;

    // Allowed radius (in km)
    double allowedRadius = 0.2;

    double distance = getDistance(userLat, userLon, officeLat, officeLon);

    if (distance <= allowedRadius) {
        cout << "? Attendance Marked!" << endl;
    } else {
        cout << "? You are not at the location!" << endl;
    }

    return 0;
}
