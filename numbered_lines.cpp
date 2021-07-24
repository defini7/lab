#include <string>
#include <vector>

std::vector<std::string> number(const std::vector<std::string> &lines)
{
    std::vector<std::string> lines1 = lines;
    for (int i = 0; i < lines1.size(); i++)
      lines1[i] = std::to_string(i + 1) + ": " + lines1[i];
    return lines1;
}
