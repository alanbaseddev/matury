#include <iostream>
#include <fstream>
#include <vector>

struct Punkt {
    int x;
    int y;
};

int main() {
    std::ifstream infile("dron.txt");
    std::vector<Punkt> trasa;
    int x, y;
    int aktualny_x = 0;
    int aktualny_y = 0;
    while (infile >> x >> y) {
        aktualny_x += x;
        aktualny_y += y;
        trasa.push_back({aktualny_x, aktualny_y});
    }
    int licznik_kwadratu = 0;
    for (const auto& p : trasa) {
        if (p.x > 0 && p.x < 5000 && p.y > 0 && p.y < 5000) {
            licznik_kwadratu++;
        }
    }
    std::cout << "a: " << licznik_kwadratu << std::endl;
    // czesc b
    std::cout << "b: " << std::endl;
    int n = trasa.size();
    bool znaleziono = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                Punkt p1 = trasa[i];
                Punkt p2 = trasa[j];
                Punkt p3 = trasa[k];
                if (2 * p1.x == p2.x + p3.x && 2 * p1.y == p2.y + p3.y) {
                    std::cout << "(" << p1.x << ", " << p1.y << ")" << std::endl;
                    std::cout << "(" << p2.x << ", " << p2.y << ")" << std::endl;
                    std::cout << "(" << p3.x << ", " << p3.y << ")" << std::endl;
                    znaleziono = true;
                }
                else if (2 * p2.x == p1.x + p3.x && 2 * p2.y == p1.y + p3.y) {
                    std::cout << "(" << p2.x << ", " << p2.y << ")" << std::endl;
                    std::cout << "(" << p1.x << ", " << p1.y << ")" << std::endl;
                    std::cout << "(" << p3.x << ", " << p3.y << ")" << std::endl;
                    znaleziono = true;
                }
                else if (2 * p3.x == p1.x + p2.x && 2 * p3.y == p1.y + p2.y) {
                    std::cout << "(" << p3.x << ", " << p3.y << ")" << std::endl;
                    std::cout << "(" << p1.x << ", " << p1.y << ")" << std::endl;
                    std::cout << "(" << p2.x << ", " << p2.y << ")" << std::endl;
                    znaleziono = true;
                }
                if (znaleziono) break;
            }
            if (znaleziono) break;
        }
        if (znaleziono) break;
    }

    return 0;
}