#ifndef VISUALCOMPILER
#define VISUALCOMPILER

struct InformationTypes {
    InformationTypes();
    void set(const std::string&, const std::string&, const std::string&, const size_t&, const size_t&);
    std::string typeName;
    std::string value;
    std::string name;
    size_t row;
    size_t column;
};

class Types {
public:
    explicit Types(const std::string&);
    ~Types();
    void run();
private:
    void executeLine(std::vector<std::string>& line);
    void cutString(std::string line, size_t& row);
    std::map<std::string, InformationTypes> data;
    void executeLine(std::vector<std::string>&, size_t&, size_t&);
    std::string helperExecuteLine(std::vector<std::string>&, size_t);
    void putInResultFile(const std::string&);
    void printResultTxt();
    std::ifstream inputFile;
    std::ofstream outputFile;
};

#endif //VISUALCOMPILER
