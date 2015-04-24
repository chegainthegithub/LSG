#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H
class GameStatistics
{
public:
    struct statistics
    {
        int eaten ;
        int movesmade ;
		int enemieskilled ;
    };
    statistics element;
	GameStatistics()
	{
		element.eaten = 0;
		element.movesmade = 0;
		element.enemieskilled = 0;
	}
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
