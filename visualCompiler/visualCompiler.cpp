InformationTypes::InformationTypes()
{
    typeName = "";
    value = "";
    name = "";
    row = 0;
    column = 0;
}

void InformationTypes::set(const std::string& typeName, const std::string& value, const std::string& name, const size_t& row, const size_t& column)
{
    this -> typeName = typeName;
    this -> value = value;
    this -> name = name;
    this -> row = row;
    this -> column = column;
}

Types::Types(const std::string& fileName)
        : inputFile(fileName), outputFile("result.txt")
{
    if (outputFile.is_open()) {
        outputFile << std::left 
                   << std::setw(25) << "Type"
                   << std::setw(25) << "Value"
                   << std::setw(25) << "Name"
                   << std::setw(25) << "Row"
                   << std::setw(25) << "Column" 
                   << '\n' << '\n';
    }
}

Types::~Types()
{
    if (inputFile.is_open()) {
        inputFile.close();
    }
    if (outputFile.is_open()) {
        outputFile.close();
        printResultTxt();
    }
}

void Types::printResultTxt()
{
    std::ifstream file("result.txt");
    if (!file.is_open()) {
        std::cout << "Error Unable to open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void Types::run()
{
    if (!inputFile.is_open()) {
        std::cout << "No such file exists" << std::endl;
        return;
    }
    std::string oneLine = "";
    size_t row = 0;
    while (!inputFile.eof()) {
        std::getline(inputFile, oneLine);
        cutString(oneLine, row);
        ++row;
    }
}

std::vector<std::string> cutSemicolon(std::string& line)
{
    std::vector<std::string> cutLine;
    int index = 0;
    while (index != std::string::npos) {
        index = line.find(';');
        if (index != std::string::npos) {
            cutLine.push_back(line.substr(0, index));
        }
        line.erase(0, index + 1);
    }
    return cutLine;
}

void Types::putInResultFile(const std::string& oneStatement)
{
    if (!outputFile.is_open()) {
        std::cout << "the file could not be opened 'outputFile'" << std::endl;
        exit(0);
    }
    const int columnWidth = 25;
    auto it = data.find(oneStatement);
    if (it != data.end()) {
        InformationTypes& obj = it -> second;
        outputFile << std::left
                   << std::setw(columnWidth) << obj.typeName
                   << std::setw(columnWidth) << obj.value
                   << std::setw(columnWidth) << obj.name
                   << std::setw(columnWidth) << obj.row
                   << std::setw(columnWidth) << obj.column 
                   << std::endl;
    } else {
        outputFile << std::left
                   << std::setw(columnWidth) << "-"
                   << std::setw(columnWidth) << "-"
                   << std::setw(columnWidth) << oneStatement
                   << std::setw(columnWidth) << "-"
                   << std::setw(columnWidth) << "-" 
                   << std::endl;
    }
}

void Types::cutString(std::string line, size_t& row)
{
    std::vector<std::string> tmpCutLineSemicolon = cutSemicolon(line);
    std::string tmpPerString = "";
    size_t i = 0;
    while (i < tmpCutLineSemicolon.size()) {
        std::stringstream cutLine(tmpCutLineSemicolon[i]);
        std::vector<std::string> tmpCutLine;
        while (cutLine >> tmpPerString) {
            tmpCutLine.push_back(tmpPerString);
        }

        if (tmpCutLine.size() == 1) {
            putInResultFile(tmpCutLine[0]);
        } else {
            executeLine(tmpCutLine, row, i);
        }
        ++i;
    }
    return;
}

std::string Types::helperExecuteLine(std::vector<std::string>& line, size_t index)
{
    std::string name = "";
    int i = 0;
    while (i < line.size() - index) {
        name += line[i][0];
        ++i;
    }
    return name;
}

void Types::executeLine(std::vector<std::string>& line, size_t& row, size_t& column)
{
    if (line.size() > 3 && line[line.size() - 2] == "=") {
        data[line[line.size() - 3]].set(helperExecuteLine(line, 3), line[line.size() - 1], line[line.size() - 3], row, column);
    } else {
        data[line[line.size() - 1]].set(helperExecuteLine(line, 1), "GARBAGE", line[line.size() - 1], row, column);
    }
    return;
}
