#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::experimental::filesystem;
using Path = fs::path;

void printFileState(std::ifstream& file)
{
  std::cout << "good: " << file.good() // checks if no error has occurred i.e.I / O operations are available
    << " | "
    << "eof: " << file.eof() // checks if end - of - file has been reached
    << " | "
    << "fail: " << file.fail() // checks if an error has occurred
    << " | "
    << "bad: " << file.bad() // checks if a non - recoverable error has occurred
    << std::endl;
}

// C++17 在Windows和Ubuntu下测试循环次数不同，Error位赋值时机不同
void TestFileStreamStateFlags()
{
  const Path loggingRootPath = ".";
  std::ifstream file;

  {
    // Get log file path
    Path loggingPath = loggingRootPath / "dummy.txt";
    std::cout << "File path: " << loggingPath.string() << std::endl;
    bool logFolderExists = fs::exists(loggingPath.string());

    file.open(loggingPath, std::ifstream::in);
    {
      // Start over
      std::cout << "Before seek:" << file.tellg() << std::endl;
      file.seekg(0);
      std::cout << "After seek:" << file.tellg() << std::endl;
      // Get text to search for as regex
      while (true)
      {

        std::string line{};
        if (std::getline(file, line))
        {
          printFileState(file);
          std::cout << ">>>>>>>>>>In loop getline OK:" << file.tellg() << std::endl;
          std::cout << line << std::endl;
          std::cout << ">>>>>>>>>>" << std::endl;
        }
        else
        {
          printFileState(file);
          std::cout << "<<<<<<<<<<In loop getline FAIL:" << file.tellg() << std::endl;
          std::cout << line << std::endl;
          std::cout << "<<<<<<<<<<" << std::endl;
          break;
        }

      }
    }

    std::cout << "Before seek (Already EOF):" << file.tellg() << std::endl;
    file.seekg(std::ios::beg);
    std::cout << "After seek (Already EOF):" << file.tellg() << std::endl;

    printFileState(file);

    if (file.eof()) {
      std::cout << "eof() returns true." << std::endl;
      file.clear();
    }

    if (file.fail()) {
      std::cout << "fail() returns true." << std::endl;
      file.clear();
    }

    std::cout << "After seek (Try to clear):" << file.tellg() << std::endl;
    file.close();

  }
}
