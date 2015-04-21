#ifndef GAMESTATISTICS
#define GAMESTATISTICS
class GameStatistics
{
public:
    struct statistics
    {
        int eaten = 0;
        int movesmade = 0;
    };
    statistics element;
    void UpdateStats(int local)
    {
        if (local)
            element.eaten++;
        element.movesmade++;
    }
    void show()
    {
        std::cout << "eaten == " << element.eaten<<std::endl;
        std::cout << "moves made == " << element.movesmade <<std::endl;
    }
};
#endif // GAMESTATISTICS

