#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <set>
#include <dirent.h>
#include <glob.h>

#include <cstring>

std::chrono::time_point<std::chrono::high_resolution_clock> START;
std::string BASE_NAME = "jimmy-humunukuapua";
std::string TERMINATION = ".txt";
std::ofstream dat("a.dat");

void cleanup() {
    system(("rm -f *" + TERMINATION).c_str());
}

void createFiles(int n) {
    for (int i = 0; i < n ; ++i) {
        std::stringstream name_stream;
        name_stream << std::right << std::setfill('0') << std::setw(20) << i;
        std::ofstream(BASE_NAME + name_stream.str() + TERMINATION);
    }
}

void start() {
   START = std::chrono::high_resolution_clock::now();
}

void end() {
   auto end = std::chrono::high_resolution_clock::now();
   auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - START)
                   .count();
   std::cout << diff << " ms" << std::endl;
   dat << diff << " ";
}

std::string glob() {
    glob_t globbuf;
    std::string glob_pattern(BASE_NAME+ "*" + TERMINATION);
    glob(glob_pattern.c_str(), 0, NULL, &globbuf);
    std::string result;
    if (globbuf.gl_pathc > 0) {
        result = globbuf.gl_pathv[globbuf.gl_pathc - 1];
    }
    globfree(&globbuf);
    return result;
}

std::string readdir() {
    DIR* dir = opendir(".");
    if (!dir) {
        return "";
    }

    // Set of sorted files by name.
    std::set<std::string> files;

    // Add only files of interest that could be used to append logging data.
    for (struct dirent* dent = readdir(dir); dent; dent = readdir(dir)) {
        std::string name(dent->d_name);
        // Skip current and parent directory
        if (name == "." || name == "..") {
            continue;
        }

        // Skip non .txt files
        if (name.size() < 4 || name.size() < BASE_NAME.size() || name.substr(name.size() - 4) != ".txt") {
            continue;
        }

        std::string file = name.substr(0, name.size() - 4);

        // Skip files that are not beginning with base name.
        if (file.substr(0, BASE_NAME.size()) != BASE_NAME) {
            continue;
        }

        files.insert(file + TERMINATION);
    }

    closedir(dir);

    if (files.size() == 0) {
        return "";
    }

    return *files.rbegin();
}

int main() {
    std::string result;

    for (int i = 1; i < (1 << 16); i <<= 1) {
        createFiles(i);
        dat << i << " ";

        std::cout << "=== glob ===" << std::endl;
        start();
        result = glob();
        end();
        std::cout << "Files: " << i << std::endl;
        std::cout << "Result: " << result << std::endl;

        std::cout << "=== readdir ===" << std::endl;
        start();
        result = readdir();
        end();
        std::cout << "Files: " << i << std::endl;
        std::cout << "Result: " << result << std::endl;

        std::cout << std::endl;
        dat << std::endl;
    }
    cleanup();
    dat.close();

    return 0;
}
