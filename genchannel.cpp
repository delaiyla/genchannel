#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

std::string generateRandomPassword() {
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, alphabet.size() - 1);

    int length = dis(gen) + 8; // длина строки от 8 до 12 символов
    std::string password;
    for (int i = 0; i < length; i++) {
        password += alphabet[dis(gen)];
    }

    return password;
}

bool fileExists(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

std::vector<std::string> readLinesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

void writeLinesToFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    for (const std::string& line : lines) {
        file << line << std::endl;
    }
}

int main() {
    std::vector<std::string> loginLines = readLinesFromFile("videostreams.txt");
    std::vector<std::string> passwdLines;

    if (fileExists("videostreams_channels.txt")) {
        passwdLines = readLinesFromFile("videostreams_channels.txt");
    }

    if (loginLines.size() > passwdLines.size()) {
        int missingLines = loginLines.size() - passwdLines.size();
        for (int i = 0; i < missingLines; i++) {
            std::string password = generateRandomPassword();
            passwdLines.push_back(password);
        }
    } else {
        passwdLines.resize(loginLines.size());
    }

    writeLinesToFile("videostreams_channels.txt", passwdLines);

    return 0;
}
