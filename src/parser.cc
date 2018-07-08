#include "parser.hh"

// Function that transform a string date to int
int dateToInt(std::string s)
{
  int secondes = 0;
  size_t pos, i = 0;
  std::string token;

  while ((pos = s.find(":")) != std::string::npos)
  {
    token = s.substr(0, pos);
    secondes += std::stoi(token) * 3600; // Houres to secondes
    s.erase(0, pos + 1);
    i++;
  }

  secondes += std::stoi(s) * 60; // Minutes to secondes
  return secondes;
}

// Function that parse a file and fills the struct day
int parser(day &day, std::string path)
{
  std::ifstream infile(path);
  std::string s1, s2, s3, s4, s5, s6, s7, s8;

  // Bypass first header line
  if (!(infile >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7))
  {
    std::cerr << "Error: could not read first line, abort. \n";
    return 1;
  }
  else
  {   // successfully extracted one line, data is in s1, ..., s8.
    while (infile >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8)
    {
      // Creation of a dot
      data point = data();
      point.value = strtof((s3).c_str(), 0);
      point.date = dateToInt(s2);
      // Add this dot to the day
      day.data_vect.push_back(point);        
    }

    // Add the date and the name to the day
    day.date = s1;
    day.name = path;

    return 0;        
  }
}

// Function that parse all file of a folder and fills the vector of day
void parse_days(std::vector<day> days)
{
  // Browse data files throught ressources folder
  std::string path = "./ressources/";
  std::cout << "\n-> Begining parsing: " << path << " folder will be parsed.\n" << std::endl;
  
  // Creating DIR structure
  DIR *dir;
	struct dirent *ent;

  // Check if folder exist
	if ((dir = opendir ("./ressources/")) != NULL)
	{
		// Print files within directory
		while ((ent = readdir (dir)) != NULL)
		{
      // Getting current path file string
			std::string file_path_str = ent->d_name;

      // If file is allows ".txt" extension
      if (file_path_str.length() > 4)
      {
        std::cout << "\tParsing of file " << file_path_str << std::endl;

        // Creating a new day
        day current_day;
        days.push_back(current_day);

        // Filling the new day
        parser(current_day, path + file_path_str);
      }
		}
		closedir (dir);
	}

  // Exit error if folder cannot be opened
	else
	{
		perror ("");
		exit(1);
	}

  std::cout << "\n-> Finished parsing: " << days.size() << " files has been parsed.\n" << std::endl;
}
