#include <iostream>
#include <cmath>

template<typename T>
class point {
private:
    T x;
    T y;

public:
    point(T x_val, T y_val) : x(x_val), y(y_val) {}

    friend std::ostream& operator<<(std::ostream& os, const point<T>& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }

    friend double operator-(const point<T>& p1, const point<T>& p2) {
        T dx = p1.x - p2.x;
        T dy = p1.y - p2.y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main() {
    point<int> p1(2, 3), p2(3, 4);
    std::cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << std::endl;

    return 0;
}
