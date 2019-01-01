#include <iostream>
#include <fstream>
#include <string>

using std::string;



int main(int argc, char* argv[])
{
  if (argc == 0)
  {
    std::cerr << "\nImpossible error occured.\n\n";
    return -1;
  }

  if (argc == 1)
  {
    std::cout << "\nUsage: " << argv[0] << " <Comment (in quotes)>\n\n";
    return 0;
  }

  if (argc > 2)
  {
    std::cerr << "\nToo many arguments. Usage: " << argv[0] << " <Comment (in quotes)>\n\n";
    return 0;
  }


  string iComment = argv[1];
  string oComment = "";
  for (int i = 1; i < iComment.length(); i++)
  {
    oComment += iComment.substr(0, i) + "\n";
  }
  for (int i = iComment.length(); i > 0; i--)
  {
    oComment += iComment.substr(0, i) + "\n";
  }
  oComment.pop_back();


  std::ofstream Output("GeneratedComment.txt");
  if (!Output.is_open())
  {
    std::cerr << "\nCouldn't open output file. Make sure nothing is trying to access \"GeneratedComment.txt\".\n\n";
    return -1;
  }
  Output.write(oComment.c_str(), oComment.length());
  Output.close();

  std::cout << "\nGenerated comment lives at GeneratedComment.txt\n\n";
  #ifdef _WIN32
  system("Notepad GeneratedComment.txt");
  #endif
  #ifdef __linux__
  system("gedit GeneratedComment.txt");
  #endif

  return 1;
}
