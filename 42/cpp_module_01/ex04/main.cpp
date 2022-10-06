#include <iostream>
#include <string>
#include <fstream>

std::string    replace_line(std::string line, std::string needle, std::string added)
{
    int i;
    int pos;

    i = 0;
    pos = line.find(needle);
    while (pos != -1)
    {
        line.erase(pos, needle.length());
        line.insert(pos, added);
        pos = line.find(needle);
    }
    return line;
}

int main(int argc, char **argv)
{
    std::string line;
    std::string fileName;
    std::string str1;
    std::string str2;

    str1.assign(argv[2]);
    str2.assign(argv[3]);
    fileName.assign(argv[1]);
    if (argc > 1)
    {
        std::ifstream originalFile;
        std::ofstream replaceFile;

        originalFile.open(fileName);
        replaceFile.open(fileName.append(".replace"));
        if (originalFile.is_open())
        {
            while (getline(originalFile, line))
            {
                line = replace_line(line, str1, str2);
                replaceFile << line << std::endl;
            }
            originalFile.close();
        }
        else
            std::cout << "Error could not open the file." << std::endl;
    }
    return (0);
}