#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>

struct Point {
    double x, y;
};
std::istream& operator>>(std::istream& is, Point& point) {
    return is >> point.x >> point.y;
}
// Funkcija za racunanje udaljenosti tocke od ishodista.
double distanceFromOrigin(const Point& p) {
    return std::sqrt(p.x * p.x + p.y * p.y);
}

void processPoints(const std::string& filePath, double circleRadius) {
    std::ifstream inputFile(filePath);
    std::vector<Point> points{
        std::istream_iterator<Point>(inputFile),
        std::istream_iterator<Point>()
    };

    std::sort(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return distanceFromOrigin(a) < distanceFromOrigin(b);
        });

    size_t pointsInsideCircle = std::count_if(points.begin(), points.end(),
        [circleRadius](const Point& p) {
            return distanceFromOrigin(p) < circleRadius;
        });

    double targetDistance = 1.0;
    std::replace_if(points.begin(), points.end(),
        [targetDistance](const Point& p) {
            return std::abs(distanceFromOrigin(p) - targetDistance) < 1e-6;
        },
        Point{ points[0] });

    std::reverse(points.begin(), points.end());

    // Output points to std::cout
    for (const Point& p : points) {
        std::cout << p.x << " " << p.y << "\n";
    }
}



void processWords(const std::string& filePath, const std::string& targetWord, const std::string& substringToRemove) {
    // 1. Napuni vektor stringova rijecima iz datoteke koristeci istream iterator.
    std::ifstream inputFile(filePath);
    std::vector<std::string> words{
        std::istream_iterator<std::string>(inputFile),
        std::istream_iterator<std::string>()
    };

    // 2. Nadi sva pojavljivanja odredene rijeci i njihovu poziciju u vektoru koristeci find.
    std::vector<size_t> positions;
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i] == targetWord) {
            positions.push_back(i);
        }
    }

    // 3. Izbaci sve stringove koji sadrze odredeni podstring koristeci remove_if i erase.
    words.erase(std::remove_if(words.begin(), words.end(),
        [substringToRemove](const std::string& str) {
            return str.find(substringToRemove) != std::string::npos;
        }),
        words.end());

    // 4. Koristeci transform, promijeni sva slova u stringovima u velika slova.
    std::for_each(words.begin(), words.end(),
        [](std::string& str) {
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        });

    // 5. Ispisi stringove iz vektora koristeci copy.
    std::ostream_iterator<std::string> outputIterator(std::cout, "\n");
    std::copy(words.begin(), words.end(), outputIterator);

    std::cout << "Pozicije: " << std::endl;
    for (size_t i : positions) {
        std::cout << " " << i;
    }
}

int main() {
    processWords("words.txt", "Vita", "Liber");
    processPoints("points.txt", 8.0);
    return 0;
}
