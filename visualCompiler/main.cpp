int main(int argc, char* argv[])
{
    std::cout << "hello";
    std::cout << std::setw(10) << "world" << std::endl;
    if (argc < 2) {
        std::cout << "Enter your text file. example ./a.out text.txt" << std::endl;
        return 1;
    }
    Types obj(argv[1]);
    obj.run();
    return 0;
}
